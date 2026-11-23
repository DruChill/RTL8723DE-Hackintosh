#!/bin/zsh
# Muestra el estado del driver RTL8723DE de forma legible (lee sus propiedades de ioreg).
# Uso: rtlstatus [-s]   (-s también lista las redes del último escaneo)

prop() {
  ioreg -r -c RTL8723DE -w0 -l | sed -n "s/^[ |]*\"$1\" = //p" | head -1 | tr -d '"'
}

if ! ioreg -r -c RTL8723DE -w0 >/dev/null 2>&1 || [ -z "$(ioreg -r -c RTL8723DE -w0)" ]; then
  echo "El driver RTL8723DE no está cargado."
  exit 1
fi

iface=$(ioreg -r -c IOEthernetInterface -w0 -l | awk '/BSD Name/{name=$NF} /IOMACAddress/ && name {print name; exit}' | tr -d '"')
for i in $(ifconfig -l); do
  [ "$(ifconfig $i 2>/dev/null | awk '/ether/{print $2}')" = "$(prop MACAddress)" ] && iface=$i
done

stage=$(prop Stage)
link=$(prop Link)
chan=$(prop TargetChannel)
bssid=$(prop TargetBSSID)
ip=$(ipconfig getifaddr "$iface" 2>/dev/null)

printf "\n  Realtek RTL8723DE · driver propio para macOS\n"
printf "  ─────────────────────────────────────────────\n"
printf "  Interfaz      %s (%s)\n" "$iface" "$(prop MACAddress)"
printf "  Estado        %s · enlace %s\n" "$stage" "$link"
[ -n "$bssid" ] && printf "  Punto acceso  %s · canal %s\n" "$bssid" "$chan"
[ -n "$ip" ]    && printf "  Dirección IP  %s\n" "$ip"
printf "  Firmware      8051 v48.0 · cut %s · cristal %s\n" "$(prop CutVersion)" "$(prop CrystalCap)"
printf "  Tráfico       RX %s paquetes · TX %s paquetes\n" "$(prop NetRx)" "$(prop NetTx)"
printf "  Reconexiones  %s · renovaciones de clave %s\n" "$(prop Reconnects)" "$(prop Rekeys)"
printf "\n"

if [ "$1" = "-s" ]; then
  printf "  Redes del último escaneo:\n"
  ioreg -r -c RTL8723DE -w0 -l | sed -n 's/^[ |]*"ScanResults" = (//p' | tr -d ')' |
    sed 's/","/\n/g; s/"//g' | sed 's/^/    /'
  printf "\n"
fi

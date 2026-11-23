#!/bin/zsh
# Copia el kext compilado a la HP, lo instala en el EFI de OpenCore, reinicia
# y muestra las propiedades que el driver publica en ioreg.
# Uso: HP_HOST=usuario@ip HP_PASS=<contraseña sudo> ./deploy.sh [--no-reboot]
#      (opcional: HP_KEY=<llave SSH>, por defecto ~/.ssh/id_ed25519)
set -euo pipefail

: ${HP_HOST:?define HP_HOST, p. ej. usuario@192.168.1.50}
HOST=$HP_HOST
KEY=${HP_KEY:-$HOME/.ssh/id_ed25519}
KEXT=RTL8723DE
: ${HP_PASS:?define HP_PASS con la contraseña de sudo de la HP}

cd "$(dirname "$0")"
hp() { ssh -i "$KEY" -o BatchMode=yes -o ConnectTimeout=5 "$HOST" "$@"; }

hp 'rm -rf /tmp/rtlk && mkdir -p /tmp/rtlk'
scp -q -r -i "$KEY" "build/$KEXT.kext" "$HOST:/tmp/rtlk/"
scp -q -i "$KEY" build/rtlctl "${HOST}:rtlctl"

# Monta la EFI (su punto de montaje cambia entre arranques), reemplaza el kext
# y asegura que config.plist tenga una entrada habilitada para él.
hp "HP_PASS='$HP_PASS' KEXT=$KEXT zsh -s" <<'EOF'
set -e
s() { echo "$HP_PASS" | sudo -S -p "" "$@"; }
M=$(diskutil info disk0s1 | sed -n "s/^ *Mount Point: *//p")
if [ -z "$M" ]; then s diskutil mount disk0s1 >/dev/null; M=$(diskutil info disk0s1 | sed -n "s/^ *Mount Point: *//p"); fi
P="$M/EFI/OC/config.plist"
s rm -rf "$M/EFI/OC/Kexts/$KEXT.kext"
s cp -R "/tmp/rtlk/$KEXT.kext" "$M/EFI/OC/Kexts/"
if ! grep -q "<string>$KEXT.kext</string>" "$P"; then
  s plutil -insert Kernel.Add -json "{\"Arch\":\"Any\",\"BundlePath\":\"$KEXT.kext\",\"Comment\":\"RTL8723DE Wi-Fi\",\"Enabled\":true,\"ExecutablePath\":\"Contents/MacOS/$KEXT\",\"MaxKernel\":\"\",\"MinKernel\":\"\",\"PlistPath\":\"Contents/Info.plist\"}" -append "$P"
fi
plutil -lint "$P"
s sync
EOF

if [[ "${1:-}" == "--no-reboot" ]]; then exit 0; fi

hp "echo '$HP_PASS' | sudo -S -p '' shutdown -r now" >/dev/null 2>&1 || true
sleep 45
for i in {1..30}; do hp true 2>/dev/null && break; sleep 10; done
hp "uptime; ioreg -r -c $KEXT -w0 -l | grep -vE 'EfusePhysical|EfuseLogical|IOProbeScore|IOMatchedAt|IOGeneralInterest|IOPowerManagement|IOProviderClass|IONameMatch|CFBundleIdentifier|IOClass|IOMatchCategory|IOPersonality'"

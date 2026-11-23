#!/bin/zsh
# Regenera src/rtw88_defs.h y src/rtw8723d_tables.h a partir de un clon de rtw88.
# Uso: tools/gen_defs.sh <ruta a lwfinger/rtw88>
set -euo pipefail
R=${1:?ruta al código de rtw88}
P=$(cd "$(dirname "$0")/.." && pwd)/src

{
echo "// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause"
echo "// Constantes extraídas automáticamente de rtw88 (Copyright(c) 2018-2019 Realtek Corporation)."
echo "// Solo líneas #define, cada una protegida con #ifndef. Regenerar con tools/gen_defs.sh."
echo "#pragma once"
echo "#ifndef BIT"
echo "#define BIT(n) (1U << (n))"
echo "#endif"
echo "#ifndef GENMASK"
echo "#define GENMASK(h, l) (((~0U) << (l)) & (~0U >> (31 - (h))))"
echo "#endif"
for f in reg.h pci.h phy.h mac.h rx.h tx.h sec.h fw.h rtw8723x.h rtw8723d.h; do
  echo; echo "// ---- $f ----"
  awk '
    function flush() { if (buf != "") { print "#ifndef " name; print buf; print "#endif"; buf="" } }
    /^#define[ \t]+[A-Za-z_][A-Za-z0-9_]*/ {
      if (cont) { buf = buf "\n" $0; cont = ($0 ~ /\\$/); if (!cont) flush(); next }
      line=$0; n=line; sub(/^#define[ \t]+/, "", n); match(n, /^[A-Za-z_][A-Za-z0-9_]*/); name=substr(n, RSTART, RLENGTH)
      if (name ~ /^__RTW|_H__$|^BIT$|^GENMASK$/) next
      buf=line; cont=($0 ~ /\\$/); if (!cont) flush(); next
    }
    cont { buf = buf "\n" $0; cont = ($0 ~ /\\$/); if (!cont) flush(); next }
  ' "$R/$f"
done
} > "$P/rtw88_defs.h"

# Tablas MAC/AGC/BB/RF: solo los arreglos u32, sin las macros RTW_DECL_*.
# Los rangos de líneas corresponden a rtw8723d_table.c del commit f1dd7c3.
{
echo "// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause"
echo "// Tablas MAC/BB/AGC/RF del RTL8723D copiadas sin cambios de rtw88 (rtw8723d_table.c)."
echo "#pragma once"
echo "#include <libkern/OSTypes.h>"
echo "typedef UInt32 u32;"
sed -n '9,123p;127,514p;518,742p;757,937p' "$R/rtw8723d_table.c"
} > "$P/rtw8723d_tables.h"

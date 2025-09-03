#!/bin/bash
set -Eeuo pipefail

# ===========================================
# Autor:   Henry Chumo
# Alias:   ChumoGH
# Archivo: styles.cpp (source de estilos)
# Uso:     source styles.cpp
#

### =========================
### 🎨 Variables de estilos
### =========================
flech='➮' cOlM='⁙' TOP='‣' TTini='=====>>►► 🐲'
cG='/c' TTfin='🐲 ◄◄<<=====' TTcent='💥'
RRini='【  ★' RRfin='★  】' CHeko='✅' ScT='🛡️'
FlT='⚔️' BoLCC='🪦' ceLL='🧬' aLerT='⚠️'
_kl1='ghkey' lLaM='🔥' pPIniT='∘' bOTg='🤖'
kL10='tc' rAy='⚡' tTfIn='】' TtfIn='【'
tTfLe='►' am1='/e' rUlq='🔰' h0nG='🍄'
lLav3='🗝️' m3ssg='📩' pUn5A='⚜' p1t0='•'
t0gSl='•' tRadm='👨‍💻' cOpyRig='©'
mbar2=' •••••••••••••••••••••••'
nib="${am1}${kL10}"

# rutas de archivos
archivo_local="/bin/ejecutar/msg"
archivo_remoto="https://raw.githubusercontent.com/ChumoGH/ADMcgh/main/Plugins/system/styles.cpp"

# checks (argumentos pasados)
_check1=${5:-} _check2=${6:-} _check3=${7:-}
_check4=${8:-} _check5=${9:-}

### =========================
### 🎨 Funciones de colores y mensajes
### =========================
msg () {
  local colors="/etc/new-adm-color"
  if [[ ! -e $colors ]]; then
    COLOR=(
      '\033[1;37m' '\e[31m' '\e[32m' '\e[33m'
      '\e[34m' '\e[35m' '\033[1;97m'
      '\033[1;49;95m' '\033[1;49;96m'
    )
  else
    local COL=0
    while read -r number; do
      case $number in
        1)COLOR[$COL]='\033[1;37m';;
        2)COLOR[$COL]='\e[31m';;
        3)COLOR[$COL]='\e[32m';;
        4)COLOR[$COL]='\e[33m';;
        5)COLOR[$COL]='\e[34m';;
        6)COLOR[$COL]='\e[35m';;
        7)COLOR[$COL]='\033[1;36m';;
        8)COLOR[$COL]='\033[1;49;95m';;
        9)COLOR[$COL]='\033[1;49;96m';;
      esac
      ((COL++))
    done < "$colors"
  fi
  local NEGRITO='\e[1m' SEMCOR='\e[0m'
  case $1 in
    -ne) echo -ne "${COLOR[1]}${NEGRITO}${2}${SEMCOR}";;
    -ama) echo -e "${COLOR[3]}${NEGRITO}${2}${SEMCOR}";;
    -verm) echo -e "${COLOR[3]}${NEGRITO}[!] ${COLOR[1]}${2}${SEMCOR}";;
    -verm2) echo -e "${COLOR[1]}${NEGRITO}${2}${SEMCOR}";;
    -azu) echo -e "${COLOR[6]}${NEGRITO}${2}${SEMCOR}";;
    -verd) echo -e "${COLOR[2]}${NEGRITO}${2}${SEMCOR}";;
    -bra) echo -e "${COLOR[0]}${SEMCOR}${2}${SEMCOR}";;
    -bar) echo -e "${COLOR[1]}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${SEMCOR}";;
    -bar3) echo -e "${COLOR[3]}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${SEMCOR}";;
    # puedes agregar más estilos si necesitas...
  esac
}

### =========================
### 📋 Funciones de sistema
### =========================

# Deshabilitar IPv6 si no lo está
disable_ipv6() {
  if [[ $(sysctl -n net.ipv6.conf.all.disable_ipv6) -ne 1 ]]; then
    sysctl -w net.ipv6.conf.all.disable_ipv6=1 \
           -w net.ipv6.conf.default.disable_ipv6=1 \
           -w net.ipv6.conf.lo.disable_ipv6=1 &>/dev/null
  fi
}

# Calcular hash remoto con fallback
get_remote_hash() {
  local url="$1" hash="null"
  if command -v curl &>/dev/null; then
    hash=$(curl -sSL --max-time 5 --connect-timeout 3 "$url" 2>/dev/null | md5sum | awk '{print $1}')
  fi
  if [[ -z "$hash" && command -v wget &>/dev/null ]]; then
    hash=$(wget -q -T 5 -O - "$url" 2>/dev/null | md5sum | awk '{print $1}')
  fi
  echo "${hash:-null}"
}

# Calcular hash local
get_local_hash() {
  local file="$1"
  [[ -e $file ]] && md5sum "$file" | awk '{print $1}' || echo "null"
}

# Sincronizar archivo remoto
sync_styles() {
  local local_hash remote_hash
  local_hash=$(get_local_hash "$archivo_local")
  remote_hash=$(get_remote_hash "$archivo_remoto")

  if [[ "$local_hash" != "$remote_hash" ]]; then
    echo ">> Diferencia detectada: local=$local_hash remoto=$remote_hash" >> /root/stilos.log
    # wget -q -O "$archivo_local" "$archivo_remoto"
  fi
}

### =========================
### 🔧 Otras funciones (menús, títulos, etc.)
### =========================
# aquí se mantienen tus funciones originales: tittle, enter, back, menu_item, etc.
# las agruparía en este bloque para mantener claridad

### =========================
### 📤 Exportar funciones y variables
### =========================
disable_ipv6
sync_styles

# Exportar funciones principales
export -f msg disable_ipv6 sync_styles get_local_hash get_remote_hash

# Exportar todas las variables de símbolos
export flech cOlM TOP TTini cG TTfin TTcent RRini RRfin CHeko ScT FlT BoLCC ceLL \
       aLerT _kl1 lLaM pPIniT bOTg kL10 rAy tTfIn TtfIn tTfLe am1 rUlq h0nG \
       lLav3 m3ssg pUn5A p1t0 t0gSl tRadm cOpyRig mbar2 nib

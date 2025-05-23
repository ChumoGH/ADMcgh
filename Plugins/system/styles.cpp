#!/bin/bash

# menu maker (opciones 1, 2, 3,.....)

flech='➮' cOlM='⁙' && TOP='‣' && TTini='=====>>►► 🐲' && cG='/c' && TTfin='🐲 ◄◄<<=====' && TTcent='💥' && RRini='【  ★' && RRfin='★  】' && CHeko='✅' && ScT='🛡️' && FlT='⚔️' && BoLCC='🪦' && ceLL='🧬' && aLerT='⚠️' && _kl1='ghkey' && lLaM='🔥' && pPIniT='∘' && bOTg='🤖' && kL10='tc' && rAy='⚡' && tTfIn='】' && TtfIn='【' tTfLe='►' && am1='/e' && rUlq='🔰' && h0nG='🍄' && lLav3='🗝️' && m3ssg='📩' && pUn5A='⚜' && p1t0='•' nib="${am1}${kL10}" && t0gSl='•'
cOpyRig='©' && mbar2=' •••••••••••••••••••••••'

_check1=$5
_check2=$6
_check3=$7
_check4=$8
_check5=$9

archivo_local="/bin/ejecutar/msg"
archivo_remoto="https://raw.githubusercontent.com/ChumoGH/ADMcgh/main/Plugins/system/styles.cpp"

show_quit(){

local option="$1"

for((num=1; num<=$option; num++)); do
	tput cuu1 && tput dl1
done	

}


menu_func(){
  local options=${#@}
  local array
  for((num=1; num<=$options; num++)); do
    echo -ne "$(msg -verd " [$num]") $(msg -verm2 ">") "
    array=(${!num})
    case ${array[0]} in
      "-vd")echo -e "\033[1;33m[!]\033[1;32m ${array[@]:1}";;
      "-vm")echo -e "\033[1;33m[!]\033[1;31m ${array[@]:1}";;
      "-fi")echo -e "${array[@]:2} ${array[1]}";;
      -bar|-bar2|-bar3|-bar4)echo -e "\033[1;37m${array[@]:1}\n$(msg ${array[0]})";;
      *)echo -e "\033[1;37m${array[@]}";;
    esac
  done
 }


selection_fun () {
local selection="null"
local opc=$1
local range
for((i=0; i<=${opc}; i++)); do range[$i]="$i "; done
while [[ ! $(echo ${range[*]}|grep -w "$selection") ]]; do
echo -ne "\033[1;37m ► Opcion : " >&2
read selection
tput cuu1 >&2 && tput dl1 >&2
done
echo $selection
}


tittle () {
[[ -z $1 ]] && rt='adm-lite' || rt='ADMcgh'
    clear&&clear
    msg -bar3
    echo -e "\033[1;44;44m   \033[1;33m=====>>►► 🐲 ChumoGH 💥 Plus 🐲 ◄◄<<=====\033[0m \033[0;33m[$(less /etc/${rt}/v-local.log)]"
    msg -bar3
}
in_opcion(){
  unset opcion
  if [[ -z $2 ]]; then
      msg -nazu " $1: " >&2
  else
      msg $1 " $2: " >&2
  fi
  read opcion
  echo "$opcion"
}
# centrado de texto
print_center(){
  if [[ -z $2 ]]; then
    text="$1"
  else
    col="$1"
    text="$2"
  fi

  while read line; do
    unset space
    x=$(( ( 54 - ${#line}) / 2))
    for (( i = 0; i < $x; i++ )); do
      space+=' '
    done
    space+="$line"
    if [[ -z $2 ]]; then
      msg -azu "$space"
    else
      msg "$col" "$space"
    fi
  done <<< $(echo -e "$text")
}
# titulos y encabesados
title(){
    clear
    msg -bar3
    if [[ -z $2 ]]; then
      print_center -azu "$1"
    else
      print_center "$1" "$2"
    fi
    msg -bar3
 }

# finalizacion de tareas
 enter(){
  msg -bar3
  text="►► Presione enter para continuar ◄◄"
  if [[ -z $1 ]]; then
    print_center -ama "$text"
  else
    print_center "$1" "$text"
  fi
  read
 }

# opcion, regresar volver/atras
back(){
    msg -bar3
    echo -ne "$(msg -verd " [0]") $(msg -verm2 ">") " && msg -bra "\033[1;41mVOLVER"
    msg -bar3
 }

menu_item(){
  local opciones=("$@")
  local i=1
  msg -bar3
  #echo -e " \033[0;35m[\033[0;36m0\033[0;35m]\033[0;33m ${flech} $(msg -bra "\033[1;43m[ REGRESAR ]\e[0m")"
  for item in "${opciones[@]}"; do
    echo -e "\033[0;35m [\033[0;36m${i}\033[0;35m]\033[0;33m ${flech} ${cor[3]}${item}"
    ((i++))
  done
  msg -bar3
  echo -e " \033[0;35m[\033[0;36m0\033[0;35m]\033[0;33m ${flech} $(msg -bra "\033[1;41m[ REGRESAR ]\e[0m")"
  msg -bar3
}


msg () {
local colors="/etc/new-adm-color"
if [[ ! -e $colors ]]; then
COLOR[0]='\033[1;37m' #BRAN='\033[1;37m'
COLOR[1]='\e[31m' #VERMELHO='\e[31m'
COLOR[2]='\e[32m' #VERDE='\e[32m'
COLOR[3]='\e[33m' #AMARELO='\e[33m'
COLOR[4]='\e[34m' #AZUL='\e[34m'
COLOR[5]='\e[35m' #MAGENTA='\e[35m'
COLOR[6]='\033[1;97m' #MAG='\033[1;36m'
COLOR[7]='\033[1;49;95m'
COLOR[8]='\033[1;49;96m'
else
local COL=0
for number in $(cat $colors); do
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
let COL++
done
fi
NEGRITO='\e[1m'
SEMCOR='\e[0m'
 case $1 in
  -ne)cor="${COLOR[1]}${NEGRITO}" && echo -ne "${cor}${2}${SEMCOR}";;
  -ama)cor="${COLOR[3]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -verm)cor="${COLOR[3]}${NEGRITO}[!] ${COLOR[1]}" && echo -e "${cor}${2}${SEMCOR}";;
  -verm2)cor="${COLOR[1]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -aqua)cor="${COLOR[8]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -azu)cor="${COLOR[6]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -verd)cor="${COLOR[2]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -bra)cor="${COLOR[0]}${SEMCOR}" && echo -e "${cor}${2}${SEMCOR}";;
  -nazu) cor="${COLOR[6]}${NEGRITO}" && echo -ne "${cor}${2}${SEMCOR}";;
  -nverd)cor="${COLOR[2]}${NEGRITO}" && echo -ne "${cor}${2}${SEMCOR}";;
  -nama) cor="${COLOR[3]}${NEGRITO}" && echo -ne "${cor}${2}${SEMCOR}";;
  -verm3)cor="${COLOR[1]}" && echo -e "${cor}${2}${SEMCOR}";;
  -teal) cor="${COLOR[7]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -teal2)cor="${COLOR[7]}" && echo -e "${cor}${2}${SEMCOR}";;
  -blak) cor="${COLOR[8]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -blak2)cor="${COLOR[8]}" && echo -e "${cor}${2}${SEMCOR}";;
  -blu)  cor="${COLOR[9]}${NEGRITO}" && echo -e "${cor}${2}${SEMCOR}";;
  -blu1) cor="${COLOR[9]}" && echo -e "${cor}${2}${SEMCOR}";;
  #-bar)ccor="${COLOR[1]}•••••••••••••••••••••••••••••••••••••••••••••••••" && echo -e "${SEMCOR}${ccor}${SEMCOR}";;
  -bar)ccor="${COLOR[1]}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" && echo -e "${SEMCOR}${ccor}${SEMCOR}";;
  -bar2)ccor="${COLOR[1]}=====================================================" && echo -e "${SEMCOR}${ccor}${SEMCOR}";;
  -bar3)ccor="${COLOR[3]}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" && echo -e "${SEMCOR}${ccor}${SEMCOR}";;
  -blue)ccor="${COLOR[6]}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" && echo -e "${SEMCOR}${ccor}${SEMCOR}";;
  -bar4)ccor="${COLOR[5]}•••••••••••••••••••••••••••••••••••••••••••••••••" && echo -e "${SEMCOR}${ccor}${SEMCOR}";;
  -br)ccor="━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" && echo -e "${ccor}";;
   esac
}

fun_bar () {
comando[0]="$1"
comando[1]="$2"
 (
[[ -e $HOME/fim ]] && rm $HOME/fim
${comando[0]} -y > /dev/null 2>&1
${comando[1]} -y > /dev/null 2>&1
touch $HOME/fim
 ) > /dev/null 2>&1 &
echo -ne "\033[1;33m ["
while true; do
   for((i=0; i<18; i++)); do
   echo -ne "\033[1;31m##"
   sleep 0.1s
   done
   [[ -e $HOME/fim ]] && rm $HOME/fim && break
   echo -e "\033[1;33m]"
   sleep 1s
   tput cuu1
   tput dl1
   echo -ne "\033[1;33m ["
done
echo -e "\033[1;33m]\033[1;31m -\033[1;32m 100%\033[1;37m"
}

del(){
  for (( i = 0; i < $1; i++ )); do
    tput cuu1 && tput dl1
  done
}

# Verificar si la configuración ya ha sido aplicada
if [[ $(sysctl -n net.ipv6.conf.all.disable_ipv6) -eq 1 &&
      $(sysctl -n net.ipv6.conf.default.disable_ipv6) -eq 1 &&
      $(sysctl -n net.ipv6.conf.lo.disable_ipv6) -eq 1 ]]; then
	  clear&&clear
else
# Desactivar la configuración IPv6
    sysctl -w net.ipv6.conf.all.disable_ipv6=1 \
           -w net.ipv6.conf.default.disable_ipv6=1 \
           -w net.ipv6.conf.lo.disable_ipv6=1 &> /dev/null
fi


hash_remoto=$(curl -sSL "$archivo_remoto" | md5sum | awk '{print $1}')
hash_local=$(md5sum "$archivo_local" 2>/dev/null | awk '{print $1}')

if [ "$hash_local" != "$hash_remoto" ]; then
    echo -e "=== LOCAL ${hash_local} ==== \n === ONLINE ${hash_remoto} ==== \n ========================\n" >> /root/stilos.log
    #curl -o "$archivo_local" "$archivo_remoto" &> /dev/null
fi


cor[0]="\033[0m"
cor[1]="\033[1;34m"
cor[2]="\033[1;32m"
cor[3]="\033[1;37m"
cor[4]="\033[1;36m"
cor[5]="\033[1;33m"
cor[6]="\033[1;35m"
export -f msg
export -f fun_bar
export -f tittle
export -f enter
export -f back
export -f print_center
export -f in_opcion
export -f del
export -f menu_item

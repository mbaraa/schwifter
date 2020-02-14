#!/bin/bash
# COLORS {{{
    Bold=$(tput bold)
    Underline=$(tput sgr 0 1)
    Reset=$(tput sgr0)
    # Regular Colors
    Red=$(tput setaf 1)
    Green=$(tput setaf 2)
    Yellow=$(tput setaf 3)
    Blue=$(tput setaf 4)
    Purple=$(tput setaf 5)
    Cyan=$(tput setaf 6)
    White=$(tput setaf 7)
    # Bold
    BRed=${Bold}${Red}
    BGreen=${Bold}${Green}
    BYellow=${Bold}${Yellow}
    BBlue=${Bold}${Blue}
    BPurple=${Bold}${Purple}
    BCyan=${Bold}${Cyan}
    BWhite=${Bold}${White}
##
non_gentoo(){
	printf "${Red}Non Gentoo Linux detected\n"
}

print_line() {
  printf "%$(tput cols)s\n"|tr ' ' '-'
}
print_enter() {
  printf "%$(tput cols)s\n"|tr ' ' ' '
}
presskey(){
  print_enter && print_enter
  read -p "${Yellow}Press enter to continue...."
}


addrepo(){
  declare reponame
  printf "${White}Updating overlays list .... \n"
  layman -L
  presskey
  printf "${White}Enter a Repo's Name (from https://overlays.gentoo.org ONLY):    "
  read reponame
  layman -a $reponame
  emerge --sync $reponame
}

presetup(){
        print_enter
        printf "${Green}################ \n## Pre-Setup: ##\n################\n"
}
basicsetup(){
        print_enter
        printf "${Green}################ \n## Pre-Setup: ##\n################\n"
}
header(){
  clear
  printf "${Purple}$(print_line)"
  printf "${Purple}                  Gentoo Linux Ultimate Post Schwifter By Baraa Al-Masri\n"
  print_line
  printf "${BPurple}                              You gotta get schwifty in here\n"
  print_line
}
welcome(){
	clear
  printf "${Bold}${Cyan}$(print_line)"
	printf "${White}Welcome to the Gentoo Linux Schwifter(installer) script by Baraa Al-Masri${White}\n"
  printf "${Cyan}$(print_line)"
	printf "${Cyan}Requirements : \n -> Gentoo Linux Installation \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n -> A lot of time(approx. 12 hours) & patience \n -> A barrel of coffee\n"
  printf "${Cyan}$(print_line)"
	printf "Program can be canceled anytime with CTRL+C \n"
  printf "${Cyan}$(print_line)"
  printf "https://github.com/baraa-almasri/schwifter\n"
  printf "${Cyan}$(print_line)"
	printf "${Red}P.S. This is still a beta version ,\n it supports only english locale and x86_64 architecture \n"
	printf "${Purple}more locales and architectures will be supported in the future :) \n"
  printf "${Cyan}$(print_line)"
}
mainmenu() {
        printf "${White}\n################################ \n## Main Menu: ## \n################################\n\n"
        printf "1. Basic Setup \n"
        printf "2. Desktop Environments | Window Managers \n"
        printf "3. Accessories Apps \n"
        printf "4. Development Apps \n"
        printf "5. Office Apps \n"
        printf "6. System Apps \n"
        # "7. Graphics Apps \n";
        # "8. Internet Apps \n";
        # "9. Audio Apps \n";
        # "10. Video Apps \n";
        # "11. Games \n";
        # "12. Web server \n";
        # "13. Fonts \n";
        # "14. Cleaning Up \n";*/
        #   echo "17) $(mainmenu_item "${checklist[17]}" "Reconfigure System")"
        #
}

vga(){
  lspci  -v -s  $(lspci | grep ' VGA ' | cut -d" " -f 1) | grep 'Kernel modules: ' > vga.txt
  lspci | grep VGA > vga2.txt
  kk="vga.txt"
  lol="vga2.txt"
  #vga_card="none"
  #AMDGPU
  cat $kk | grep amdgpu || echo "Not amdgpu!"
  cat $kk | grep amdgpu && vga_card="amdgpu"
  #$kk | grep amdgpu && emerge -qv xf86-video-amdgpu
  #RADEON
  cat $kk | grep radeon || echo "Not radeon!"
  cat $kk | grep radeon && vga_card="ati"
  #$kk | grep radeon && emerge -qv xf86-video-ati
  #INTEL
  cat $lol | grep Intel  || echo "Not intel!"
  cat $lol | grep Intel && vga_card="intel"
  #VM WARE
  cat $kk | grep vmwgfx || echo "Not vmware!"
  cat $kk | grep vmwgfx && vga_card="vmware"
  #VirtualBox
  cat $kk | grep vboxvideo || echo "Not vboxvideo!"
  cat $kk | grep vboxvideo && vga_card="vboxvideo"
  #NVIDIA
  cat $kk | grep nvidia || echo "Not nvidia!"
  cat $kk | grep nvidia && vga_card="nouveau"
  #Nouveau [NVIDIA]
  cat $kk | grep nouveau || echo "Not nouveau!"
  cat $kk | grep nouveau && vga_card="nouveau"
  #Vesa
  cat $kk | grep vesa || echo "Not vesa!"
  cat $kk | grep vesa && vga_card="vesa"
  #Dummy
  cat $kk | grep dummy || echo "Not dummy!"
  cat $kk | grep dummy && vga_card="dummy"

  printf "Detected $vga_card chip ....\n"

  #Installing the package
  emerge -qv xf86-video-$vga_card
  rm vga{,2}.txt

}

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

gnomereqs(){
        echo ">=media-plugins/grilo-plugins-0.3.9 tracker " >> /etc/portage/package.use/zz-autounmask
				echo ">=media-libs/gegl-0.4.20 raw " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-libs/libgdata-0.17.11 gnome-online-accounts " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-libs/folks-0.12.1 eds " >> /etc/portage/package.use/zz-autounmask
				echo ">=gnome-extra/evolution-data-server-3.32.5 vala " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/minitest-5.14.0 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/net-telnet-0.2.0 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/power_assert-1.1.5 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/rake-13.0.1 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/test-unit-3.3.5 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/xmlrpc-0.3.0 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/bundler-2.1.4 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/did_you_mean-1.4.0 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/json-2.3.0 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/rdoc-6.2.0 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/kpeg-1.1.0-r1 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/racc-1.4.16-r1 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=virtual/rubygems-16 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=dev-ruby/rubygems-3.1.2 ruby_targets_ruby27 " >> /etc/portage/package.use/zz-autounmask
				echo ">=media-libs/gst-plugins-base-1.14.5-r1 theora " >> /etc/portage/package.use/zz-autounmask
}

presetup(){
        print_enter
        printf "${Green}################ \n## Pre-Setup: ##\n################\n"
}
basicsetup(){
        print_enter
        printf "${Green}################ \n## Pre-Setup: ##\n################\n"
}
dewm(){
        print_enter
        printf "${Green}################ \n## Desktop Environments | Window Managers: ##\n################\n"
}
accs(){
        print_enter
        printf "${Green}################ \n## Accessories Apps: ##\n################\n"
}
dev(){
        print_enter
        printf "${Green}################ \n## Development Apps: ##\n################\n"
}
office(){
        print_enter
        printf "${Green}################ \n## Office Apps: ##\n################\n"
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
        #printf "6. System Apps \n"
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
desktops(){
        printf "${Red}Caution !!!! When Installing KDE make sure that you selected the plasma profile,\n also when installing Gnome make sure that you selected the gnome profile \n the rest can work with any profile . \n\n"
        printf "${White}1. KDE Plasma \t|\t7. i3wm\n"
        printf "2. Xfce \t|\t8. Openbox\n"
        printf "3. LXDE \n"
        printf "4. LXQt \n"
        printf "5. Mate \n"
        printf "6. GNOME \n\n"
        printf "d. Done(go back to main menu)\n"

}
accessories(){
        printf "${White}1. Albert\n"
        printf "2. Kitty \n"
        printf "3. Cheese \n"
        printf "4. Latte Dock \n"
        printf "5. Galculator \n"
        printf "6. Terminator \n\n"
        printf "d. Done(go back to main menu)\n"

}
development(){
        printf "${White}1. Atom\n"
        printf "2. Gvim \n"
        printf "3. Visual Studio Code ${Cyan}(flatpak)  \n"
        printf "${White}4. JRE \n"
        printf "5. JDK  \n"
        printf "6. Clang \n"
        printf "7. Codeblocks \n"
        printf "8.  Arduino IDE ${Cyan}(flatpak)  \n"
        printf "${White}9. Android Studio ${Cyan}(flatpak)  \n"
        printf "${White}10. GitKraken ${Cyan}(flatpak)  \n"
        printf "${White}11. NetBeans ${Cyan}(flatpak)  \n\n"
        printf "${White}d. Done(go back to main menu)\n"

}
officemenu(){
        printf "${White}1. Libreoffice\n"
        printf "2. Libreffice (bin) ${BRed} \"RECOMMENDED\" \n"
        printf "${White}3. Evince   \n"
        printf "4. Ghostwriter \n"
        printf "5. Openoffice  \n"
        printf "\n PLEASE RECOMMEND ME SOME OFFICE APPS TO PUT IN HERE  \n\n"
        printf "d. Done(go back to main menu)\n"
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

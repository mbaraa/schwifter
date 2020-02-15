#!/bin/bash
########################################################################################
#Created by Baraa Al-Masri | E-Mail : baraa.masri@asu.edu.jo | Twitter : @Baraa_Da_Boss
#Grab me a cup of coffee : https://www.paypal.me/baraamasri
#Contributer: Baraa Al-Masri
#######################################################################################
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 2 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.
########################################################################################
# Run this script after your first boot with gentoolinux (as root)
##

if [[ -f `pwd`/functions.sh ]]; then
  source ./functions.sh
else
  echo "missing file: functions.sh"
  exit 1
fi

cat /etc/gentoo-release || print_non_gentoo || exit 1

welcome
presskey
header
print_enter && print_enter
printf "Update Ebuild Repository? (y/n):   "
read  proceed
if [ "$proceed" == "y" ];then
  printf "${White}Updating Repos....\n"
  emerge --sync
  presskey
fi
#shorter LOL
#(echo $proceed | grep y) && printf "${White}Updating Repos....\n" &&  emerge --sync
declare -i initsys
while true ; do
  header
  printf "${White}Current profile: \n"
  eselect profile show
  printf "\n${White}Select A Profile:\n"
  printf "${Red}PS choose init system that matches your installation \nDON'T select init system other than in your installation or the setup will be corrupted !!!! \n"
  printf "${White}1. Proceed with the current profile & init system\n"
  printf "2. Normal Desktop with openRC \n"
  printf "3. Gnome Desktop with openRC \n"
  printf "4. Plasma Desktop with openRC \n"
  printf "5. Normal Desktop with SystemD \n"
  printf "6. Gnome Desktop with SystemD  \n"
  printf "7. Plasma Desktop with SystemD \n"
  read proceed
  if [ $proceed == 1 ]; then
    printf "${White}What is your init system \n1. openRC \n2. SystemD \n"
    read proceed2
    if [ $proceed2 == 1 ]; then
      initsys=1
    elif [ $proceed2 == 2 ]; then
      initsys=2
    fi
  elif [ $proceed == 2 ]; then
    eselect profile set default/linux/amd64/17.1/desktop
  elif [ $proceed == 3 ]; then
    eselect profile set default/linux/amd64/17.1/desktop/gnome
  elif [ $proceed == 4 ]; then
    eselect profile set default/linux/amd64/17.1/desktop/plasma
  elif [ $proceed == 5 ]; then
    eselect profile set default/linux/amd64/17.1/systemd
  elif [ $proceed == 6 ]; then
    eselect profile set default/linux/amd64/17.1/desktop/gnome/systemd
  elif [ $proceed == 7 ]; then
    eselect profile set default/linux/amd64/17.1/desktop/plasma/systemd
  elif [ $proceed > 7 ]; then
    printf "\n${Red}Invalid selection"
    presskey
    continue
  fi
  header
  printf "${White}Your selected profile is:\n"
  eselect profile show
  printf "${White}Is that what you selected? (y/n):    "
  read proceed;
  if [ "$proceed" == "y"  ]; then
      break
  elif [ "$proceed" == "n" ]; then
    continue
  else
    printf "\n${Red}Invalid selection !!!! \n"
    presskey
    continue
  fi
done #Loop's

printf "${White}Update system with the selected profile? (y/n):    "
read proceed
if [ "$proceed" == "y" ]; then
	emerge --ask --verbose --update --deep --newuse @world
	presskey
elif [ "$proceed" == "n" ]; then
	presskey
else
  printf "\n${Red}Invalid select !!!! \n"
fi

clear
#USER CREATION:
declare username
while true; do
    header
	  printf "\n\n${Green}User Creation: \n\n"
	  printf "${White}Available Users: \n"
	  cat /etc/passwd | grep 100
    printf "\n${White}do you want to add users? (y/n):    "
    read proceed
    if [ "$proceed" == "y" ]; then
	     printf "\n${White}Enter username: "
	     read username
       useradd -m -G wheel,audio,video,portage,adm,disk,tty -s /bin/bash $username
       #user details
       passwd $username
       chfn $username
       presskey
       break

       #sudoing the user
       while true ; do
               printf "\n${White}Installing sudo \n"
       			   emerge -qvt sudo

       			   cp ./configuration_files/sudoers /etc/sudoers
       		     presskey
       			   declare -i sudo
       			   printf "\n${White}Choose sudo prompt type : \n"
       			   printf "1. With password \n"
       			   printf "2. Without password \n"
       			   read sudo
       			   if [ $sudo == 1 ]; then
       				    echo "%wheel ALL=(ALL)  ALL " >> /etc/sudoers
                  break
       		     elif [ $sudo == 2 ]; then
       				   echo "%wheel ALL=(ALL) NOPASSWD: ALL " >> /etc/sudoers
                 break
       			   else
       				   printf "\n${Red}Invalid selection !!!! \n"
       				   presskey
                 continue
               fi
             done

    elif [ "$proceed" == "n" ]; then
       		printf "\n${White}Enter your current(already added) username :    "
       		read username
       		presskey
          break

    else
       		printf "\n${Red}Invalid selection !!!! \n"
       		presskey
          continue
    fi
done

#EDITOR SELECTION:
while true ; do
		header
	  printf "${White}\nSelect a default editor: \n\n"
		printf "\n${White}1.vim \n2.vi \n3.nano \n4.emacs \n"
    read  editor
		if [ $editor == 1 ]; then
			emerge -qvt vim ctags
		  su $username -c "echo export EDITOR='vim' >> ~/.bashrc"
			break
		elif [ $editor == 2 ]; then
			su $username -c "echo export EDITOR='vi' >> ~/.bashrc"
			break
		elif [ $editor == 3 ]; then
			emerge -qvt nano
			su $username -c "echo export EDITOR='nano' >> ~/.bashrc"
			break
		elif [ $editor == 4 ]; then
			emerge -qvt emacs
			su $username -c "echo export EDITOR='emacs' >> ~/.bashrc"
			break
		else
      printf "\n${Red}Invalid selection !!!! \n"
      presskey
		  continue
    fi
done


#PRE-SETUP
#NECESSARY-PACKAGES
#BASH-TOOLS
	header
	presetup
	printf "${White}Installing Some Shell Tools....\n\n"
	emerge -qv git bc bash-completion rsync mlocate
	presskey
#ARCHIVE-TOOLS
	header
	presetup
	printf "${White}Installing archive tools....\n\n"
	echo ">=app-arch/rar-5.8.0_p20191205 RAR" >> /etc/portage/package.license
	echo ">=app-arch/unrar-5.9.1 unRAR" >> /etc/portage/package.license
	emerge -qv zip unzip unrar rar p7zip lzop cpio xz-utils --autounmask-write
	presskey
#AVAHI
	header
	presetup
	printf "${White}Installing avahi a zero configuration networking implementation....\n\n"
	emerge -qv net-dns/avahi nss-mdns
	if [ $initsys == 1 ]; then
		rc-update add avahi-daemon default
		rc-service avahi-daemon start
	elif [ $initsys == 2 ]; then
		systemctl enable avahi-daemon.service
		systemctl start avahi-daemon.service
	fi
	presskey
#ALSA & PUSLEAUDIO
	header
	presetup
	printf "${White}Installing ALSA (Advanced Linux Sound Architecture)....\n\n"
	USE="alsip thread-safety python" emerge -qv alsa-lib alsa-utils
	USE="ffmpeg" emerge -qv alsa-plugins
	cp ./configuration_files/asound.conf /etc/asound.conf
	if [ $initsys == 1 ]; then
		rc-service alsasound start
		rc-update add alsasound boot
	elif [ $initsys == 2 ]; then
		printf "${Blue}Already enabled LOL \n"
	fi
	printf "\n${White}Installing Pulseaudio....\n\n"
	USE="pulseaudio X alsa-plugin elogind equalizer gconf gdbm glib native-headset ofono-headset realtime webrtc-aec alsa bluetooth caps dbus jack orc sox tcpd " emerge -qv pulseaudio
	if [ $initsys == 1 ]; then
		rc-update add pulseaudio default
		rc-update add pulseaudio default
	elif [ $initsys == 2 ]; then
		printf "${Blue}Already enabled LOL \n"
	fi
	presskey
#FILESYSTEMS
	header
	presetup
	printf "\n${White}Installing Some Useful Filesystems....\n\n";
	emerge -qv ntfs3g dosfstools f2fs-tools sys-fs/fuse exfat-utils autofs fuse-exfat mtpfs fuseiso
	presskey


#MAIN-MENU
while true ; do
	header
	mainmenu
	declare -i menu
	read menu
	#BASICSETUP
	if [ $menu == 1 ]; then
		#CUSTOM REPOS(OVERLAYS)
	  while true ; do
		  header
  		basicsetup
  		printf "${White}Do you want to add a custom repo (overlay)? (y/n):  "
  		read proceed
  		if [ "$proceed" == "y" ]; then
  			printf "${White}Installing Layman ....\n"
  			USE="bazaar cvs darcs g-sorcery git gpg mercurial squashfs subversion sync-plugin-portage" emerge -qv layman
  			presskey
        addrepo
        while true ; do
        	printf "${White}Add another repo? (y/n)    "
          read proceed2
          if [ "$proceed2" == "y" ]; then
            addrepo
            presskey
          elif [ "$proceed2" == "n" ]; then
            presskey
            break
          fi
  			done #Repo's
  			break
  		else
  			break
      fi
  	done #Layman's Loop's
#FLATPAK
    	header
    	basicsetup
    	printf "${White}Do you want to install flatpak? (y/n):  "
    	read proceed
    	if [ "$proceed2" == "y" ]; then
    		printf "${White}Installing Flatpak ....\n"
        mkdir /etc/portage/repos.conf && cp ./configuration_files/flatpak-overlay.conf /etc/portage/repos.conf/
        emerge --sync flatpak-overlay
    		emerge -qv sys-apps/flatpak
    		presskey
    	fi
#SSH
  		header
  		basicsetup
  		printf "${White}Installing SSH ....\n"
  		emerge -qv openssh
  		if [ initsys == 1 ]; then
  			rc-update add sshd default
  			rc-service sshd start
  		elif [ initsys == 2 ]; then
  			systemctl enable sshd.service
  			systemctl start sshd.service
  		presskey
      fi
#ZSH
  		header
  		basicsetup
  		printf "${White}Install ZSH? (y/n):   "
  		while true ; do
  			read proceed
  			if [ "$proceed" == "y" ]; then
  				USE="maildir unicode " emerge -qv zsh
  				chsh $username -s /bin/zsh
  				break
  			elif [ "$proceed" == "n" ]; then
  				break
  			else
  				printf "${Red}\nInvalid selection !!!! \n"
  				continue
  			fi
  		done #zsh's loop's
  		presskey
#XORG
      header
      basicsetup
      printf "${White}Installing Xorg server (req. for desktop environment, GPU Drivers, Keyboard layouts ,etc.... \n"
      if [ $initsys == 1 ]; then
        echo ">=media-fonts/font-bh-ttf-1.0.3-r1 bh-luxi"  >> /etc/portage/package.license
        echo ">=media-fonts/font-bh-type1-1.0.3-r1 bh-luxi"  >> /etc/portage/package.license
        USE="dmx kdrive elogind -consolekit -systemd static-libs unwind xsecurity xorg xvfb " emerge -qv x11-base/xorg-server x11-base/xorg-x11 xorg-drivers
      elif [ initsys == 2 ]; then
        USE="dmx kdrive systemd -elogind -consolekit static-libs unwind xsecurity xorg xvfb " emerge -qv x11-base/xorg-server x11-base/xorg-x11 xorg-drivers
      fi
#VIDEO_CARDS
      header
      basicsetup
      emerge -qv dmidecode linux-firmware
      printf "${White}Installing Video Card Driver ....\n"
      vga
      emerge -qv libglvnd
      presskey
#CUPS
      header
      basicsetup
      printf "${White}Installing CUPS (aka Commom Unix Printing System ) ....\n"
      USE=" X acl dbus static-libs zeroconf " emerge -qv net-print/cups
      presskey
      continue

#DE & WM
      elif [ $menu == 2 ]; then
      		while true ; do
      			header
      			dewm
      			desktops
      			read proceed
      			if [ $proceed == 1 ]; then
      				if [ $initsys == 1 ]; then
      				 	USE="bluetooth browser-integration elogind -consolekit -systemd desktop-portal networkmanager display-manager gtk legacy-systray pam pm-utils pulseaudio sddm wallpapers mtp jumbo-build " emerge -qv kde-plasma/plasma-meta
      				elif [ $initsys == 2 ]; then
      				 	USE="bluetooth browser-integration -elogind -consolekit systemd desktop-portal networkmanager display-manager gtk legacy-systray pam pm-utils pulseaudio sddm wallpapers mtp jumbo-build " emerge -qv kde-plasma/plasma-meta
      				fi

      				printf "\n${White}Install KDE apps? (y/n)    "
      				read proceed2
      				if [ "$proceed2" == "y" ]; then
      					echo ">=media-libs/faac-1.29.9.2 MPEG-4 " >> /etc/portage/package.licnse
      					USE="mtp" emerge -qv kde{accessibility,admin,core,graphics,multimedia,network,utils}-meta
      				elif [ "$proceed2" == "n" ]; then
      					printf "${White}ok whatever \n"
      				fi

      				su $username -c "echo "exec dbus-launch --exit-with-session startplasma-x11" >> .xinitrc"
      				presskey

      			elif [ $proceed == 2 ]; then
      				if [ $initsys == 1 ]; then
      						USE=" mtp elogind -consolekit -systemd" emerge -qv xfce4-meta xfce4-notifyd xfce4-volumed-pulse
      				elif [ $initsys == 2 ]; then
      						USE=" mtp -elogind -consolekit systemd" emerge -qv xfce4-meta xfce4-notifyd xfce4-volumed-pulse

      				fi
      				su $username -c "echo "exec dbus-launch --exit-with-session xfce4-session " >> ~/.xinitrc"
      				presskey

      			elif [ $proceed == 3 ]; then
      				if [ $initsys == 1 ]; then
      						USE=" mtp elogind -consolekit -systemd" emerge -qv lxde-meta
      				elif [ $initsys == 2 ]; then
      						USE=" mtp -elogind -consolekit systemd" emerge -qv lxde-meta
      				fi
      				su $username -c "echo "exec dbus-launch --exit-with-session startlxde " >> .xinitrc"
      				presskey

      			elif [ $proceed == 4 ]; then
      				if [ $initsys == 1 ]; then
      					USE=" mtp elogind -consolekit -systemd" emerge -qv lxqt-meta
      				elif [ initsys == 2 ]; then
      					USE=" mtp elogind -consolekit -systemd" emerge -qv lxqt-meta
      				fi
      				su $username -c "echo "exec dbus-launch --exit-with-session startlxqt " >> .xinitrc"
      				presskey

      			elif [ $proceed == 5 ]; then
      				if [ $initsys == 1 ]; then
      					USE="base bluetooth extras notification mtp themes elogind -consolekit -systemd" emerge -qv --changed-use mate-base/mate caja-extensions
      				elif [ $initsys == 2 ]; then
      					USE="base bluetooth extras notification mtp themes -elogind -consolekit systemd" emerge -qv --changed-use mate-base/mate caja-extensions
      				fi
      				su $username -c "echo "exec dbus-launch --exit-with-session mate-session " >> .xinitrc"
      				presskey

      			elif [ $proceed == 6 ]; then
      				gnomereqs
      				if [ $initsys == 1 ]; then
      					USE=" bluetooth mtp networkmanager gtk -qt5 elogind -consolekit -systemd" emerge -qv gnome-base/gnome;
      					rc-update add openrc-settingsd default
      				elif [ initsys == 2 ]; then
      					USE=" bluetooth mtp networkmanager gtk -qt5 -elogind -consolekit systemd" emerge -qv gnome-base/gnome
      				su $username -c "echo "exec dbus-launch --exit-with-session gnome-session  " >> .xinitrc"
      				presskey
              fi

      			elif [ $proceed == 7 ]; then
      				printf "${White}Do you want i3-gaps? (y/n):    "
      				read proceed2
              declare i3wm
              if [ "$proceed2" == "y" ]; then
      					i3wm="i3-gaps"
      				else
      					i3wm="i3"
      				fi
      				emerge -qv $i3wm
      				USE=" xinerama filecaps libnotify" emerge -qv dmenu i3status i3lock thunar arandr lxappearance nitrogen dmenu pavucontrol volumeicon xarchiver
      				su $username -c "echo "exec dbus-launch --exit-with-session i3 " >> .xinitrc"
      				presskey

      			elif [ $proceed == 8 ]; then
      				USE="branding imlib session xdg libnotify" emerge -qv openbox thunar arandr lxappearance nitrogen dmenu pavucontrol volumeicon xarchiver
      				su $username -c "echo "exec dbus-launch --exit-with-session openbox-session " >> .xinitrc"
      				presskey

      			elif [ "$proceed" == "d" ]; then
      				break
      			else
      				printf "${Red}Invalid Selection !\n"
                      presskey
                      continue
            fi
      		done #Loop's
      		header
      		dewm
      		printf "${White}Add bluetooth support? (y/n):    "
      		read proceed2
      		if [ "$proceed2" == "y"]; then
      			USE="bluetooth btpclient extra-tools midi user-session" emerge -qv bluez
      			if [ $initsys == 1 ]; then
      				rc-service bluetooth start
      				rc-update add bluetooth default
      			elif [ $initsys == 2 ]; then
      				systemctl start bluetooth
      				systemctl enable bluetooth
      			fi
          fi
      		if [ $initsys == 1 ]; then
                  rc-update add elogind boot
      		fi
      		rc-update add dbus default
      		gpasswd -a $username plugdev
#ACCESSORIES
	 elif [ $menu == 3 ]; then
		while true ; do
			header
			accs
			accessories
			read  proceed
      case "$proceed" in
        1)  emerge -qv albert
        ;;
        2)  emerge -qv kitty
        ;;
        3) echo ">=media-libs/gst-plugins-base-1.14.5-r1 theora" >> /etc/portage/package.use/zz-autounmask
            emerge -qv cheese
        ;;
        4) emerge -qv latte-dock
        ;;
        5) emerge -qv galculator
        ;;
        6) emerge -qv terminator;
        ;;
        "d") break
        ;;
        "*") printf "${Red}Invalid Selection !\n"
        ;;
      esac
        presskey
        break
      done

#DEVELOPMENT
elif [ $menu == 4 ]; then
      while true ; do
      	header
      	dev
      	development
        read  proceed
        case "$proceed" in
          1)  emerge -qv atom
          ;;
          2)  emerge -qv gvim
          ;;
          3) flatpak install flathub com.visualstudio.code
          ;;
          4) emerge -qv jre
          ;;
          5) emerge -qv jdk
          ;;
          6) emerge -qv clang
          ;;
          7) emerge -qv codeblocks
          ;;
          8) flatpak install flathub cc.arduino.arduinoide
          ;;
          9) flatpak install flathub com.google.AndroidStudio
          ;;
          10) flatpak install flathub com.axosoft.GitKraken
          ;;
          11) flatpak install flathub org.apache.netbeans
          ;;
          "d") break
          ;;
          "*") printf "${Red}Invalid Selection !\n"
          ;;
        esac
          presskey
          break
        done

#OFFICE
elif [ $menu == 5 ]; then
      while true ; do
      header
      office
      officemenu
      read  proceed
      case "$proceed" in
        1)  USE="cups pdfimport gstreamer" emerge -qv libreoffice
        ;;
        2)  USE="cups pdfimport gstreamer" emerge -qv libreoffice
        ;;
        3) emerge -qv evince
        ;;
        4) emerge -qv ghostwriter
        ;;
        5) echo ">=app-office/wps-office-11.1.0.9080 WPS-EULA" >> /etc/portage/package.license
            emerge -qv openoffice-bin
        ;;
        "d") break
        ;;
        "*") printf "${Red}Invalid Selection !\n"
        ;;
        esac
        presskey
        break
        done
  fi #MENU's
done

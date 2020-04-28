/*
-----------------------------------------------------------------------------
Created by Baraa Al-Masri | E-Mail : baraa.masri@asu.edu.jo | Twitter : @Baraa_Da_Boss
Grab me a cup of coffee : https://www.paypal.me/baraamasri
Contributer: Baraa Al-Masri
------------------------------------------------------------------------------
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
-------------------------------------------------------------------------------
 Run this program after your first boot with gentoolinux (as root)
 */
#include<iostream>
#include<string>
#include<unistd.h>
#include<stdlib.h>
//#include"functions.h"
#include"unmask_func.h"
using namespace std;
int main () {
	system("clear");
	header1();
	presskey();
	header2();
	cout << endl << endl ;
	char proceed='n',proceed2='n';
	cout << "Update Ebuild Repository? (y/n):   ";
	cin >> proceed;
	if(proceed == 'y'){
		cout << "Updating Repos....\n";
		system("emerge --sync");
	}
	presskey();
	header2();
	cout << endl << endl ;
	char initsys = '2';
	while(true){
	header2();
	cout << WHITE << "Current profile : \n";
	system("eselect profile show"); cout << endl;
	cout << "Select A Profile :\n" << RED << "PS choose init system that matches your installation \nDON'T select init system other than in your installation or the setup will be corrupted !!!! \n\n"
		<< WHITE << "1. Proceed with the current profile & init system\n"
		<< "2. Normal Desktop with openRC \n"
		<< "3. Gnome Desktop with openRC \n"
		<< "4. Plasma Desktop with openRC \n"
		<< "5. Normal Desktop with SystemD \n"
		<< "6. Gnome Desktop with SystemD  \n"
		<< "7. Plasma Desktop with SystemD \n";
	string profileslist[7]={"printf 'What is your init system \n1. openRC \n2. SystemD \n'" , "eselect profile set default/linux/amd64/17.1/desktop", "eselect profile set default/linux/amd64/17.1/desktop/gnome" , "eselect profile set default/linux/amd64/17.1/desktop/plasma", "eselect profile set default/linux/amd64/17.1/systemd"  , "eselect profile set default/linux/amd64/17.1/desktop/gnome/systemd" , "eselect profile set default/linux/amd64/17.1/desktop/plasma/systemd"} ;
	int select ;
  cin >> select;
  if(select > 7){
	cout << "\nInvalid Selection !!!!";
  }
	else{
			const char *exec = profileslist[select - 1].c_str();
      system(exec);
  }
	if(select < 5 && select > 1){
		initsys = '1';
	}
	else if(select == 1){
		cin >> initsys;
	}

	header2();
	cout << "Your selected profile is:    ";
	system("eselect profile show");
	cout << endl <<"Is that what you selected? (y/n):    ";
	cin >> proceed;
	if(proceed == 'y' || proceed == 'Y'){
		break;
	}else if(proceed == 'n' || proceed == 'N'){
		continue;
	}else{
		cout << "\nInvalid selection !!!! \n";
		continue;
	}
}//loop's
	cout << "Update system with the selected profile? (y/n):    ";
	cin >> proceed;
	if(proceed == 'y' || proceed == 'Y'){
		system("emerge --ask --verbose --update --deep --newuse @world");
	}else{
		cout << "\nInvalid select !!!! \n";
	}

//USER CREATION:
	system("clear");
	//hey baraa never declare a variable inside a loop and expect using it later dummy
	string username;

	while(true){
	header2();
	cout << endl << endl << GREEN << "User Creation: \n\n";
	cout << WHITE << "Available Users: \n";
	system("cat /etc/passwd | grep 100");
	cout << endl << ("do you want to add users? (y/n):    ");
	cin >> proceed;
	if(proceed == 'y' || proceed == 'Y'){
        	//string user1 = ("useradd -m -G wheel,audio,video,adm,disk,tty -s /bin/bash ");
        	string user1 = ("useradd -m -G wheel,audio,video,portage,adm,disk,tty -s /bin/bash ");
		cout << ("Enter username :    ");
       		cin >> username;
       		user1 = user1 + username;
		const char *user = user1.c_str();
		system(user);
		//user details
		string uconf = ("chfn ");
		string passwd = ("passwd ");
		uconf = uconf + username;
		passwd = passwd + username;
		const char *uconf0 = uconf.c_str();
		const char *upasswd = passwd.c_str();
		system(upasswd);
		system(uconf0);
		//Sudoing the user
		while(true){
			cout << ("Installing sudo \n");
			system("emerge -qvt sudo");
			//sudo prompt
			system("cp ./configuration_files/sudoers /etc/sudoers");
			presskey();
			int sudo;
			cout << "Choose sudo prompt type : \n"
				<< "1. With password \n"
				<< "2. Without password \n" << endl;
			cin >> sudo;
			if(sudo == 1){
				string pass = ("echo \"%wheel ALL=(ALL)  ALL \" >> /etc/sudoers");
				const char *passsudo = pass.c_str();
				system(passsudo);
				break;
			}else if(sudo == 2){
				string nopass = ("echo \"%wheel ALL=(ALL) NOPASSWD: ALL \" >> /etc/sudoers");
				const char *nopasssudo = nopass.c_str();
				system(nopasssudo);
				break;
			}else{
				cout << "choose  ONLY from the menu !!!!\n";
				continue;
			}

		}//Loop's
		presskey();
		break;

	}else if(proceed == 'n' || proceed == 'N'){
		cout << "Enter your current(already added) username :    ";
		cin >> username;
		presskey();
		break;

	}else{
                cout << "\nInvalid selection !!!!";
		continue;
        }
}//Loop's
//EDITOR SELECTION:
	string swuser = ("su ") , dashc = (" -c ");
	while(true){
	header2();
	cout << WHITE<< "\nSelect a default editor: \n\n"
				<< "1.vim \n2.vi \n3.nano \n4.emacs \n"<< RESET;
	char editor;
	cin >> editor;
	if(editor == '1'){
		system("emerge -qvt vim ctags");
		string vim = ("\"echo export EDITOR='vim' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + vim;
		const char *editorvim = swuser.c_str();
		system(editorvim);
		swuser = ("su ");
		break;
	}else if(editor == '2'){
		string vi = ("\"echo export EDITOR='vi' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + vi;
		const char *editorvi = swuser.c_str();
		system(editorvi);
		swuser = ("su ");
		break;
	}else if(editor == '3'){
		system("emerge -qvt nano");
		string nano = ("\"echo export EDITOR='nano' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + nano;
		const char *editornano = swuser.c_str();
		system(editornano);
		swuser = ("su ");
		break;
	}else if(editor == '4'){
		system("emerge -qvt emacs");
		string emacs = ("\"echo export EDITOR='emacs' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + emacs;
		const char *editoremacs = swuser.c_str();
		system(editoremacs);
		swuser = ("su ");
		break;
	}else {
		cout << "Invalid Choice \n";
		continue;
	}
}//Loop's

//PRE-SETUP
//NECESSARY-PACKAGES
//BASH-TOOLS
	header2();
	presetup();
	cout << "Installing Some Shell Tools....\n\n";
	emerge("" , " git bc bash-completion rsync mlocate");
	presskey();
//ARCHIVE-TOOLS
	header2();
	presetup();
	cout << "Installing archive tools....\n\n";
	acceptlicnse(">=app-arch/rar-5.8.0_p20191205 RAR");
	acceptlicnse(">=app-arch/unrar-5.9.1 unRAR");
	emerge("", " zip unzip unrar rar p7zip lzop cpio xz-utils --autounmask-write");
	presskey();
//AVAHI
	header2();
	presetup();
	cout << "Installing avahi a zero configuration networking implementation....\n\n";
	emerge(""," net-dns/avahi nss-mdns");
	if(initsys == '1'){
		system("rc-update add avahi-daemon default");
		system("rc-service avahi-daemon start");
	}else if(initsys == '2'){
		system("systemctl enable avahi-daemon.service");
		system("systemctl start avahi-daemon.service");
	}
	presskey();
//ALSA & PUSLEAUDIO
	header2();
	presetup();
	cout << "Installing ALSA (Advanced Linux Sound Architecture)....\n\n";
	emerge("alsip thread-safety python", "alsa-lib alsa-utils");
	emerge("ffmpeg","alsa-plugins");
	system("cp ./configuration_files/asound.conf /etc/asound.conf");
	if(initsys == '1'){
		system("rc-service alsasound start");
		system("rc-update add alsasound boot");
	}else if(initsys == '2'){
		cout << "Already enabled LOL \n";
	}
	cout << "Installing Pulseaudio....\n\n";
	emerge("pulseaudio X alsa-plugin elogind equalizer gconf gdbm glib native-headset ofono-headset realtime webrtc-aec alsa bluetooth caps dbus jack orc sox tcpd zerocon", "pulseaudio");
	if(initsys == '2'){
		system("rc-update add pulseaudio default");
		system("rc-update add pulseaudio default");
	}else if(initsys == '2'){
		cout << "Already enabled LOL \n";
	}
	presskey();
//FILESYSTEMS
	header2();
	presetup();
	cout << "Installing Some Useful Filesystems....\n\n";
	emerge("", " ntfs3g dosfstools f2fs-tools sys-fs/fuse exfat-utils autofs fuse-exfat mtpfs fuseiso");
	presskey();
//MAIN-MENU
    bool flatpak_istalled = 0;
	while(true){
	header2();
	mainmenu(username);
	int menu;
	cin >> menu;
	//BASICSETUP
	if(menu == 1){
		//CUSTOM REPOS(OVERLAYS)
		while(true){
		header2();basicsetup();
		cout << "Do you want to add a custom repo (overlay)? (y/n) :  ";
		cin >> proceed;
		if(proceed == 'y' || proceed == 'Y'){
			string reponame;
			cout << "Installing Layman ....\n";
			emerge("bazaar cvs darcs g-sorcery git gpg mercurial squashfs subversion sync-plugin-portage", "layman");
			system("layman -L");
			presskey();
            addrepo();
            while(true){
                cout << "Add another repo? (y/n)    ";
                cin >> proceed2;
                if(proceed2 == 'y'){
                    addrepo();
                    presskey();
                }else if(proceed2 == 'n'){
                    presskey();
                    break;
                }
            }

			break;
		}else{break;}
		}//Layman's Loop's
		//FLATPAK
		while(true){
		header2();basicsetup();
		cout << "Do you want to install flatpak? (y/n) :  ";
		cin >> proceed;
		if(proceed == 'y' || proceed == 'Y'){
			cout << "Installing Flatpak ....\n";
            system("mkdir /etc/portage/repos.conf && cp ./configuration_files/flatpak-overlay.conf /etc/portage/repos.conf/ ");
            emerge("" , " --sync flatpak-overlay");
			emerge("", "sys-apps/flatpak");
			flatpak_istalled = 1;
            presskey();
			break;
		}else{break;}
		}//Flatpak's Loop's
		//SSH
		header2();basicsetup();
		cout << "Installing SSH ....\n";
		emerge(""," openssh");
		if(initsys == '1'){
			system("rc-update add sshd default");
			system("rc-service sshd start");
		}else if(initsys == '2'){
			system("systemctl enable sshd.service");
			system("systemctl start sshd.service");
		}presskey();
		//ZSH
		header2();basicsetup();
		cout << "Install ZSH ? (y/n) :   ";
		while(true){
			cin >> proceed;
			if(proceed == 'y' || proceed == 'Y'){
				emerge("maildir unicode "," zsh");
				string chsh = ("chsh ") , dashs = (" -s ") , zsh = (" /bin/zsh");
				chsh = chsh + username + dashs + zsh;
				const char *zsh0 = chsh.c_str();
				system(zsh0);
				break;
			}else if(proceed == 'n' || proceed == 'N'){
				break;
			}else{
				cout << "\nInvalid selection !!!! \n";
				continue;
			}
		}//zsh's loop's
		presskey();
		//XORG
		header2();basicsetup();
		cout << "Installing Xorg server (req. for desktop environment, GPU Drivers, Keyboard layouts ,etc.... \n";
		if(initsys == '1'){
			system("echo \">=media-fonts/font-bh-ttf-1.0.3-r1 bh-luxi\"  >> /etc/portage/package.license ");
			system("echo \">=media-fonts/font-bh-type1-1.0.3-r1 bh-luxi\"  >> /etc/portage/package.license ");
			emerge(" dmx kdrive elogind -consolekit -systemd static-libs unwind xsecurity xorg xvfb "," x11-base/xorg-server x11-base/xorg-x11 xorg-drivers ");
		}else if(initsys == '2'){
			emerge(" dmx kdrive systemd -elogind -consolekit static-libs unwind xsecurity xorg xvfb "," x11-base/xorg-server x11-base/xorg-x11 xorg-drivers ");
		}
		//VIDEO_CARDS
		header2();basicsetup();
		emerge(""," dmidecode linux-firmware ");
		cout << "Installing Video Card Driver ....\n";
		system("./bash_scripts/video_driver.sh");
		emerge(""," libglvnd ");
		presskey();
		//CUPS
		header2();basicsetup();
		cout << "Installing CUPS (aka Commom Unix Printing System ) ....\n";
		emerge(" X acl dbus static-libs zeroconf "," net-print/cups ");
		presskey();
		continue;
	}//(menu == 1)'s
	//DE & WM
	else if(menu == 2){
		while(true){
			header2(); dewm(); desktops();
			cin >> proceed;
			if(proceed == '1'){
				if(initsys == '1'){
				emerge(" bluetooth browser-integration elogind -consolekit -systemd desktop-portal networkmanager display-manager gtk legacy-systray pam pm-utils pulseaudio sddm wallpapers mtp jumbo-build " , " kde-plasma/plasma-meta ");
				}
				else if(initsys == '2'){
				emerge(" bluetooth browser-integration -elogind -consolekit systemd desktop-portal networkmanager display-manager gtk legacy-systray pam pm-utils pulseaudio sddm wallpapers mtp jumbo-build " , " kde-plasma/plasma-meta ");
				}

				cout << "Install KDE apps? (y/n)    ";
				cin >> proceed2;
				if(proceed2 == 'y'){
					system("echo \">=media-libs/faac-1.29.9.2 MPEG-4 \" >> /etc/portage/package.licnse ");
					emerge("mtp"," kde{accessibility,admin,core,graphics,multimedia,network,utils}-meta");
				}else if(proceed2 == 'n'){
					cout << "ok whatever \n";

				}
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session startplasma-x11\" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();

			}
			else if(proceed == '2'){
				if(initsys == '1'){
				emerge(" mtp elogind -consolekit -systemd" , " xfce4-meta xfce4-notifyd xfce4-volumed-pulse ");
				}
				else if(initsys == '2'){
				emerge(" mtp -elogind -consolekit systemd" , " xfce4-meta xfce4-notifyd xfce4-volumed-pulse ");
				}
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session xfce4-session \" >> ~/.xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}
			else if(proceed == '3'){
				if(initsys == '1'){
				emerge(" mtp elogind -consolekit -systemd" , " lxde-meta ");
				}
				else if(initsys == '2'){
				emerge(" mtp -elogind -consolekit systemd" , " lxde-meta ");
				}
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session startlxde \" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}
			else if(proceed == '4'){
				if(initsys == '1'){
				emerge(" mtp elogind -consolekit -systemd" , " lxqt-meta ");
				}
				else if(initsys == '2'){
				emerge(" mtp elogind -consolekit -systemd" , " lxqt-meta ");
				}
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session startlxqt \" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}
			else if(proceed == '5'){
				if(initsys == '1'){
				emerge("base bluetooth extras notification mtp themes elogind -consolekit -systemd" , " --changed-use mate-base/mate caja-extensions");
				}
				else if(initsys == '2'){
				emerge("base bluetooth extras notification mtp themes -elogind -consolekit systemd" , " --changed-use mate-base/mate caja-extensions ");
				}
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session mate-session \" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}
			else if(proceed == '6'){
				gnomereqs();
				if(initsys == '1'){
				emerge(" bluetooth mtp networkmanager gtk -qt5 elogind -consolekit -systemd" , " gnome-base/gnome  ");
				system("rc-update add openrc-settingsd default ");
				}
				else if(initsys == '2'){
				emerge(" bluetooth mtp networkmanager gtk -qt5 -elogind -consolekit systemd" , " gnome-base/gnome ");
				}
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session gnome-session  \" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}
			else if(proceed == '7'){
				cout << "Do you want i3-gaps? (y/n)    ";
				cin >> proceed2;
				string i3wm;
				if(proceed2 == 'y'){
					i3wm = ("i3-gaps");
				}else{
					i3wm = ("i3");
				}
				emerge("" , i3wm );
				emerge(" xinerama filecaps libnotify" , " dmenu i3status i3lock thunar arandr lxappearance nitrogen dmenu pavucontrol volumeicon xarchiver ");
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session i3 \" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}
			else if(proceed == '8'){
				emerge("branding imlib session xdg libnotify" , "openbox thunar arandr lxappearance nitrogen dmenu pavucontrol volumeicon xarchiver ");
				string xinitrc	= ("\" echo \"exec dbus-launch --exit-with-session openbox-session \" >> .xinitrc\"");
				swuser = swuser + username + dashc + xinitrc;
				const char *startx = swuser.c_str();
				system(startx);
				presskey();
			}

			else if(proceed == 'd'){
				break;
			}
			else{
				cout << "Invalid Selection !\n";
                presskey();
                continue;
			}

		}//Loop's
		header2();dewm();
		cout << "Add bluetooth support? (y/n)    ";
		cin >> proceed2;
		if(proceed2 == 'y'){
			emerge("bluetooth btpclient extra-tools midi user-session" , "bluez");
			if(initsys == '1'){
				system("rc-service bluetooth start");
				system("rc-update add bluetooth default");
			}
			else if(initsys == '2'){
				system("systemctl start bluetooth");
				system("systemctl enable bluetooth");
			}
	}
		if(initsys == '1' ){
            system("rc-update add elogind boot ");
    }
		system("rc-update add dbus default");
		string gpasswd = ("gpasswd -a ");
		gpasswd = gpasswd + username + "plugdev";
		const char *group = gpasswd.c_str();
		system(group);


	}//(menu == 2)'s
	 else if(menu == 3){
		while(true){
			header2(); accs(); accessories();
			cin >> proceed;

            switch(proceed){
                case '1':
                    emerge("" , "albert");
                    break;
                case '2':
                    emerge("" , "kitty");
                    break;
                case '3':
                    emerge("" , " cheese");
                    unmask(">=media-libs/gst-plugins-base-1.14.5-r1 theora");
                    break;
                case '4':
                    emerge("" , "latte-dock");
                    break;
                case '5':
                    emerge("" , "galculator");
                    break;
                case '6':
                    emerge("" , "terminator");
                    break;
                case 'd':
                    break;
                default:
                    cout << "Invalid Selection !\n";
                    presskey();
            }
            break;

        }
    }//(menu == 3)'s
	 else if(menu == 4){
		while(true){
			header2(); dev(); development();
			cin >> proceed;

            switch(proceed){
                case '1':
                    emerge("" , "app-editors/atom");
                    break;
                case '2':
                    emerge("" , "gvim");
                    break;
                case '3':
                    if(flatpak_istalled){
                        flatpak("com.visualstudio.code");
                    }else{
                        break;
                    }
                case '4':
                    emerge("" , "virtual/jre");
                    break;
                case '5':
                    emerge("" , "virtual/jdk");
                    break;
                case '6':
                    emerge("" , "clang");
                    break;
                case '7':
                    emerge("" , "codeblocks");
                    break;
                case '8':
                    if(flatpak_istalled){
                        flatpak("cc.arduino.arduinoide");break;
                    }else{
                        break;
                    }
                case '9':
                    if(flatpak_istalled){
                        flatpak("com.google.AndroidStudio");break;
                    }else{
                        break;
                    }
                case 'a':if(flatpak_istalled){
                        flatpak("com.axosoft.GitKraken");break;
                    }else{
                        break;
                    }
                case 'b':
                    if(flatpak_istalled){
                        flatpak("org.apache.netbeans");break;
                    }else{
                        break;
                    }
                case 'd':
                    break;
                default:
                    cout << "Invalid Selection !\n";
                    presskey();
            }
            break;

        }
    }//(menu == 4)'s
	 else if(menu == 5){
		while(true){
			header2(); office(); officemenu();
			cin >> proceed;

            switch(proceed){
                case '1':
                    emerge("cups pdfimport gstreamer" , "libreoffice");
                    break;
                case '2':
                    emerge("cups pdfimport gstreamer" , "libreoffice-bin");
                    break;
                case '3':
                    emerge("" , " evince");
                    break;
                case '4':
                    emerge("" , "ghostwriter");
                    break;
                case '5':
                    emerge("" , "openoffice-bin");
                    break;
                case '6':
                    acceptlicnse(">=app-office/wps-office-11.1.0.9080 WPS-EULA");
                    emerge("" , "wps-office");
                    break;
                case 'd':
                    break;
                default:
                    cout << "Invalid Selection !\n";
                    presskey();
            }
            break;

        }
	}//(menu == 5)'s
	 else if(menu == 6){
		while(true){
			header2(); sys(); systemmenu();
			cin >> proceed;

            switch(proceed){
                case '1':
			emerge("","--unmerge iptables");
			emerge("gui" , "net-firewalld/firewalld");
                    break;
                case '2':
                    emerge("(policykit) btrfs cryptsetup dmraid f2fs fat hfs jfs mdadm ntfs reiser4 reiserfs -test udf -wayland xfs" , "gparted");
                    break;
                case '3':
                    emerge("" , " gnome-disk-utility ");
                    break;
                case '4':
                    emerge("" , "htop");
                    break;
                case '5':
                    emerge("" , "wine-vanilla");
                    break;
                case '6':
		    winereqs();
                    emerge("" , "wine-staging");
                    break;
                case '7':
		    addgitrepo("stefantalpalaru","https://github.com/stefantalpalaru/gentoo-overlay");
                    if(initsys=='1'){
		    	emerge("cups macos-guests* modules vmware-tools-darwin* vmware-tools-darwinPre15* vmware-tools-linux* vmware-tools-netware* vmware-tools-solaris* vmware-tools-winPreVista* vmware-tools-windows* -doc -ovftool -systemd -vix -vmware-tools-linuxPreGlibc25 -vmware-tools-winPre2k","vmware-workstation");
		    }
		    else if(initsys=='2'){
		    	emerge("cups macos-guests* modules vmware-tools-darwin* vmware-tools-darwinPre15* vmware-tools-linux* vmware-tools-netware* vmware-tools-solaris* vmware-tools-winPreVista* vmware-tools-windows* -doc -ovftool systemd -vix -vmware-tools-linuxPreGlibc25 -vmware-tools-winPre2k" , "vmware-workstation");
		    }
                    break;
                case 'd':
                    break;
                default:
                    cout << "Invalid Selection !\n";
                    presskey();
            }
            break;

        }
	}//(menu == 6)'s
        //Valar Dohaeris
	}//Mainmenu's Loop's



};//MAIN FUNCTION'S

//FUNCTIONS
//Guess who moved out! :)

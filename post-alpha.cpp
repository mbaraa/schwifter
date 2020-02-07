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
using namespace std;
void header1();
void header2();
void presetup();
void emerge(string, string);
void mainmenu(string);
void basicsetup();
void dewm();
void presskey();
void desktops();
void unmask(string);
int main () {
	system("clear");	
	header1();
	presskey();
	header2();
	cout << endl << endl ;
	char proceed='n',proceed2='n';
	cout << "Update Ebuild Repo ? (y/n)   ";
	cin >> proceed;
	if(proceed == 'y'){
		cout << "Updating Repos....\n";
		system("emerge-webrsync && emerge --sync");
	}
	presskey();
	header2();
	cout << endl << endl ;	
	char profile1 ,initsys;
	while(true){
	header2();
	cout << "Current profile : \n";	
	system("eselect profile show"); cout << endl;
	cout << "Select A Profile :\n PS choose init system that matches your installation \n DON'T select init system other than in your installation or the setup will be corrupted !!!! \n"
		<< "1. Proced with the current profile \n"
		<< "2. Normal Desktop \n"
		<< "3. Gnome Desktop \n"
		<< "4. Plasma Desktop \n"
		<< "5. No Multilib (don't select this unless you know what are you doing ! \n";
		cin >> profile1;
		cout << "Now select initial system :\n"
		<< "1. openRC\n"
		<< "2. SystemD\n";
		cin >> initsys;
	if(profile1 == '1' && initsys == '1'){
		cout << "OK whatever \n";
	}else if(profile1 == '1' && initsys == '2'){
		cout << "OK whatever \n";
	}else if (profile1 == '2' && initsys == '1'){
		system("eselect profile set default/linux/amd64/17.1/desktop");
	}else if (profile1 == '2' && initsys == '2'){
		system("eselect profile set default/linux/amd64/17.1/systemd");
	}else if (profile1 == '3' && initsys == '1'){
		system("eselect profile set default/linux/amd64/17.1/desktop/gnome ");
	}else if (profile1 == '3' && initsys == '2'){
		system("eselect profile set default/linux/amd64/17.1/desktop/gnome/systemd");
	}else if (profile1 == '4' && initsys == '1'){
		system("eselect profile set default/linux/amd64/17.1/desktop/plasma");
	}else if (profile1 == '4' && initsys == '2'){
		system("eselect profile set default/linux/amd64/17.1/desktop/plasma/systemd");
	}else if (profile1 == '5' && (initsys == '1' || initsys == '2')){
		system("eselect profile set default/linux/amd64/17.1/no-multilib");
	}else {
		cout << "\nInvalid selection !!!!\n";
		
	}
	header2();
	cout << "your selected profile is : ";
	system("eselect profile show");
	cout << "\n Is that what you selected ? (y/n) :  ";
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
	cout << "Update system with the selected profile ? (y/n) :    ";
	cin >> proceed;
	if(proceed == 'y' || proceed == 'Y'){
		system("emerge --ask --verbose --update --deep --newuse @world");
	}else{
		cout << "\nInvalid select !!!! \n";
	}

//USER CREATION:
	system("clear");
	//hey baraa never declare a variable inside a loop and expect using it late dummy
	string username;

	while(true){
	header2();
	cout << endl << endl << "User Creation : \n";
	cout << ("Available Users : \n");
	system("cat /etc/passwd | grep 100");
	cout << ("do you want to add users ? (y/n)\n");
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
	cout << "Select a default editor : \n" ;
	char editor;
	cout << " 1.vim \n 2.vi \n 3.nano \n 4.emacs \n";
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
	cout << "Installing Some Shell Tools ....\n";
	emerge("" , " git bc bash-completion rsync mlocate");
	presskey();
//ARCHIVE-TOOLS
	header2();
	presetup();
	cout << "Installing archive tools ....\n";
	system("echo \">=app-arch/rar-5.8.0_p20191205 RAR\"  >> /etc/portage/package.license ");
	system("echo \">=app-arch/unrar-5.9.1 unRAR\"  >> /etc/portage/package.license ");
	emerge("", " zip unzip unrar rar p7zip lzop cpio xz-utils --autounmask-write");
	presskey();
//AVAHI
	header2();
	presetup();
	cout << "Installing avahi a zero configuration networking implementation ....\n";
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
	cout << "Installing ALSA (Advanced Linux Sound Architecture) ....\n";
	emerge("alsip thread-safety python", "alsa-lib alsa-utils");
	emerge("ffmpeg","alsa-plugins");
	system("cp ./configuration_files/asound.conf /etc/asound.conf");
	if(initsys == '1'){
		system("rc-service alsasound start");
		system("rc-update add alsasound boot");
	}else if(initsys == '2'){
		cout << "Already enabled LOL \n";
	}
	cout << "Installing Pulseaudio ....\n";
	emerge("pulseaudio X alsa-plugin elogind equalizer gconf gdbm glib native-headset ofono-headset realtime webrtc-aec alsa bluetooth caps dbus jack orc sox tcpd zerocon", "pulseaudio");
	if(initsys == '2'){
		system("rc-update add pulseaudio default");
		system("rc-update add pulseaudio default");
	}else if(initsys == '2'){
		cout << "Already enabled LOL \n";
	}
//FILESYSTEMS
	header2();
	presetup();
	cout << "Installing Some Useful Filesystems ....\n";
	emerge("", " ntfs3g dosfstools f2fs-tools sys-fs/fuse exfat-utils autofs fuse-exfat mtpfs fuseiso");
	presskey();
//MAIN-MENU
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
		cout << "Do you want to add a custom repo (overlay) ? (y/n) :  ";
		cin >> proceed;
		if(proceed == 'y' || proceed == 'Y'){
			string reponame;
			cout << "Installing Layman ....\n";
			emerge("bazaar cvs darcs g-sorcery git gpg mercurial squashfs subversion sync-plugin-portage", "layman");
			system("layman -L");
			presskey();
			string repolayman = ("layman -a ");
			cout << "Enter a Repo\'s Name (from https://overlays.gentoo.org ONLY) : ";
			cin >> reponame;
			repolayman = repolayman + reponame;
			const char *addrepo = repolayman.c_str();
			system(addrepo);
			system("emerge --sync");
			presskey();
			break;
		}else{break;}
		}//Layman's Loop's
		
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
				emerge(" bluetooth browser-integration elogind -consolekit -systemd desktop-portal networkmanager display-manager gtk legacy-systray pam pm-utils pulseaudio sddm wallpapers mtp " , " kde-plasma/plasma-meta ");
				}
				else if(initsys == '2'){
				emerge(" bluetooth browser-integration -elogind -consolekit systemd desktop-portal networkmanager display-manager gtk legacy-systray pam pm-utils pulseaudio sddm wallpapers mtp " , " kde-plasma/plasma-meta ");
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
				system("echo \">=media-plugins/grilo-plugins-0.3.9 tracker \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=media-libs/gegl-0.4.20 raw \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-libs/libgdata-0.17.11 gnome-online-accounts \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-libs/folks-0.12.1 eds \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=gnome-extra/evolution-data-server-3.32.5 vala \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/minitest-5.14.0 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/net-telnet-0.2.0 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/power_assert-1.1.5 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/rake-13.0.1 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/test-unit-3.3.5 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/xmlrpc-0.3.0 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/bundler-2.1.4 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/did_you_mean-1.4.0 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/json-2.3.0 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/rdoc-6.2.0 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/kpeg-1.1.0-r1 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/racc-1.4.16-r1 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=virtual/rubygems-16 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=dev-ruby/rubygems-3.1.2 ruby_targets_ruby27 \" >> /etc/portage/package.use/zz-autounmask ");
				system("echo \">=media-libs/gst-plugins-base-1.14.5-r1 theora \" >> /etc/portage/package.use/zz-autounmask ");
				
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
			//Valar Dohaeris

			else if(proceed == 'd'){
				break;
			}
			else{
				cout << "Invalid Selection !\n";
			}
					
		}//Loop's
		system("rc-update add elogind boot ");
		system("rc-update add dbus default");
		string gpasswd = ("gpasswd -a ");
		gpasswd = gpasswd + username + "plugdev";
		const char *group = gpasswd.c_str();
		system(group);

	}//(menu == 2)'s
	}//Mainmenu's Loop's 


		
};//MAIN FUNCTION'S

//FUNCTIONS
void header1(){
	cout << "Welcome to the Gentoo Linux Schwifter(installer) program by Baraa Al-Masri\n"
		<< "----------------------------------------------------------------------------\n"
		<< "Requirements : \n -> Gentoo Linux Installation \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n -> A lot of time(approx. 12 hours) & patience \n -> A barrel of coffee\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Program can be canceled anytime with CTRL+C \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "https://github.com/baraa-almasri/schwifter\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "P.S. This is still an alpha version DON'T run it on a non gentoo system ,\n also it supports only english locale and x86_64 architecture \n more locales and architectures will be supported in the future :) \n"
		<< "-----------------------------------------------------------------------------\n \n \n"<<endl;
}
void header2(){
	system("clear");
	cout << "-----------------------------------------------------------------------------\n           Gentoo Linux Ultimate Post Schwifter By Baraa Al-Masri \n-----------------------------------------------------------------------------"<<endl;
	cout << "-----------------------------------------------------------------------------\n           You gotta get schwifty in here            \n-----------------------------------------------------------------------------"<<endl;
}
void presetup(){
	cout << endl;
	cout << "################ \n## Pre-Setup: ##\n################\n"<<endl;
}
void emerge(string use , string package){
        string install =("emerge -qv ");
        string USE = ("USE=\" "), USE2 = (" \"  ");
        install = USE + use + USE2 + install + package;
        const char *in = install.c_str();
        system(in);
	/*to input a package name from keyboard 
	  and use it with this function use
	string pkgs,uses ;
        getline(cin, pkgs);
	getline(cin, uses);
        emerge(uses,pkgs);
	*/
}
void presskey(){
	cout << "\n Press enter to continue...."<<endl;
	cin.ignore();
	system("clear");
}
void basicsetup(){
	cout << endl;
	cout << "################ \n# Basic-Setup: #\n################\n"<<endl;
}
void dewm(){
	cout << endl;
	cout << "################ \n# Desktop Environments | Window Managers: #\n################\n"<<endl;
}
void mainmenu(string un){
	system("clear");
	cout << "################################ \n## Main Menu: ## User : " << un << "\n################################\n";
	cout << "\n\n";
	cout << "1. Basic Setup \n"
  		 << "2. Desktop Environments | Window Managers \n";
  	/* << "3. Accessories Apps \n";
  	 << "4. Development Apps \n";
	 << "5. Office Apps \n";
  	 << "6. System Apps \n";
  	 << "7. Graphics Apps \n";
  	 << "8. Internet Apps \n";
  	 << "9. Audio Apps \n";
 	 << "10. Video Apps \n";
 	 << "11. Games \n";
 	 << "12. Web server \n";
 	 << "13. Fonts \n";
         << "14. Cleaning Up \n";*/
 	/*   echo "17) $(mainmenu_item "${checklist[17]}" "Reconfigure System")"
	 */
}
void desktops(){
	cout << "\nCaution !!!! When Installing KDE make sure that you selected the plasma profile,\n also when installing Gnome make sure that you selected the gnome profile \n the rest can work with any profile . \n\n"
		<< "1. KDE Plasma \t|\t7. i3wm\n"
		<< "2. Xfce \t|\t8. Openbox\n"
		<< "3. LXDE \n"
		<< "4. LXQt \n"
		<< "5. Mate \n"
		<< "6. GNOME \n"
		<< "d. Done(go back to main menu)\n";

}
void unmask(string tounmask){
	string lol1 =("echo \" "), lol2 = (" \" >> /etc/portage/package.use/zz-autounmask ");
	lol1 = lol1 + tounmask + lol2 ;
	const char *exec=lol1.c_str();
	system(exec);
}

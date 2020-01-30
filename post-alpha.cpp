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
void presskey();
int main () {
	system("clear");	
	header1();
	presskey();
	header2();
	cout << endl << endl ;

	cout << "Updating Repos....\n";
	system("emerge-webrsync && emerge --sync");
	
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
	if(profile1 == '1'){
		cout << "go on \n";
		break;
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
		cout << "\nselect only from the menu !!!!\n";
		
	}
	header2();
	char proced1;
	cout << "your selected profile is : ";
	system("eselect profile show");
	cout << "\n Is that what you selected ? (y , n) don't type (yes) or (no)\n";
	cin >> proced1;
	if(proced1 == 'y' || proced1 == 'Y'){
		break;
	}else if(proced1 == 'n' || proced1 == 'N'){
		continue;
	}else{
		cout << "\nselect only y or n !!!! \n";
		continue;
	}
}//loop's


//USER CREATION:
	system("clear");
	//hey baraa never declare a variable inside a loop and expect using it late dummy
	string username;

	while(true){
	header2();
	cout << endl << endl << "User Creation : \n";
	cout << ("Available Users : \n");
	system("cat /etc/passwd | grep 100");
	cout << ("do you want to add users ? (y , n)\n");
	
	char proced2;
	cin >> proced2;
	if(proced2 == 'y' || proced2 == 'Y'){
		cout << ("Enter username :    ");
        	string user1 = ("useradd -m -G wheel,audio,video,portage,adm,disk,tty -s /bin/bash ");
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

	}else if(proced2 == 'n' || proced2 == 'N'){
		cout << "Enter your current(already added) username :    ";
		cin >> username;
		presskey();
		break;
		
	}else{
                cout << "\nselect only y or n";
		continue;
        }
}//Loop's

//EDITOR SELECTION:
	while(true){
	header2();
	cout << "Select a default editor : \n" ;
	char editor;
	cout << "1.vim \n 2.vi \n 3.nano \n 4.emacs \n";
	cin >> editor;
	
	string swuser = ("su ");
	string dashc = (" -c ");
	if(editor == '1'){
		system("emerge -qvt vim ctags");
		string vim = ("\"echo export EDITOR='vim' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + vim;
		const char *editorvim = swuser.c_str();
		system(editorvim);
		break;
	}else if(editor == '2'){
		string vi = ("\"echo export EDITOR='vi' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + vi;
		const char *editorvi = swuser.c_str();
		system(editorvi);
		break;
	}else if(editor == '3'){
		system("emerge -qvt nano");
		string nano = ("\"echo export EDITOR='nano' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + nano;
		const char *editornano = swuser.c_str();
		system(editornano);
		break;
	}else if(editor == '4'){ 	
		system("emerge -qvt emacs");
		string emacs = ("\"echo export EDITOR='emacs' >> ~/.bashrc \"");
		swuser = swuser + username + dashc + emacs;
		const char *editoremacs = swuser.c_str();
		system(editoremacs);
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
	emerge("", " zip unzip unrar rar p7zip lzop cpio xz-utils");
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
	cout << "Installing ALSA (Advanced Linux Sound Architecture ....\n";
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
	if(menu == 1){	
		//BASICSETUP
			//CUSTOM REPOS(OVERLAYS)
			while(true){
			header2();
			basicsetup();
			cout << "Do you want to add a custom repo (overlay) ? \n";
			char proced3;
			cin >> proced3;
			if(proced3 == 'y' || proced3 == 'Y'){
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
			}//Loop's of Layman's
			
			//SSH
			emerge(""," openssh");
			if(initsys == '1'){
				system("rc-update add sshd default");
				system("rc-service sshd start");
			}else if(initsys == '2'){
				system("systemctl enable sshd.service");
				system("systemctl start sshd.service");
			}

			//ZSH
	}
		//DE & WM
	}//Loop's Mainmenu


		
};//MAIN FUNCTION'S

//FUNCTIONS
void header1(){
	cout << "Welcome to the Gentoo Linux Schwifter(installer) program by Baraa Al-Masri\n"
		<< "----------------------------------------------------------------------------\n"
		<< "Requirements : \n -> Gentoo Linux Installation \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n -> A lot of time & patience \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Program can be canceled anytime with CTRL+C \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "https://github.com/baraa-almasri/glui\n"
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
void basicsetup(){
	cout << endl;
	cout << "################ \n# Basic-Setup: #\n################\n"<<endl;
}
void mainmenu(string un){
	system("clear");
	cout << "################################ \n## Main Menu: ## User : " << un << "\n################################\n";
	cout << "\n\n";
	cout << "1. Basic Setup \n";
  	/*cout << "2. Desktop Environments | Window Managers \n";
  	cout << "3. Accessories Apps \n";
  	cout << "4. Development Apps \n";
	cout << "5. Office Apps \n";
  	cout << "6. System Apps \n";
  	cout << "7. Graphics Apps \n";
  	cout << "8. Internet Apps \n";
  	cout << "9. Audio Apps \n";
 	cout << "10. Video Apps \n";
 	cout << "11. Games \n";
 	cout << "12. Web server \n";
 	cout << "13. Fonts \n";
 	cout << "14. Cleaning Up \n";*/
 	/*   echo "17) $(mainmenu_item "${checklist[17]}" "Reconfigure System")"
	 */
}
void presskey(){
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
}

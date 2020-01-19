/*
-----------------------------------------------------------------------------
Created by hexagon16 | E-Mail : hexagon16rpm@yandex.com | Twitter : @Larry_Gentoo
Grab me a cup of coffee : PayPal.Me/larrygentoo
Contributer: hexagon16
-------------------------------------------------------------------------------
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
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	header2();
	cout << endl << endl ;

	cout << "Updating Repos....\n";
	cout << "emerge-webrsync && emerge --sync";
	
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	header2();
	cout << endl << endl ;
	
	char profile1 ,initsys;
	while(true){
	header2();
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
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else if (profile1 == '2' && initsys == '2'){
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else if (profile1 == '3' && initsys == '1'){
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else if (profile1 == '3' && initsys == '2'){
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else if (profile1 == '4' && initsys == '1'){
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else if (profile1 == '4' && initsys == '2'){
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else if (profile1 == '5' && (initsys == '1' || initsys == '2')){
		cout << "DEMO!!!! So nothing happend , lol"<<endl;
	}else {
		cout << "\nselect only from the menu !!!!\n";
		
	}
	presskey();
	header2();
	char proced1;
	cout << "your selected profile is : ";
	cout << "DEMO!!!! So nothing happend , lol"<<endl;
	cout << "\n Is that what you selected ? (y or n) don't type (yes) or (no)\n";
	cin >> proced1;
	if(proced1 == 'y' || proced1 == 'Y'){
		break;
	}else if(proced1 == 'n' || proced1 == 'N'){
		continue;
	}else{
		cout << "\nselect only yes or no !!!! \n";
		continue;
	}
}//loop's


//USER CREATION:
	system("clear");
	//hey hexagon16 never declare a variable inside a loop and expect using it late
	string username;

	while(true){
	header2();
	cout << endl << endl << "User Creation : \n";
	cout << ("Available Users : \n");
	system("cat /etc/passwd | grep 100");
	cout << ("do you want to add users ? (yes or no)\nPS no user will be added since it's a DEMO\n");
	
	char proced2;
	cin >> proced2;
	if(proced2 == 'y' || proced2 == 'Y'){
		cout << ("Enter username \nPS no user will be added since it's a DEMO : ");
        	string user1 = ("useradd -m -G wheel,audio,video,portage,adm,disk,tty -s /bin/bash ");
       		cin >> username;
       		user1 = user1 + username;
		const char *user = user1.c_str();
		cout << "You can copy this command to create a user \"if not using gentoo don't use the portage group \n"<< user;
		//user details
		string uconf = ("chfn ");
		uconf = uconf + username;
		const char *uconf0 = uconf.c_str();
		cout << "And this command to add details to user \n" << uconf0;
		//Sudoing the user
		presskey();
		while(true){
			cout << ("Installing sudo again not really installing ,lol\n");
			emerge("","sudo");
			cout << "\n Press enter to continue"<<endl;
			cin.ignore();
			system("clear");
			int sudo;
			cout << "Choose sudo prompt type : \n"
				<< "1. With password \n"
				<< "2. Without password \n" << endl;
			cin >> sudo;
			if(sudo == 1){
				cout << "command if you want : \n";
				cout << "echo \"%wheel ALL=(ALL) ALL\" >> /etc/sudoers \n";
				break;
			}else if(sudo == 2){
				cout << "command if you want : \n";
				cout << "echo \"%wheel ALL=(ALL) NOPASSWD: ALL \" >> /etc/sudoers";
				break;
			}else{
				cout << "choose  ONLY from the menu !!!!\n";
				continue;
			}
			cout << "Again nothing happend !!!! \n";
		}//Loop's
		presskey();
		string sudoprompt = ("echo \"Defaults passprompt=\"[sudo] password for %u: \" >> /etc/sudoers");
		const char *prompt = sudoprompt.c_str();
		cout << "Prompt message when executing a command in sudo , add the following to /etc/sudoers "<< prompt;
		cout << "\n Press enter to continue"<<endl;
		cin.ignore();
		system("clear");
		break;

        }else if(proced2 == 'n' || proced2 == 'N'){
		cout << "Enter your username : ";
		cin >> username;
		cout << "\n Press enter to continue"<<endl;
		cin.ignore();
		system("clear");
		break;
		
	}else{
                cout << "\nselect only yes or no";
		continue;
        }
}//Loop's

	presskey();
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
		emerge("","ctags vim");
		cout << "\"echo export EDITOR='vim'\" >> ~/.bashrc ";
		break;
	}else if(editor == '2'){
		cout << "echo \"export EDITOR='vi'\" >> ~/.bashrc ";
		break;
	}else if(editor == '3'){
		emerge(""," nano");
		cout <<"echo \"export EDITOR='nano'\" >> ~/.bashrc ";
		break;
	}else if(editor == '4'){ 	
		emerge(""," emacs");
		cout << "echo \"export EDITOR='emacs'\" >> ~/.bashrc ";
		break;
	}else {
		cout << "Invalid Choice \n";
		continue;
	}
}//Loop's

	presskey();
//PRE-SETUP
//NECESSARY-PACKAGES
//BASH-TOOLS
	header2();
	presetup();
	cout << "Installing Some Shell Tools ....\n";
	emerge("" , " git bc bash-completion rsync mlocate");
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
//ARCHIVE-TOOLS
	header2();
	presetup();
	cout << "Installing archive tools ....\n";
	emerge("", " zip unzip unrar rar p7zip lzop cpio xz-utils");
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
//AVAHI
	header2();
	presetup();
	cout << "Installing avahi a zero configuration networking implementation ....\n";
	emerge(""," net-dns/avahi nss-mdns");
	system("rc-update add avahi-daemon default");
	system("rc-service avahi-daemon start");
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
//ALSA & PUSLEAUDIO
	header2();
	presetup();
	cout << "Installing ALSA (Advanced Linux Sound Architecture ....\n";
	emerge("alsip thread-safety python", "alsa-lib alsa-utils");
	emerge("ffmpeg","alsa-plugins");
	system("cp ./configuration_files/asound.conf /etc/asound.conf");
	system("rc-service alsasound start");
	system("rc-update add alsasound boot");
	cout << "Installing Pulseaudio ....\n";
	emerge("pulseaudio X alsa-plugin elogind equalizer gconf gdbm glib native-headset ofono-headset realtime webrtc-aec alsa bluetooth caps dbus jack orc sox tcpd zerocon", "pulseaudio");
	system("rc-update add pulseaudio default");
	system("rc-update add pulseaudio default");
//FILESYSTEMS
	header2();
	presetup();
	cout << "Installing Some Useful Filesystems ....\n";
	emerge("", " ntfs3g dosfstools f2fs-tools sys-fs/fuse exfat-utils autofs fuse-exfat mtpfs fuseiso");
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");

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
			string repolayman = ("layman -a ");
			string reponame;
			header2();
			presetup();
			cout << "Do you want to add a custom repo (overlay) ? \n";
			char proced3;
			cin >> proced3;
			if(proced3 == 'y' || proced3 == 'Y'){
				cout << "Installing Layman ....\n";
				emerge("bazaar cvs darcs g-sorcery git gpg mercurial squashfs subversion sync-plugin-portage", "layman");
				cout << "Enter a Repo\'s Name (from https://overlays.gentoo.org ONLY) : ";
				cin >> reponame;
				repolayman = repolayman + reponame;
				const char *addrepo = repolayman.c_str();
				system(addrepo);
				system("emerge --sync");
				cout << "\n Press enter to continue"<<endl;
				cin.ignore();
				system("clear");
				break;
			}else{break;}
			}//Loop's of Layman's
			

	}
		//DE & WM
	}//Loop's Mainmenu


		
};//MAIN FUNCTION'S

//FUNCTIONS
void header1(){
	cout << "Welcome to the Gentoo Linux Ultimate Post Installer demo by Hexagon16\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Requirements : \n Nothing since it's a demo \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Program demo can be canceled anytime with CTRL+C \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "https://github.com/hexagon16rpm/gupi\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "P.S. This is still a demo version you can run it on a non gentoo system and it does nothing at all to the system :) \ninsteade of running the commands the program will print them so you can see what's happenning behind the scene\n"
		<< "-----------------------------------------------------------------------------\n \n \n"<<endl;
}
void header2(){
	system("clear");
	cout << "-----------------------------------------------------------------------------\n           Gentoo Linux Ultimate Post Installer By Hexagon16 \"Demo\" \n-----------------------------------------------------------------------------\n \n \n"<<endl;
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
        cout << "command if you want " << in <<endl;
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
	cout << "################ \n# Basic-Setup: \"Demo\" #\n################\n"<<endl;
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

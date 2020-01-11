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
int main () {
	system("clear");	
	header1();
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	header2();
	cout << endl << endl ;

	cout << "Updating Repos....\n";
	system("emerge-webrsync && emerge --sync");
	
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	header2();
	cout << endl << endl ;
	
	char profile1 ,profile2;
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
		cin >> profile2;
	if(profile1 == '1'){
		cout << "go on \n";
		break;
	}else if (profile1 == '2' && profile2 == '1'){
		system("eselect profile set default/linux/amd64/17.1/desktop");
	}else if (profile1 == '2' && profile2 == '2'){
		system("eselect profile set default/linux/amd64/17.1/systemd");
	}else if (profile1 == '3' && profile2 == '1'){
		system("eselect profile set default/linux/amd64/17.1/desktop/gnome ");
	}else if (profile1 == '3' && profile2 == '2'){
		system("eselect profile set default/linux/amd64/17.1/desktop/gnome/systemd");
	}else if (profile1 == '4' && profile2 == '1'){
		system("eselect profile set default/linux/amd64/17.1/desktop/plasma");
	}else if (profile1 == '4' && profile2 == '2'){
		system("eselect profile set default/linux/amd64/17.1/desktop/plasma/systemd");
	}else if (profile1 == '5' && (profile2 == '1' || profile2 == '2')){
		system("eselect profile set default/linux/amd64/17.1/no-multilib");
	}else {
		cout << "\nselect only from the menu !!!!\n";
		
	}
	header2();
	char proced1;
	cout << "your selected profile is : ";
	system("eselect profile show");
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
	string user2;

	while(true){
	header2();
	cout << endl << endl << "User Creation : \n";
	cout << ("Available Users : \n");
	system("cat /etc/passwd | grep 100");
	cout << ("do you want to add users ? (yes or no)\n");
	
	char proced2;
	cin >> proced2;
	if(proced2 == 'y' || proced2 == 'Y'){
		cout << ("Enter username ");
        	string user1 = ("useradd -m -G wheel,audio,video,portage,adm,disk,tty -s /bin/bash ");
       		cin >> user2;
       		user1 = user1 + user2;
		const char *user = user1.c_str();
		system(user);
		//user details
		string uconf = ("chfn ");
		string passwd = ("passwd ");
		uconf = uconf + user2;
		passwd = passwd + user2;
		const char *uconf0 = uconf.c_str();
		const char *upasswd = passwd.c_str();
		system(upasswd);
		system(uconf0);
		//Sudoing the user
		while(true){
			cout << ("Installing sudo \n");
			system("emerge -qvt sudo");
			cout << "\n Press enter to continue"<<endl;
			cin.ignore();
			system("clear");
			int sudo;
			cout << "Choose sudo prompt type : \n"
				<< "1. With password \n"
				<< "2. Without password \n" << endl;
			cin >> sudo;
			if(sudo == 1){
				system("echo %wheel ALL=(ALL) ALL >> /etc/sudoers");
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
		string sudoprompt = ("echo \"Defaults passprompt=\"[sudo] password for %u: \" >> /etc/sudoers");
		const char *prompt = sudoprompt.c_str();
		system(prompt);
		break;

        }else if(proced2 == 'n' || proced2 == 'N'){
		continue;
		
	}else{
                cout << "\nselect only yes or no";
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
		swuser = swuser + user2 + dashc + vim;
		const char *editorvim = swuser.c_str();
		system(editorvim);
		break;
	}else if(editor == '2'){
		string vi = ("\"echo export EDITOR='vi' >> ~/.bashrc \"");
		swuser = swuser + user2 + dashc + vi;
		const char *editorvi = swuser.c_str();
		system(editorvi);
		break;
	}else if(editor == '3'){
		system("emerge -qvt nano");
		string nano = ("\"echo export EDITOR='nano' >> ~/.bashrc \"");
		swuser = swuser + user2 + dashc + nano;
		const char *editornano = swuser.c_str();
		system(editornano);
		break;
	}else if(editor == '4'){ 	
		system("emerge -qvt emacs");
		string emacs = ("\"echo export EDITOR='emacs' >> ~/.bashrc \"");
		swuser = swuser + user2 + dashc + emacs;
		const char *editoremacs = swuser.c_str();
		system(editoremacs);
		break;
	}else {
		cout << "Invalid Choice \n";
		continue;
	}
}//Loop's
//CUSTOM REPOS(OVERLAYS)
	while(true){
	header2();
	presetup();
	cout << "Installing Layman ....\n";
	string layman = ("USE=\"git\" emerge -qv git layman");
	const char *laymanin = layman.c_str();
	system(laymanin);
	string repo;
	header2();
	presetup();
	cout << "Do you want to add a custom repo (overlay) ? \n";
	char proced3;
	cin >> proced3;
	if(proced3 == 'y' || proced3 == 'Y'){
		cout << "Enter Repo\'s Name : ";
		cin >> repo;
		break;
	}else if(proced3 == 'n' || proced3 == 'N'){
		continue;
	}else{
		cout << "\nselect only yes or no !!!! \n";
	}
}//Loop's  */
	return 0;	
}
void header1(){
	cout << "Welcome to the Gentoo Linux Ultimate Post Installer program by Hexagon16\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Requirements : \n -> Gentoo Linux Installation \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Program can be canceled anytime with CTRL+C \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "https://github.com/hexagon16rpm/gupi\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "P.S. This is still an alpha version DON'T run it on a non gentoo system ,\n also it supports only english locale and x86_64 architecture \n more locales and architectures will be supported in the future :) \n"
		<< "-----------------------------------------------------------------------------\n \n \n"<<endl;
}
void header2(){
	system("clear");
	cout << "-----------------------------------------------------------------------------\n           Gentoo Linux Ultimate Post Installer By Hexagon16 \n-----------------------------------------------------------------------------\n \n \n";
}
void presetup(){
	system("clear");
	cout << endl;
	cout << "################ \n## Pre-Setup: ##\n################\n";
}

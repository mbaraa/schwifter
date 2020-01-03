#include<iostream>
#include<string>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
int main () {
	
 	string header = ("-----------------------------------------------------------------------------\n           Gentoo Linux Ultimate Post Installer By Hexagon16 \n-----------------------------------------------------------------------------\n");
	cout << "Welcome to the Gentoo Linux Ultimate Post Installer program by Hexagon16\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Requirements : \n -> Gentoo Linux Installation \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Program can be canceled anytime with CTRL+C \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "https://github.com/hexagon16rpm/gupi\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "P.S. This is still an alpha version DON'T run it on a non gentoo system , also it supports only english locale and x86_64 architecture \n"
		<< "-----------------------------------------------------------------------------\n \n \n"<<endl;
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	cout << header << endl << endl ;

	cout << "Updating Repos....\n";
	system("emerge-webrsync && emerge --sync");
	
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	cout << header << endl << endl ;
	
	char profile1 ,profile2;
	while(true){
	cout << "Select A Profile :\n PS choose init system that matches your installation DON'T select init system other than in your installation or the setup will be corrupted !!!! \n"
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
	system("clear");
	char proced1;
	cout << "your selected profile is : ";
	system("eselect profile show");
	cout << "\n Is that what you selected ? (yes or no)\n";
	cin >> proced1;
	if(proced1 == 'y' || proced1 == 'yes' || proced1 == 'Y'){
		break;
	}else if(proced1 == 'n' || proced1 == 'no' || proced1 == 'N'){
		continue;
	}else{
		cout << "\nselect only yes or no";
	}
}//loop's

	
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	cout << header << endl << endl << "User Creation : \n";
	cout << ("Installing sudo \n");
	system("emerge -qvt sudo");
	
	cout << ("Available Users : \n");
	system("cat /etc/passwd | grep 100");
	cout << ("do you want to add users ? (yes or no)\n");
	

	char proced2;
	cin >> proced2;
	if(proced2 == 'y' || proced2 == 'yes' || proced2 == 'Y'){
		cout << ("Enter username ");
        	string user1 = ("useradd -m -G wheel,audio,video,portage,adm,disk,tty -s /bin/bash ");
       		string user2;
       		cin >> user2;
       		user1 = user1 + user2;
		const char *user = user1.c_str();
		system(user);
		
		string uconf = ("chfn ");
		uconf = uconf + user2;
		const char *uconf0 = uconf.c_str();
		system(uconf0);
		
		string switchuser = ("su ");
		switchuser = switchuser + user2;
		const char *su = switchuser.c_str();
		system(su);

        }else if(proced2 == 'n' || proced2 == 'no' || proced2 == 'N'){
		cout << "Please type your username (if exists) : \n";
		string user;
		cin >> user;
		string switchuser = ("su ");
		switchuser = switchuser + user;
		const char *su = switchuser.c_str();
		system(su);
		
	}else{
                cout << "\nselect only yes or no";
        }
	
	cout << "Select a default editor : \n" ;
	char editor;
	cout << "1.vim \n 2.vi \n 3.nano \n 4.emacs \n";
	cin >> editor;
	switch(editor){
		case'1':
			system("sudo emerge -qvt vim ctags");
			system("echo export EDITOR='vim' >> ~/.bashrc ");
			break;
		case'2':
			system("echo export EDITOR='vi' >> ~/.bashrc ");
			break;
		case'3':
			system("sudo emerge -qvt nano");
			system("echo export EDITOR='nano' >> ~/.bashrc ");
			break;
		case'4': 	
			system("sudo emerge -qvt emacs");
			system("echo export EDITOR='emacs' >> ~/.bashrc ");
			break;
		default:
			cout << "Invalid Choice \n";
	}

	char menu;
	cin >> menu;
        int g=0;
        while (g<1){
            g++;
             switch (menu) {
		case '1': 
			system("mkdir lol ");
                        g--;
			break;
		case '2':
			system("vim lol.txt");
                        g--;
			break;
		}
	}
	return 0;	
}

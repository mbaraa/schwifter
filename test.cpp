#include <iostream>
using namespace std;
int main () {
	cout << "Welcome to the Gentoo GNU/Linux Ultimate Post Install program by Hexagon16\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Requirements : \n -> Gentoo GNU/Linux Installation \n -> Root & ONLY Root User Running the program \n -> Working Internet Connection\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Program can be canceled anytime with CTRL+C \n"
		<< "-----------------------------------------------------------------------------\n"
		<< "https://github.com/hexagon16rpm/gupi\n"
		<< "-----------------------------------------------------------------------------"<<endl;
	system("emerge-webrsync && emerge --sync");
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
		<< "a. openRC\n"
		<< "b. SystemD\n";
		cin >> profile2;
	if(profile1 == '1'){
		cout << "go on \n";
	}else if (profile1 == '2' && profile2 == 'a'){
		system("eselect profile set default/linux/amd64/17.1/desktop");
	}else if (profile1 == '2' && profile2 == 'b'){
		system("eselect profile set default/linux/amd64/17.1/systemd");
	}else if (profile1 == '3' && profile2 == 'a'){
		system("eselect profile set default/linux/amd64/17.1/desktop/gnome ");
	}else if (profile1 == '3' && profile2 == 'b'){
		system("eselect profile set default/linux/amd64/17.1/desktop/gnome/systemd");
	}else if (profile1 == '4' && profile2 == 'a'){
		system("eselect profile set default/linux/amd64/17.1/desktop/plasma");
	}else if (profile1 == '4' && profile2 == 'b'){
		system("eselect profile set default/linux/amd64/17.1/desktop/plasma/systemd");
	}else if (profile1 == '5' && (profile2 == 'a' || profile2 == 'b')){
		system("eselect profile set default/linux/amd64/17.1/no-multilib");
	}else {
		cout << "\nselect only from the menu !!!!\n"
	}
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
}

	






	cout << "##############################"
		<< "##############################"
		<< "##############################"
	        << "\n##                           "
	        << "Gentoo Ultimate Post-Installer:"
	        << "                            ##"
	        << "\n#############################"
	        << "###############################"
	        << "##############################"
		<< "\n###############"
	        << "\n#### Menu: ####\n"
                << "####           "
	        << "\n#### 1) Make Directory \n"
                << "#### 2) Make Text File \n";
	   
	char menu;
	cin >> menu;
        int g=0;
        while (g<1){
            g++;
             switch (menu) {
		case '1': 
			system("mkdir fuck");
                        g--;
			break;
		case '2':
			system("vim fuck.txt");
                        g--;
			break;
		}
	}
	return 0;	
}

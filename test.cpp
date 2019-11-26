#include <iostream>
using namespace std;
int main () {
	
	char menu;
	cin >> menu;
        int g=0;
        while (g<1){
            g++;
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
	   
             switch (menu) {
		case '1': 
			system("mkdir fuck");
			break;
		case '2':
			system("vim fuck.txt");
			break;
		}
	}
	return 0;	
}

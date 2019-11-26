#include <iostream>
using namespace std;
int main () {
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
	switch (menu) {
		case '1': 
			system("mkdir fuck");
			break;
		case '2':
			system("vim fuck.txt");
			break;
		}
	
	return 0;	
}

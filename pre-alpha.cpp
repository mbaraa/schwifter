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
int main () {
	system("clear");	
	header1();
	cout << "\n Press enter to continue"<<endl;
	cin.ignore();
	system("clear");
	header2();
	cout << endl << endl ;

		
};//MAIN FUNCTION'S

//FUNCTIONS
void header1(){
	cout << "Welcome to the Gentoo Linux Ultimate Pre Installer program by Baraa Al-Masri\n"
		<< "-----------------------------------------------------------------------------\n"
		<< "Requirements : \n -> Gentoo Linux Live CD whatever it is \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n -> A lot of time & patience \n"
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
	cout << "-----------------------------------------------------------------------------\n           Gentoo Linux Ultimate Post Installer By Baraa Al-Masri \n-----------------------------------------------------------------------------\n \n \n"<<endl;
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

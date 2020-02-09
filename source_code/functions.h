#include<string>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include"colors.h"
using namespace std;
void header1(){
        cout << WHITE << "Welcome to the Gentoo Linux Schwifter(installer) program by Baraa Al-Masri\n" << RESET
                << "----------------------------------------------------------------------------\n"
                << BOLDBLUE <<  "Requirements : \n -> Gentoo Linux Installation \n -> Root or normal user with sudo running the program \n -> Working Internet Connection\n -> A lot of time(approx. 12 hours) & patience \n -> A barrel of coffee\n"
                << "-----------------------------------------------------------------------------\n"
                << "Program can be canceled anytime with CTRL+C \n"
                << "-----------------------------------------------------------------------------\n"
                << "https://github.com/baraa-almasri/schwifter\n"
                << "-----------------------------------------------------------------------------\n"
                << "P.S. This is still an alpha version DON'T run it on a non gentoo system ,\n also it supports only english locale and x86_64 architecture \n more locales and architectures will be supported in the future :) \n"
                << "-----------------------------------------------------------------------------\n \n \n"<< RESET <<endl;
}
void header2(){
        system("clear");
        cout << MAGENTA << "-----------------------------------------------------------------------------\n           Gentoo Linux Ultimate Post Schwifter By Baraa Al-Masri \n-----------------------------------------------------------------------------"<<endl;
        cout << "-----------------------------------------------------------------------------\n           You gotta get schwifty in here            \n-----------------------------------------------------------------------------"<< RESET <<endl;
}
void presetup(){
        cout << endl;
        cout << GREEN << "################ \n## Pre-Setup: ##\n################\n"<< RESET <<endl;
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
void flatpak(string package){
        string install =("flatpak install flathub -y ");
        install = install + package;
        const char *in = install.c_str();
        system(in);
}
void presskey(){
        cout << YELLOW <<"\n Press enter to continue...."<< RESET <<endl;
        cin.ignore();          
        system("clear");       
}
void basicsetup(){
        cout << endl;
        cout << GREEN << "################ \n# Basic-Setup: #\n################\n"<< RESET <<endl;
}
void dewm(){
        cout << endl;
        cout << GREEN << "################ \n# Desktop Environments | Window Managers: #\n################"<< RESET <<endl;
}
void desktops(){
        cout << RED << "Caution !!!! When Installing KDE make sure that you selected the plasma profile,\n also when installing Gnome make sure that you selected the gnome profile \n the rest can work with any profile . \n\n"
                << RESET << WHITE << "1. KDE Plasma \t|\t7. i3wm\n"
                << "2. Xfce \t|\t8. Openbox\n"
                << "3. LXDE \n"
                << "4. LXQt \n"
                << "5. Mate \n"
                << "6. GNOME \n"
                << "d. Done(go back to main menu)\n" << RESET;

}
void accs(){
        cout << endl;
        cout << GREEN << "################ \n# Accessories Apps: #\n################"<< RESET <<endl;
}
void accessories(){
        cout << WHITE << "1. Albert\n"
                << "2. Kitty \n"
                //<< "3. Conky \n"
                << "3. Cheese \n"
                << "4. Latte Dock \n"
                << "5. Galculator \n"
                << "6. Terminator \n"
                << "d. Done(go back to main menu)\n" << RESET;

}
void unmask(string tounmask){
        string lol1 =("echo \" "), lol2 = (" \" >> /etc/portage/package.use/zz-autounmask ");
        lol1 = lol1 + tounmask + lol2 ;
        const char *exec=lol1.c_str();
        system(exec);
}
void acceptlicnse(string toaccept){
        string lol1 =("echo \" "), lol2 = (" \" >> /etc/portage/package.license ");
        lol1 = lol1 + toaccept + lol2 ;
        const char *exec=lol1.c_str();
        system(exec);
}
void mainmenu(string un){
        cout << WHITE << "################################ \n## Main Menu: ## User : " << un << "\n################################\n";
        cout << "\n\n";
        cout << "1. Basic Setup \n"
                 << "2. Desktop Environments | Window Managers \n"
        	     << "3. Accessories Apps \n"<< RESET;
         /* << "4. Development Apps \n";
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

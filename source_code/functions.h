#include<string>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
using namespace std;
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

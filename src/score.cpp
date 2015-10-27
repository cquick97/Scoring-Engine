#include <iostream>
#include "check.h"
#include "backdoors.h"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void rootLoginSSH(){
    // Check to see if SSH root login is disabled

    if( isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes" ) == false){
        std::cout << success << " SSH Root login has been disabled." << std::endl;
    }
}

int main(){

    backdoorWeb("/var/www/c99.php");
    //isPortOpen("80");
    //isPortOpen("22");
    backdoorPort("/var/www/c99.php", "80");
    //isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes");
    rootLoginSSH();

    return 0;
}

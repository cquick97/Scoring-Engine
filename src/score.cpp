#include <iostream>
#include "check.hpp"
#include "backdoors.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void rootLoginSSH(){
    // Check to see if SSH root login is disabled

    if( isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes" ) == false){
        std::cout << success << " SSH Root login has been disabled." << std::endl;
    }
}

int main(){

    //isPortOpen("80");
    //isPortOpen("22");
    backdoor("/var/www/c99.php", "80");
    backdoor("/home/ubuntu/test.txt");
    //isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes");
    //rootLoginSSH();

    return 0;
}

// serviceConfig.cpp contains functions to check for configuration changes
// in certain services, such as SSH, etc.

#include <iostream>
#include "check.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void rootLoginSSH(){
    // Check to see if SSH root login is disabled

    if( isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes" ) == false){
        std::cout << success << " SSH Root login has been disabled." << std::endl;
    }
}

void sudoersFile(const char *fileName){

    if(isFileExist(fileName) == false){
        std::cout << success << " Insecure sudoers configuration fixed." << std::endl;
    }
}

void sudoersEntry(const char *searchString){

    if( isStringInFile("/etc/sudoers", searchString ) == false){
        std::cout << success << " Insecure sudoers configuration fixed." << std::endl;
    }
}

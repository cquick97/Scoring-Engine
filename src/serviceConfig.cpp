// serviceConfig.cpp contains functions to check for configuration changes
// in certain services, such as SSH, etc.

#include <iostream>
#include "files.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void rootLoginSSH(const char *searchString){
    // Check to see if insecure configuration options are removed
    // in /etc/ssh/sshd_config

    if( isStringInFile("/etc/ssh/sshd_config", searchString ) == false){
        std::cout << success << " \"" << searchString <<
            "\" has been removed from the SSH configuration." << std::endl;
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

// serviceConfig.cpp contains functions to check for configuration changes
// in certain services, such as SSH, etc.

#include <iostream>
#include "files.hpp"
#include "globals.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void rootLoginSSH(const char *searchString){
    // Check to see if insecure configuration options are removed
    // in /etc/ssh/sshd_config

    if( isStringInFile("/etc/ssh/sshd_config", searchString ) == false){
        std::cout << success << " Root SSH login has been disabled." << std::endl;
            total += 10;
    }
}

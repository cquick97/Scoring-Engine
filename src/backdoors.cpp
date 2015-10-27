// backdoors.cpp contains functions to check for _SIMPLE_ backdoors.

#include <iostream>
#include "check.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void backdoorWeb(const char *fileName){
    // If the file doesn't exist, the backdoor file has been removed.

    if( isFileExist(fileName) == false ){
        std::cout << success << " Backdoor at " << fileName << " has been removed." << std::endl;
    }
}

void backdoorPort(const char *fileName, const char *portNumber){
    // Check to see if backdoor is NOT running on port, then check if startup
    // file is removed

    if( isFileExist(fileName) == false && isPortOpen(portNumber) == false){
        std::cout << success << " Backdoor at " << fileName << " running on port " << portNumber << " has been removed." << std::endl;
    }
}


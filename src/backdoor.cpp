// backdoors.cpp contains functions to check for _SIMPLE_ backdoors.

#include <iostream>
#include "networking.hpp"
#include "files.hpp"
#include "globals.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void backdoor(const char *fileName, const char *portNumber = NULL){
    // Checks for backdoors. The port is an optional argument.
    // If it isn't there, just check for file (c99.php for instance)

    if(portNumber == NULL){
        if( isFileExist(fileName) == false ){
            std::cout << success << " Backdoor at " << fileName << " has been removed." << std::endl;
            total += 10;
        }
    }
    else{
        if( isFileExist(fileName) == false && isPortOpen(portNumber) == false){
            std::cout << success << " Backdoor at " << fileName << " running on port " << portNumber << " has been removed." << std::endl;
            total += 10;
        }
    }
}

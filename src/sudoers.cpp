// sudoers.cpp contains functions to check for configuration changes
// in certain the sudoers file.

#include <iostream>
#include "files.hpp"
#include "globals.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void sudoersFile(const char *fileName){
    // This most likely will be looking for a file in /etc/sudoers.d/

    if(isFileExist(fileName) == false){
        std::cout << success << " Insecure sudoers configuration in "
            << fileName << " fixed." << std::endl;
            total += 10;
    }
}

void sudoersEntry(const char *searchString){

    if( isStringInFile("/etc/sudoers", searchString ) == false){
        std::cout << success << " Insecure sudoers configuration in /etc/sudoers fixed."
            << std::endl;
            total += 10;
    }
}

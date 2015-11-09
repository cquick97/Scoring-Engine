#include "backdoor.hpp"
#include "serviceConfig.hpp"
#include "sudoers.hpp"
#include "globals.hpp"

int total = 0;

int main(){

    //isPortOpen("80");
    //isPortOpen("22");
    backdoor("/var/www/c99.php", "80");
    backdoor("/home/ubuntu/test.txt");
    //isStringInFile("/etc/ssh/sshd_config", "PermitRootLogin yes");
    rootLoginSSH("PermitRootLogin yes");
    sudoersFile("/etc/sudoers.d/toor");
    sudoersEntry("toor ALL=(ALL) NOPASSWD:ALL");
    std::cout << "Points: " << total << std::endl;

    return 0;
}

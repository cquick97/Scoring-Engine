#include "backdoor.hpp"
#include "serviceConfig.hpp"
#include "sudoers.hpp"
#include "users.hpp"
#include "globals.hpp"

int total = 0;

int main(){

    backdoor("/var/www/c99.php", "80");
    backdoor("/home/ubuntu/test.txt");
    rootLoginSSH("PermitRootLogin yes");
    sudoersFile("/etc/sudoers.d/toor");
    sudoersEntry("toor ALL=(ALL) NOPASSWD:ALL");
    rogueUser("toor");

    std::cout << "Points: " << total << std::endl;

    return 0;
}

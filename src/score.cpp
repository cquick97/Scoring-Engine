#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>

bool isFileExist(const char *fileName){
    // Check to see if a file exists

    if(boost::filesystem::exists(fileName)){
        return true;
    }

    return false;
}

bool isStringInFile(const char *fileName, const char *searchString){
    // Check to see if a string exists in a file
    // For instance: root ssh login string in /etc/ssh/sshd_config

}

bool isPortOpen(const int *portNumber){
    // Check to see if a port is open

}

void backdoorWeb(const char *fileName){
    // If the file doesn't exist, the backdoor file has been removed.

    if( isFileExist(fileName) == false ){
        std::cout << "Backdoor at " << fileName << " has been removed." << std::endl;
    }
}

void backdoorPort(const int *portNumber){
    // Check to see if backdoor is NOT running on port, then check if startup
    // file is removed

}


int main(){

    backdoorWeb("/var/www/c99.php");

    return 0;
}

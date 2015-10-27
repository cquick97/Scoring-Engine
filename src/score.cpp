#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <boost/filesystem.hpp>

#define success "\e[01;32m[+]\e[00m"
#define error "\e[01;31m[!]\e[00m"


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

bool isPortOpen(const char *portNumber){
    // Check to see if a port is open

    int status;
    struct addrinfo host_info;
    struct addrinfo *host_info_list;

    memset(&host_info, 0, sizeof host_info);

    host_info.ai_family = AF_UNSPEC;
    host_info.ai_socktype = SOCK_STREAM;

    status = getaddrinfo("localhost", portNumber, &host_info, &host_info_list);

    if (status != 0){
        std::cout << "getaddrinfo error" << gai_strerror(status);
    }

    int socketfd;
    socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
            host_info_list->ai_protocol);

    if (socketfd == -1){
        std::cout << "socket error ";
    }

    status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);

    if (status == -1){
        std::cout << success << " Port " << portNumber << " is CLOSED on localhost." << std::endl;
        return false;
    }
    else{
        std::cout << error << " Port " << portNumber << " is OPEN on localhost." << std::endl;
        return true;
    }
}

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


int main(){

    backdoorWeb("/var/www/c99.php");
    isPortOpen("80");
    isPortOpen("22");
    backdoorPort("/var/www/c99.php", "80");

    return 0;
}

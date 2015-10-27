// check.cpp contains functions to check for certain things, such as
// if a file exists, if a string is in a text file, or if a port is open.
// These functions are used in some of the other security specific checks
// such as backdoors and config file options.

#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include <boost/filesystem.hpp>

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

    std::ifstream inFile;
    std::string line;

    inFile.open(fileName);

    size_t pos;
    while(inFile.good())
    {
        getline(inFile,line);
        pos=line.find(searchString);
        if(pos != std::string::npos) // string::npos is returned if string is not found
        {
            //std::cout << success << " \"" << searchString << "\" has been found in " << fileName << std::endl;
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

bool isPortOpen(const char *portNumber){
    // Check to see if a port is open
    // Used the following site as a guide. Changed to say if port
    // is open or not based on connection success or failure.
    // http://codebase.eu/tutorial/linux-socket-programming-c/

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
        //std::cout << success << " Port " << portNumber << " is CLOSED on localhost." << std::endl;
        return false;
    }
    else{
        //std::cout << error << " Port " << portNumber << " is OPEN on localhost." << std::endl;
        return true;
    }
}

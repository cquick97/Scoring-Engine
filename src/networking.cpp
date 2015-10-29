// networking.cpp has functions related to networking, such as checking
// for open ports, and communication to scoring server.


#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>

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

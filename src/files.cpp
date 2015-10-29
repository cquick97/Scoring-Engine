// files.cpp has functions related to files, such as checking if a file
// exists, or if a string is contained within a file.

#include <iostream>
#include <fstream>
#include <string>
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
    while(inFile.good()){
        getline(inFile,line);
        pos=line.find(searchString);
        if(pos != std::string::npos){ // string::npos is returned if string is not found
            //std::cout << success << " \"" << searchString << "\" has been found in " << fileName << std::endl;
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

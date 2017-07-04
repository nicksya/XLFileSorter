//
//  indexer.cpp
//  Indexer
//
//  Created by Mykyta on 29.04.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#include "Utils.hpp"

using namespace std;

void tryFile(std::fstream& stream, std::string& path, std::ios_base::openmode mode) {
    stream.open(path, mode);
    if (!stream.is_open()){
        stream.close();
        std::cout << "Cannot access the file " << path << " !\nTerminating.\n"<< std::endl;
        exit (EXIT_FAILURE);
    }
}

bool fileExists(std::string& filename) {
    ifstream file(filename);
    if ( file ) return true;
    return false;
}

unsigned long long getFileSize(std::string& filePath) {
    unsigned long long length = 0;
    std::ifstream is(filePath, std::ifstream::binary);
    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        length = is.tellg();
        is.close();
        return length;
    }
    std::cout << "Cannot access the file " << filePath << " !\nExiting now\n"<< std::endl;
    exit (EXIT_FAILURE);
};

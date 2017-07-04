//
//  indexer.hpp
//  Indexer
//
//  Created by Mykyta on 29.04.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>

void tryFile(std::fstream& stream, std::string& path, std::ios_base::openmode mode);

bool fileExists(std::string&);

unsigned long long getFileSize(std::string&);

#endif /* utils_hpp */

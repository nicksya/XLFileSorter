//
//  Merger.h
//  Indexer
//
//  Created by Mykyta on 12.05.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#ifndef Merger_h
#define Merger_h

#include <stdio.h>
#include "Record.h"
#include "Globals.h"
#include "Utils.hpp"

void moveFile(std::string& oldPath, std::string& newPath);

void checkAndResolveDupes(Record& result, Record records[], long long& index, long long size);

void mergeArrayWithFile(std::string& mergedFile, std::string& resultFile, Record records[], long long size);

void dumpArrayToFile(std::string& filePath, Record records[], long long size);

void writeOutput(Record records[], long long size);

#endif /* Merger_h */

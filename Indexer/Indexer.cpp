//
//  indexer.cpp
//  Indexer
//
//  Created by Mykyta on 29.04.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#include "Indexer.h"

unsigned long long getEstimatedRecordCount(unsigned long long fileSize) {
    return fileSize / (FIELD_LINE_SIZE + 1);
}

void doIndexing(Record records[], void (*sort)(Record[], long long), unsigned long long arraySize) {
    std::fstream input;
    std::string inputFilePath = INPUT_FILE;
    
    unsigned long long keyIndex   = 1;
    unsigned long long arrayIndex = 0;
    unsigned long long inputFileSize = getFileSize(inputFilePath);
    unsigned long long progressStep = inputFileSize / (FIELD_LINE_SIZE * 100);
    unsigned long long progressTotal = 0;
    unsigned long long recordCount = getEstimatedRecordCount(inputFileSize);
    
    tryFile(input, inputFilePath, std::ios::in);
    
    std::cout << "Reading file: '" << inputFilePath   << "' (file size = "<< inputFileSize << ") and extending with indexes.\n";
    std::cout << std::endl;
    std::cout << "Estimated record count on input : " << recordCount << std::endl;
    std::string line;
    while ( getline(input, line) )
    {
        Record * rec = new Record();
        rec->V = strtoull(line.c_str(), NULL, 10);
        rec->POS = keyIndex;                           //Records numbered starting from 1 as per requirements
        records[arrayIndex] = *rec;
        if (keyIndex > progressTotal) {              //Display progress with dots
            std::cout << '.';
            progressTotal += progressStep;
        }
        keyIndex++;
        arrayIndex++;
        if ( arrayIndex >= arraySize ) {
            std::cout << "Calling sorting routine (partial)." << std::endl;
            sort(records, arrayIndex);
            writeOutput(records, arrayIndex);
            arrayIndex = 0;
        }
    }
    std::cout << std::endl <<"Input file has been completely read." << std::endl;
    std::cout << "Calling sorting routine." << std::endl;
    input.close();
    sort(records, arrayIndex);
    writeOutput(records, arrayIndex);
}

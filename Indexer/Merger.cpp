//
//  Merger.cpp
//  Indexer
//
//  Created by Mykyta on 12.05.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#include "Merger.h"

void moveFile(std::string& oldPath, std::string& newPath) {
    rename(oldPath.c_str(), newPath.c_str());
};

void checkAndResolveDupes(Record& result, Record records[], long long& current, long long size) {
    long long next = current + 1;
    long long resultIdx = current;
    result = records[resultIdx];
        for (; next < size && records[resultIdx].V == records[next].V; next++) {
        //DEBUG
        std::cout << "checkAndResolveDupes::Duplicates found:";
        std::cout << records[resultIdx].V << " " << records[resultIdx].POS << " vs " << records[next].V << " " << records[next].POS;
        //DEBUG
        if ( records[resultIdx].POS > records[next].POS ) {
            result = records[next];
        }
        std::cout << " Picking " << result.V << " " << result.POS << std::endl;
        current++;
    }
}

void getRecord(std::string& line, Record& rec) {
    std::string::size_type sz = 0;
    rec.V = std::stoull(line.c_str(), &sz, 10);
    line = line.substr(sz);
    rec.POS = std::stoull(line.c_str(), &sz, 10);
}

void mergeArrayWithFile(std::string& inputFilePath, std::string& outputFilePath, Record records[], long long size) {
    std::fstream input;
    std::fstream output;
    tryFile(input, inputFilePath, std::ios::in);
    tryFile(output, outputFilePath, std::ios::out);
    std::string line;
    Record fileRec;
    Record result;
    long long i = 0;
    while ( i < size && getline(input, line) )
    {
        getRecord(line, fileRec);                           //getting element from file
        while ( i < size && fileRec.V > records[i].V ) {    //if array element is smaller
            checkAndResolveDupes(result, records, i, size);
            output << result;
            i++;
        }
        if ( i < size && fileRec.V == records[i].V ) {      //if ements are equal
            std::cout << "mergeArrayWithFile::Duplicates found:";
            std::cout << fileRec.V << " " << fileRec.POS << " vs " << records[i].V << " " << records[i].POS;
            std::cout << " Picking " << fileRec.V << " " << fileRec.POS << std::endl;
            checkAndResolveDupes(result, records, i, size);
            output << fileRec;                              //picking one from file
            i++;                                            //and skippig one from array
        } else {
            output << fileRec;                              //if element from file smaller
        }
    }
    while ( getline(input, line) ) {                    //all array elements get inserted
        getRecord(line, fileRec);
        output << fileRec;
    }
    while ( i < size ) {
        if (fileRec.V == records[i].V) {continue;};//if last writter from file equals to currect from array then skip
        checkAndResolveDupes(result, records, i, size);
        output << result;
        i++;
    }
    input.close();
    output.close();
}

void dumpArrayToFile(std::string& filePath, Record records[], long long size) {
    std::fstream output;
    tryFile(output, filePath, std::ios::out);
    Record result;
    for ( long long i = 0; i < size; i++ ) {
        checkAndResolveDupes(result, records, i, size);
        output << result;
    }
    output.close();
};

void writeOutput(Record records[], long long size) {
    std::string outputFilePath = OUTPUT_FILE;
    if ( !fileExists(outputFilePath) ) {
        dumpArrayToFile(outputFilePath, records, size);
        return;
    }
    std::string tempFilePath = TEMP_FILE;
    moveFile(outputFilePath, tempFilePath);
    mergeArrayWithFile(tempFilePath, outputFilePath, records, size);
    remove(tempFilePath.c_str());
};

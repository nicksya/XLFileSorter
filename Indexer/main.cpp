//
//  main.cpp
//  Indexer
//
//  Created by Mykyta on 28.04.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#include "Globals.h"
#include "Indexer.h"
#include "Record.h"
#include <ctime>

unsigned long long arraySize;
void (*sort)(Record[], long long);
bool useRadixSort = false;
time_t start = time(0);

void printParams() {
    std::cout << "Memory has been allocated for " << arraySize << " records. Size in memory: " << sizeof(Record)*arraySize<<" bytes \n";
    std::cout << "Using ";
    std::cout << ( useRadixSort ? "Radix" : "Quick" );
    std::cout << "Sort as ranging algorithm.\n";
}

void init(int argc, const char * argv[]) {
    arraySize = ARRAY_SIZE;
    sort = quickSort;
    std::string params;
    remove(OUTPUT_FILE);
    
    if (argc < 3) return;
    arraySize = strtoull(argv[1], 0, 10);
    if ( (strcmp(argv[2], RADIX_SORT_CONF)) == 0 ) {
        sort = radixSort;
        useRadixSort = true;
    }
}

int main(int argc, const char * argv[]) {
    init(argc, argv);
    printParams();
    
    Record* records = new Record[arraySize];

    doIndexing(records, sort, arraySize);
    
    delete[] records;
    
    std::cout << std::endl << difftime(time(0),start) << " seconds sorting took by chosen algo.\n";
    
    return 0;
}

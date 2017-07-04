//
//  Sorter.hpp
//  Indexer
//
//  Created by Mykyta on 10.05.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#ifndef Sorter_h
#define Sorter_h

#include <stdio.h>
#include "Record.h"

//void sort(Record records[], long long size);
void arrayDump(Record array[], long long size);
void radixSort(Record[], long long);
void quickSort(Record[], long long);

#endif /* Sorter_h */

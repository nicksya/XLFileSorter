//
//  Record.h
//  Indexer
//
//  Created by Mykyta on 04.05.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//
#include <stdio.h>
#include <iostream>

#ifndef Record_h
#define Record_h
#define FIELD_LINE_SIZE 20
#define FIELDS_DELIMETER " "

class Record {
public:
    unsigned long long V;
    unsigned long long POS;
    bool isLess(Record);
};

std::ostream& operator<<(std::ostream& out, const Record& record);

#endif /* Record_h */


//
//  Record.cpp
//  Indexer
//
//  Created by Mykyta on 04.05.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#include "Record.h"

bool Record::isLess(Record another) {
    if (this->V < another.V) {return true;};
    return false;
}

std::ostream& operator<<(std::ostream& out, const Record& record) {
    out << record.V << FIELDS_DELIMETER << record.POS << std::endl;
    return out;
}

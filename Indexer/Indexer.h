//
//  indexer.h
//  Indexer
//
//  Created by Mykyta on 29.04.17.
//  Copyright © 2017 Mykyta Khomenko. All rights reserved.
//

#ifndef indexer_h
#define indexer_h

#include "Record.h"
#include "Globals.h"
#include "Utils.hpp"
#include "Sorter.h"
#include <cstdlib>
#include "Merger.h"

void doIndexing(Record records[], void (*sort)(Record[], long long), unsigned long long);

#endif /* indexer_h */

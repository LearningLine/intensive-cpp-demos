//
//  Item.cpp
//  IntensiveC++
//
//  Created by Bradley Needham on 6/2/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#include "Item.h"
#include <iostream>

namespace Things {
int Item::defaultSize_ = 10;
static int Item_defaultSize = 10;

void printDefaultSize() {
    std::cout << Item_defaultSize << "\n";
}
}
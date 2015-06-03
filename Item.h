//
//  Item.h
//  IntensiveC++
//
//  Created by Bradley Needham on 6/2/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#ifndef __IntensiveC____Item__
#define __IntensiveC____Item__

#include <string>

namespace Things {

struct Item
{
    std::string name_;
    int size_;
    int color_;
    static void resetDefault(int newSize) {
        Item::defaultSize_ = newSize;
    }
    static int getDefaultSize() {
        return defaultSize_;
    }
private:
    static int defaultSize_;
};

void printDefaultSize();

//extern int Item_defaultSize;

}

#endif /* defined(__IntensiveC____Item__) */

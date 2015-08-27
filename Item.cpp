#include "Item.h"

namespace Things {
    Item::Item(int size, int color)
    : size_(size), color_(color)
    {}
    
    int Item::defaultSize_ = 10;
    
    void Item::reset()
    {
        size_ = defaultSize_;
        color_ = 0;
    }
}


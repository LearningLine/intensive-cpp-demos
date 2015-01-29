#ifndef ___8_Scope__Item__
#define ___8_Scope__Item__

class Item
{
    int color_;
    int size_;
    
    static int defaultSize;

public:
    
    static int getDefaultSize() {
        return defaultSize;
    }
    
    void resetSize() {
        size_ = defaultSize;
    }
};

void buy();


#endif /* defined(___8_Scope__Item__) */

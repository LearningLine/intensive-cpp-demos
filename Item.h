#ifndef __Navy20150824__Item__
#define __Navy20150824__Item__

namespace Things {
    class Item
    {
    public:
        Item(int size, int color);
        void reset();
        
        static int defaultSize() {
            return Item::defaultSize_;
        }
        
    private:
        int size_;
        int color_;
        static int defaultSize_;
    };
}
#endif /* defined(__Navy20150824__Item__) */

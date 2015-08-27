#include "Collections.h"


//void Stack::push(char item)
//{
//    set(top_++, item);
//}
//
//char Stack::pop ()
//{
//    return get(--top_);
//}

void Stack::push(char item)
{
    array_.set(top_++, item);
}

char Stack::pop ()
{
    return array_.get(--top_);
}









void Array::set(int i, char item)
{
    elements_[i] = item;
}

char Array::get(int i)
{
    return elements_[i];
}

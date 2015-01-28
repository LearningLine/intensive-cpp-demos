#ifndef _4_DynamicMemory2_Set_h
#define _4_DynamicMemory2_Set_h

#include <iostream>
#include <algorithm>

template<typename T = char>
class Set
{
    T * elements_;
    int size_ = 0;
    int capacity_ = 4;
public:
    Set() {
        elements_ = new T[capacity_];
    }
    Set(Set const & other);
    ~Set() { delete [] elements_; }
    
    Set& operator=(Set other);
    
    void add(T c);
    void print() const;
};

template<typename T>
Set<T>::Set(const Set& other)
{
    capacity_ = other.size_;
    size_ = other.size_;
    
    elements_ = new T[capacity_];
    std::copy(other.elements_, other.elements_ + size_, elements_);
}

//template<typename T>
//Set<T>& Set<T>::operator=(const Set& other)
//{
//    if (&other == this) { return *this; }
//    
//    delete [] elements_;
//    capacity_ = other.capacity_;
//    size_ = other.size_;
//    
//    elements_ = new T[capacity_];
//    std::copy(other.elements_, other.elements_ + size_, elements_);
//    
//    return *this;
//}

template<typename T>
Set<T>& Set<T>::operator=(Set other)
{
    using std::swap;
    
    swap(other.capacity_, capacity_);
    swap(other.size_, size_);
    swap(other.elements_, elements_);
    
    return *this;
}

template<typename T>
void Set<T>::add(T c)
{
    if (!(size_ < capacity_)) {
        capacity_ *= 2;
        T* tmp = new T[capacity_];
        std::copy(elements_, elements_ + size_, tmp);
        delete [] elements_;
        elements_ = tmp;
        return;
    }
    
    for (int i = 0; i < size_; ++i) {
        if (elements_[i] == c) {
            return;
        }
    }
    elements_[size_++] = c;
}

template<typename T>
void Set<T>::print() const
{
    std::cout << "capacity = " << capacity_ << " size = " << size_ << "\n";
    for (int i = 0; i < size_; ++i) {
        std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
}

#endif

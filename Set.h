#ifndef __Navy20150824__Set__
#define __Navy20150824__Set__

#include <iostream>

namespace Other {
    struct Item {};
}

template<typename T>
class Set
{
public:
    Set() { size_ = 0; capacity_ = 4; elements_ = new T[capacity_]; }
    
    Set(Set const& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        elements_ = new T[capacity_];

        std::copy(other.elements_, other.elements_ + size_, elements_);
    }
    
    ~Set() { delete [] elements_; }
    
    
    
    Set& operator=(Set tmp) {
        using std::swap;

        swap(size_, tmp.size_);
        swap(capacity_, tmp.capacity_);
        swap(elements_, tmp.elements_);
        
        return *this;
    }
    
    
    void add(T const & val);
    void print() const;
    
    int size_;
    int capacity_;
    T* elements_;
};

template<typename T>
void Set<T>::print() const {
    for (int i = 0; i < size_; ++i) {
        std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
void Set<T>::add(T const & val)
{
    for (int i = 0; i < size_; ++i) {
        if (elements_[i] == val) {
            return;
        }
    }
    
    if (size_ == capacity_) {
        capacity_ *= 2;
        T * newElements = new T[capacity_];
        
        std::copy(elements_, elements_ + size_, newElements);
        
        delete [] elements_;
        
        elements_ = newElements;
    }
    
    
    elements_[size_++] = val;
}

//
//template<typename T = char, int N = 26>
//class Set
//{
//public:
//    Set() { size_ = 0; }
//    
//    void add(T const & val);
//    void print() const;
//    
//    int size_;
//    T elements_[N];
//};
//
//template<typename T, int N>
//void Set<T, N>::print() const {
//    for (int i = 0; i < size_; ++i) {
//        std::cout << elements_[i] << " ";
//    }
//    std::cout << "\n";
//}
//
//template<typename T, int N>
//void Set<T, N>::add(T const & val)
//{
//    for (int i = 0; i < size_; ++i) {
//        if (elements_[i] == val) {
//            return;
//        }
//    }
//    
//    elements_[size_++] = val;
//}
//
//
//




class SetChar
{
public:
    SetChar() { size_ = 0; }
    
    void add(char val);
    void print() const;
    
    int size_;
    char elements_[100];
};

class SetInt
{
public:
    SetInt() { size_ = 0; }
    
    void add(int val);
    void print() const;
    
    int size_;
    int elements_[100];
};


#endif /* defined(__Navy20150824__Set__) */

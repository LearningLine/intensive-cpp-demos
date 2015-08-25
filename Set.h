#ifndef __Navy20150824__Set__
#define __Navy20150824__Set__

#include <iostream>

template<typename T = char, int N = 26>
class Set
{
public:
    Set() { size_ = 0; }
    
    void add(T const & val);
    void print() const;
    
    int size_;
    T elements_[N];
};

template<typename T, int N>
void Set<T, N>::print() const {
    for (int i = 0; i < size_; ++i) {
        std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
}

template<typename T, int N>
void Set<T, N>::add(T const & val)
{
    for (int i = 0; i < size_; ++i) {
        if (elements_[i] == val) {
            return;
        }
    }
    
    elements_[size_++] = val;
}







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

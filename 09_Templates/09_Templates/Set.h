#ifndef ___9_Templates__Set__
#define ___9_Templates__Set__
#include <iostream>

template<typename T = char, int CAP = 100>
class Set
{
    T elements_[CAP];
    int size_ = 0;
public:
    void add(T c);
    void print() const;
};

template<typename T, int CAP>
void Set<T, CAP>::add(T c)
{
    if (!(size_ < CAP)) {
        return;
    }
    for (int i = 0; i < size_; ++i) {
        if (elements_[i] == c) {
            return;
        }
    }
    elements_[size_++] = c;
}

template<typename T, int CAP>
void Set<T, CAP>::print() const
{
    for (int i = 0; i < size_; ++i) {
        std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
}

#endif /* defined(___9_Templates__Set__) */

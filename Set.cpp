#include "Set.h"
#include <iostream>

void SetChar::print() const {
    for (int i = 0; i < size_; ++i) {
        std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
}

void SetChar::add(char val)
{
    for (int i = 0; i < size_; ++i) {
        if (elements_[i] == val) {
            return;
        }
    }
    
    elements_[size_++] = val;
}

void SetInt::print() const {
    for (int i = 0; i < size_; ++i) {
        std::cout << elements_[i] << " ";
    }
    std::cout << "\n";
}

void SetInt::add(int val)
{
    for (int i = 0; i < size_; ++i) {
        if (elements_[i] == val) {
            return;
        }
    }
    
    elements_[size_++] = val;
}




//
//  Set.h
//  IntensiveC++
//
//  Created by Bradley Needham on 6/1/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#ifndef __IntensiveC____Set__
#define __IntensiveC____Set__

#include <iostream>

template<typename T>
class Set
{
    int size_;
    int capacity_;
    T * elements_;

//    void copy(Set const & other) {
//        capacity_ = other.capacity_;
//        size_ = other.size_;
//        
//        elements_ = new T[capacity_];
//        // copy other.elements_ to elements_
//        std::copy(other.elements_, other.elements_ + size_, elements_);
//    }
public:
    Set(int capacity = 4) {
        capacity_ = capacity;
        size_ = 0;
        if (capacity_ > 0) {
            elements_ = new T[capacity_];
        } else {
            elements_ = nullptr;
        }
    }
    
    Set(Set const & other);
    
    ~Set() {
        delete [] elements_;
    }
    
    Set& operator=(Set tmp) {
        // copy
  //      Set tmp(other);
        
        // swap
        using std::swap;
        
        swap(capacity_, tmp.capacity_);
        swap(size_, tmp.size_);
        swap(elements_, tmp.elements_);
        
        return *this;
      }
    
    void add(T const& val);
    
    void print() const {
        for (int i = 0; i < size_; ++i)  {
            std::cout << elements_[i] << " ";
        }
        std::cout << "\n";
    }
};

template<typename T>
Set<T>::Set(Set<T> const & other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    
    elements_ = new T[capacity_];
    // copy other.elements_ to elements_
    std::copy(other.elements_, other.elements_ + size_, elements_);
}

template<typename T>
void Set<T>::add(const T &val)  {
    auto it = std::find(elements_, elements_ + size_, val);
    if (it != elements_ + size_) {
        return;
    }
    
    if (size_ >= capacity_) {
        // allocate more memory
        capacity_ *= 2;
        T* tmp = new T[capacity_];
        // copy all elements to new memory
        std::copy(elements_, elements_ + size_, tmp);
        // free up old memory
        delete [] elements_;
        // reset elements_ to new memory
        elements_ = tmp;
    }
    
    elements_[size_++] = val;
}

//template<typename T = char, int CAP = 100>
//class Set
//{
//    T elements_[CAP];
//    int size_;
//public:
//    Set() { size_ = 0; }
//    
//    void add(T const& val);
//    
//    void print() const {
//        for (int i = 0; i < size_; ++i)  {
//            std::cout << elements_[i] << " ";
//        }
//        std::cout << "\n";
//    }
//};
//
//template<typename T, int CAP>
//void Set<T, CAP>::add(const T &val)  {
//    auto it = std::find(elements_, elements_ + size_, val);
//    if (it != elements_ + size_) {
//        return;
//    }
//    elements_[size_++] = val;
//}

#endif /* defined(__IntensiveC____Set__) */

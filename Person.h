//
//  Person.h
//  IntensiveC++
//
//  Created by Bradley Needham on 6/1/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#ifndef __IntensiveC____Person__
#define __IntensiveC____Person__

#include <string>
#include <iostream>

struct Person
{
    std::string name;
    int    age;
    
    void birthday() {
        ++age;
        std::cout << "You got a year older.\n";
    }
    
    virtual void print() const {
        std::cout << name << " is " << age << " years young.\n";
    }
};

struct Student : public Person
{
public:
    int id;
    
    virtual void print() const  {
        Person::print();
        std::cout << "Has id of " << id << "\n";
    }
    
protected:
    void computeGPA() { std::cout << "computeGPA\n"; }
};

struct UGrad : public Student
{
    void accessBaseFunctions() {
        computeGPA();
    }
};

struct Employee : public Person
{
    std::string dept;
    double salary;
};
#endif /* defined(__IntensiveC____Person__) */

#ifndef ___0_TypeConversion__Person__
#define ___0_TypeConversion__Person__

#include <string>

struct Person {
    std::string name_;
    int age_;

    Person(std::string name, int age) : name_(name), age_(age)
    {}
    std::string getName() const { return name_; }
    virtual ~Person() = default;
};

struct Student : public Person {
    std::string major_ = "CS";
    int id_ = 24;
    
    using Person::Person;
    
    void changeMajor(std::string newMajor) { major_ = newMajor; }
};

struct Employee : public Person {
    double salary_ = 2400.00;
    
    using Person::Person;
};

#endif /* defined(___0_TypeConversion__Person__) */

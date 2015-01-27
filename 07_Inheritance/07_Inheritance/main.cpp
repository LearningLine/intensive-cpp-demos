#include <iostream>
#include <string>

struct Person {
    virtual void birthday() final { ++age; }
    virtual void print() const {
            std::cout << "Name : " << name << "\n";
            std::cout << "Age : " << age << "\n";
    }
public:
    std::string name;
    int age;
};

struct Student : public Person {
    typedef Person Base;
        
    virtual void print() const override {
        Base::print();
        std::cout << "Id : " << id << "\n";
    }

    int id;
};

struct Employee : public Person {
    std::string dept;
    double salary;
    
    virtual void print() const override {
        Person::print();
        std::cout << "Dept : " << dept << "\n";
        std::cout << "Salary : " << salary << "\n";
    }
};

void process(Person& p)
{
//    p.Person::birthday();
//    p.Person::print();
    p.birthday();
    p.print();
}

int main() {
    
    Student s;
    s.name = "Bradley";
    s.age = 40;
    s.id = 1024;
    //s.Student::print();
    process(s);
//    s.birthday();
//    s.print();
    
    Employee e;
    e.name = "Paul";
    e.age = 35;
    e.dept = "CS";
    e.salary = 2400;
    process(e);

//    process(s);
//    process(e);

    return 0;
}

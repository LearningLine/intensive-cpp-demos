#include <iostream>
#include "Person.h"


struct Rational
{
    int num_, den_;
    Rational(int num = 0, int den = 1) : num_(num), den_(den) {}
    
    operator double() const {
        return num_ / (double)den_;
    }
};

Rational operator+(Rational lhs, Rational rhs)
{// no reduction done
    int ln = lhs.num_ * rhs.den_;
    int rn = rhs.num_ * lhs.den_;
    int d = lhs.den_ * rhs.den_;
    return Rational(ln + rn, d);
}

struct Set
{
    explicit Set(int initialSize) { /* ... */ }
};

void process(Set s)
{
    
}

void process(int x) {}
int main()
{
    Rational r(1,2);
    Rational q(1,8);
    
    Rational x = r + q;
    
//    Rational y = r + 4;
    Rational y = r + Rational(4);
    
    process(10);
    
    double z = y;
    
    std::cout << z << "\n";
    
    std::cout << typeid(y).name() << "\n";
}







//void examine(Person* p)
//{
//    std::cout << p->age_ << "\n";
//}
//
//void newCode(const Person& person)
//{
//    Person* ncp = const_cast<Person*>(&person);
//    examine(ncp);
//}
//
//int main()
//{
//    Person * p = new Employee("Bradley", 25);
//    
////    Student* sp = (Student*)p;
////    Employee* ep = (Employee*)p;
//    
////    Student* sp = dynamic_cast<Student*>(p);
////    Employee* ep = dynamic_cast<Employee*>(p);
//
//    int* ip = (int*)(p);
//    int* ip2 = reinterpret_cast<int*>(p);
//    
////    int* ip3 = static_cast<int*>(p);
//    Student* sp = static_cast<Student*>(p);
//    Employee* ep = static_cast<Employee*>(p);
//    
//    std::cout << ep->salary_ << "\n";
//
//    if (sp != nullptr) { sp->changeMajor("SoSci"); }
//    else { std::cout << "Not a student\n"; }
//    
//    std::cout << ep->salary_ << "\n";
//    
//    try {
//        Student& sr = dynamic_cast<Student&>(*p);
//        sr.changeMajor("SoSci");
//    } catch (std::bad_cast& excp) {
//        std::cout << "Still not a student\n";
//    }
//
//}
//








//struct Rational
//{
//    int num_, den_;
//    Rational(int num, int den) : num_(num), den_(den) {}
//    Rational() : Rational(0, 1) {}
//};
//
//int main() {
//    double a = 0.0;
//    int n = 4;
//    int k = 3;
//    Rational b;
//    char* d;
//    int* p;
//    
//    a = double(n) / k;
//    b = Rational(n, 2);
//    
//    d = (char*)(p);
//    
//    
//    std::cout << a << "\n";
//    return 0;
//}

#include <iostream>

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

class Text
{
    std::string msg;
public:
    Text(std::string m = "") :
    msg(m)
    {
        std::cout << "Text()\n";
    }
    ~Text()
    { std::cout << "~Text()\n"; }};

class Rect
{
    Point p, q;
public:
    Rect(Point lb, Point ub)
    : p(lb), q(ub)
    {
        p = lb; q = ub; std::cout << "Rect()\n";
    }
    ~Rect()
    { std::cout << "~Rect()\n"; }
};

class Graphic
{
    int id;
public:
    virtual void draw() {}
    Graphic(int _id)
    : id(_id)
    {
        std::cout << "Graphic()\n";
    }
    ~Graphic() { std::cout << "~Graphic()\n"; }
};

class Label : public Graphic
{
    Text text_;
    Rect bound_;
public:
    Label() :
    Graphic(42),
    bound_(Point{4,5}, Point{7,9})
    { std::cout << "Label()\n"; }
    ~Label()
    { std::cout << "~Label()\n"; }

};


class Person
{
    std::string name_;
public:
    Person() {std::cout << "default Person\n";}
    Person(std::string name) : name_(name) {}
    Person& operator=(Person const & other) { return *this; }
    Person(Person const& other) { std::cout << "copy Person\n";}
    ~Person() {}
};

//class Student : public Person
//{
//public:
//    Student() = default;
//    Student(Student const & other) : Person(other) {std::cout << "copy Student\n";}
//};

class Student : public Person
{
public:
    Student() = default;
    Student(Student const&) = delete;
    Student& operator=(Student const&) = delete;
    ~Student() = default;
};

class Employee : public Person
{
    int id_ = -1;
public:
    using Person::Person;
    
    Employee(std::string name, int id) : Person(name), id_(id) {}
    
    Employee(int id) : Employee("unknown", id) {}
    
};

//void process(Person per)
//{
//}
//
void process(Student student)
{
}

int main() {
    Employee e;
    
    Person p("Bradley");
    Employee b("Bradley");
    
    
//    Student s;
//    process(s);

//    Person p, b;
    
//  b = p;
    
//    process(p);
    
//    Label l;
//    Text t("hello");
//    Rect r(Point{4,5}, Point{7,9});
    
    
    return 0;
}

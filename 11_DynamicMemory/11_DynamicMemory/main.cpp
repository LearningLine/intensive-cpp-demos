#include <iostream>
#include <string>

struct Person
{
    int tag;
    Person(int x = 0) { tag = x;std::cout << "Person("<< tag <<")\n"; }
    ~Person() { std::cout << "~Person("<<tag<<")\n"; }
    std::string name_;
    int age_;
    void print() const {
        std::cout << "Name : " << name_ << " Age : " << age_;
    }
};

// remember to delete the returned pointer
Person* process()
{
    int x = 9;
    
    int * ip = new int[102400];
    
    delete [] ip;
    
    Person* ptr = new Person;
    
    ptr->name_ = "Bradley";
    ptr->age_ = 25;
    
    return ptr;
}

int main()
{
    Person p(1);
    
    Person * ptr = new (std::nothrow) Person[10];
    
    delete [] ptr;
    
//    Person p;
//    Person * ptr = &p;
//    
//    Person * person = process();
//    std::cout << "Called process to get person\n";
//    person->print();
//    delete person;
//    
//    std::cout << "\n";
//    
//    
    
//    while (true) {
//        process();
//        std::cout << ".";
//        std::cin.get();
//        break;
//    }
}

// Review pointers
//struct Person
//{
//    std::string name_;
//    int age_;
//    void print() const {
//        std::cout << "Name : " << name_ << " Age : " << age_;
//    }
//};
//
//struct Point
//{
//    int x, y;
//};
//
//int main()
//{
//    Person people[5];
//    Person * ptr = people;
//    
//    ++ptr;
//    
//    ptr->name_ = "Bradley";
//    ptr->age_ = 25;
// 
//    auto b = people;
//    auto e = people + 5;
//    while (b != e) {
//        b->print();
//        ++b;
//        std::cout << "\n";
//    }
//
//    std::cout << "Size of Person is " << sizeof(Person) << "\n";
////    Point q;
////    Point * pq = &q;
////    
////    (*pq).x = 4;
////    pq->x = 5;
////    
////    double arr[] { 3,2,562,62,62,2362,2135,};
////    int arrSize = sizeof(arr)/sizeof(*arr);
////    int x = 9;
////    int * p = &x;
////    auto begin = arr;
////    auto end = arr + arrSize;
////    
////    for (int i = 0; i < arrSize; ++i) {
////        std::cout << arr[i] << " ";
////    }
////    std::cout << "\n";
////    
////    while (begin != end) {
////        std::cout << *begin << " ";
////        std::cout << begin << "\n";
////        ++begin;
////    }
////    std::cout << "\n";
//
//}

// Review inheritance and dynamic binding
//class Person
//{
//    std::string name_;
//protected:
//    int age_ = 1;
//public:
//    virtual void birthday() final;
//    void setName(std::string name) { name_ = name; }
//    virtual void print() const {
//        std::cout << "Name : " << name_ << " Age : " << age_;
//    }
//};
//
//void Person::birthday() {
//    ++age_;
//}
//
//struct Student : public Person
//{
//    int id_ = 42;
//    
//    void print() const override {
//        Person::print();
//        std::cout << " Id : " << id_;
//    }
//    
//    int getId() { return id_; }
//};
//
//void process(Person& p)
//{
//    p.setName("Bradley");
//    p.birthday();
//    
//    p.print();
//    std::cout << "\n";
//}
//
//int main() {
//    Student s;
//    
//    process(s);
//    
//    return 0;
//}

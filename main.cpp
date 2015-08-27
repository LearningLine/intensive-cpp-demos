#if 1
#include <iostream>

class Empty
{
    Empty() {}
    Empty(Empty const&) {}
    ~Empty() {}
    Empty& operator=(Empty const&) {return *this;}
};

struct CopyBase
{
    CopyBase() { std::cout << "CopyBase()\n"; }
    CopyBase(CopyBase const&) { std::cout << "CopyBase(copy)\n"; }
};

struct CopySub : public CopyBase
{
    CopySub() { std::cout << "CopySub()\n"; }
    CopySub(CopySub const& other) : CopyBase(other) { std::cout << "CopySub(copy)\n"; }
};




struct Bag
{
    int size_;
    int capacity_;
    int* elements_;
    
    Bag(int size, int initialVal)
    : size_(size), capacity_(size_), elements_(new int[capacity_])
    {
    }
};

Bag b(10, 2);


struct Address
{
    std::string street_;
    std::string city_;
    
    Address() {std::cout << "Address()\n";}
    
    Address(std::string street, std::string city)
    : street_(street), city_(city) {
        std::cout << "Address(street,city)\n";
    }
};
struct Person
{
    std::string name_;
    int age_;
    Person(std::string name, int age) : name_(name), age_(age)
    {
        std::cout << "Person(name, age)\n";
    }

};

struct Customer : public Person
{
    Address address_;
    Customer() : Person("unknown", 25) {
        std::cout << "Customer()\n";
    }
    Customer(Address address) : Person("unknown", 25) {
        address_ = address;
        std::cout << "Customer(address)\n";
    }
    Customer(std::string street, std::string city)
    : address_(street, city),
      Person("unknown", 25)
    {
        std::cout << "Customer(address)\n";
    }
};

void process(CopySub s) {}

int main()
{
   // Customer c("street", "city");
    
    CopySub s;

    process(s);
}



#endif



#if 0
#include <iostream>

class Two
{
public:
    void bar();
};
class One
{
    friend void process();
    
public:
};
void process()  {
    std::cout << "hello\n";
}
int main()
{
    process();
}




#endif



#if 0
#include <iostream>
#include <cmath>

const int SQRT_DOMAIN_ERROR = 13;

double squareroot(double d)
{
    if (d < 0) {
        throw SQRT_DOMAIN_ERROR;
    }
    
    return std::sqrt(d);
}

void process(double d)
{
    try
    {
        double x = squareroot(d);
        std::cout << x << " is the sqrt of " << d << "\n";
    }
    catch (int xcpt)
    {
        if (xcpt == SQRT_DOMAIN_ERROR) {
            std::cout << "Sqrt domain error\n";
        }
    }
}

struct One { int data_; One(int data = 1) { data_ = data; }};
struct Sub : public One
{ int extra_; Sub(int data = 1) { data_ = data; extra_ = 10; }};

struct Two { int data_; Two(int data = 1) { data_ = data; }};

void process(int x) {
    if (x % 2 == 0) {
        throw Sub(4);
    } else if (x % 3 == 0) {
        throw Two(13);
    }
    std::cout << "exited normally\n";
}

void process() {
    try {
        process(4);
    } catch (One& o) {
        std::cout << "One :" << &o << ": data : " << o.data_ << "\n";
        o.data_ *= 5;
        
        throw;
        
    } catch (...) {
        
        throw;
    }
}

void func() {
    try {
        process();
    } catch (Two& t) {
        std::cout << "Two " << t.data_ << "\n";
    } catch (Sub& o) {
        std::cout << "Outer Sub :" << &o << ": data : " << o.data_ << " extra " << o.extra_ << "\n";
    } catch (One& o) {
        std::cout << "Outer One :" << &o << ": data : " << o.data_ <<  "\n";
    }
}
int main()
{
    func();
 
}



#endif





#if 0
#include <iostream>
#include "Set.h"

void process(Set<int> s) {
    
}

int main()
{
    Set<int> s;
    
    for (int i = 0; i < 10; ++i) {
        s.add(i * i);
    }
    
    Set<int> t;
    
    for (int i = 4; i < 10; ++i) {
        t.add(i * i * i);
    }
    
    
    t.print();
    std::cout << "\n";
    s.print();
    
    t = s;
    
    Set<int> & u = s;
    
    t.elements_[4] = 777;
    
    s.print();
    
    s = u;
    s = s;
    
    process(t);
    
    return 0;
}




#endif

#if 0
#include <iostream>
#include <memory>
#include <array>
#include <vector>

struct Point {
    int x, y;
    Point(int X = 0, int Y = 0) { x = X; y = Y; }
    
    Point& operator+=(Point const & other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    Point& operator-=(Point const & other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, Point const & p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

Point operator+(Point const & a, Point const & b) {
    Point tmp(a);
    tmp += b;
    return tmp;
}

Point operator*(int s, Point const & b) {
    return Point(s * b.x, s * b.y);
}

Point operator-(Point const & a, Point const & b) {
    Point tmp(a);
    tmp -= b;
    return tmp;
}

Point operator-(Point const & a) {
    return Point(-a.x, -a.y);
}

int main()
{
    Point p(9,1), q(2,4), t(1,7);
    

    Point z = p + q - t;
    
    Point h = -z;
    std::cout << "The value of h is " << h << "\n";
}


#endif

#if 0
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Character
{
public:
    Character() { ++Character::count;  }
    Character(std::string name, int health)
    : m_name(name), m_health(health) { ++Character::count;  }
    int health() { return m_health; }
    std::string name() { return m_name; }
    virtual void strike(Character& other) {
        //standard hit takes one health point
        other.takeHit(1);
    }
    void takeHit(int hit) {
        m_health-=hit; if (m_health < 0) m_health = 0;
    }
    void displayHealth() {
        cout << m_name
        << " takes a hit. Down to " << m_health
        << " hit points." << endl;
        if (m_health == 0) { cout << m_name << " is dead." << endl;}
    }
    virtual ~Character() { --Character::count; }
    
    static size_t live() {
        return Character::count;
    }
    
private:
    static size_t count;
    std::string m_name;
    int m_health;
};

size_t Character::count = 0;


struct Monster : Character
{
    Monster(std::string name, int health) : Character(name, health) {}
};

struct Human : Character
{
    Human(std::string name, int health) : Character(name, health) {}
};

struct Zombie : public Monster
{
    Zombie(std::string name, int health) : Monster(name, health) {}
};

struct Creeper : Monster
{
    Creeper(std::string name, int health) : Monster(name, health) {}
    virtual void strike(Character& other) {
        // Creepers are unusually strong their hit takes two health points
        other.takeHit(2);
    }
};

std::unique_ptr<Character> spawn()
{
    if (rand() % 2 == 0)
        return std::unique_ptr<Character>(new Zombie("Zombie", rand() % 15 + 2));
    else
        return std::unique_ptr<Character>(new Creeper("Creeper", rand() % 10 + 2));
}

bool battle(std::unique_ptr<Character> hero, int numSpawn)
{
    //battle numSpawn spawn at the same time
    //Character** foes = new Character*[numSpawn];
    auto foes = std::vector<std::unique_ptr<Character>>(numSpawn);
//    auto foes =
//    std::unique_ptr<std::unique_ptr<Character>[]>(new std::unique_ptr<Character>[numSpawn]);
    
    for (int i = 0; i < numSpawn; ++i)
    {
        foes[i] = spawn();
        
    }
    int liveFoes = numSpawn;
    
    do
    {
        
        //pick a random foe to fight
        std::unique_ptr<Character>& foe = foes[rand() % numSpawn];
        
        if (!foe) {
            continue;
        }
        
        
        if (rand() % 2 == 0) {
            hero->strike(*foe);
            foe->displayHealth();
        }
        else {
            foe->strike(*hero);
            hero->displayHealth();
        }
        
        if (foe->health() == 0) {
            foe = nullptr;
            --liveFoes;
        }
        
        if (hero->health() == 0) {
            return false;
        }
    } while (hero->health() != 0 && liveFoes > 0);
    
    return true;
}

int main()
{
    srand(time(0));
    
    if (battle(std::unique_ptr<Character> (new Human("Bradley", 120)), 10)) {
        cout << "Bradley has defeated the spawn!" << endl;
    }
    
    cout << "Number of Character instances still in memory: "
    << Character::live() << endl;
}

#endif

#if 0
#include <iostream>
#include <memory>
#include <array>
#include <vector>

struct Point {
    int x, y;
    Point() {std::cout << "Point()\n";}
    ~Point() {std::cout << "~Point()\n";}
    void print() const { std::cout << "(" << x << "," << y << ")\n"; }
};

struct One {
    One() {std::cout << "One()\n";}
    ~One() {std::cout << "~One()\n";}
};

std::unique_ptr<Point> makePoint()
{
    return std::unique_ptr<Point>(new Point);
}

void process(int x) {
    std::unique_ptr<Point> p = makePoint();
    
 //   std::unique_ptr<Point> p2(p);
    
    if (x % 2 == 0) {
        p->x = 10;
        p->y = 20;
        p->print();
      return;
    }
    
    if (x % 3 == 0) {
        p->x = 30;
        p->y = 70;
        p->print();
        return;
    }
    p->x = 20;
    p->y = 90;
    p->print();
}

int main()
{
//    process(4);
//    process(9);
//    
//    std::unique_ptr<Point[]> a(new Point[5]);
//    
//    std::vector<Point> arr(5);
//    
//    a[0].x = 0;
//    a[0] = Point();
//    
//    arr[0].x = 0;
//    arr[0] = Point();
    
    
    std::shared_ptr<Point> sp1(new Point);
    std::shared_ptr<Point> sp2(sp1);
   
    sp1->x = 10;
    sp2->y = 20;
    sp1->print();
    

}







#endif

#if 0
#include <iostream>
#include <vector>

void process() {
    int* y = new int(5);
    std::cout << y << "\n";
    delete y;
    double* z = new double(5);
 
    std::cout << z << "\n";
    
    delete z;
}

struct MyType {
    MyType() { std::cout << "MyType()\n"; }
    ~MyType() { std::cout << "~MyType()\n"; }
    int data_ = 5;
};

int main()
{
    //process();
    
    MyType * a = new MyType[5];
    
    
    for (int i = 0; i < 5; ++i)
    {
        std::cout << a[i].data_ << " ";
    }
    std::cout << "\n";
    
    delete [] a;
    
}





#endif



#if 0
#include <iostream>
#include <string>

void process(double* a)
{
    while (*a != 0) {
        std::cout << *a << " at " << a << "\n";
        ++a;
    }
    std::cout << "\n";
}

void print(double * a, int size) {
    for (int i = 0; i < size; ++i, ++a) {
        std::cout << *a << " ";
    }
    std::cout << "\n";
}

void print(double * begin, double * end) {
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << "\n";
}

struct Point {
    int x, y;
    
    void scale(int s) {
        this->x *= s;
        this->y *= s;
    }
};

int main()
{
    
    Point q; q.x = 10; q.y = 15;
    
    Point * p = &q;
    
    q.x = 12;
    
    p->x = 15;
    
    std::cout << q.x << "\n";
    
    
//    int x = 7;
//    double y = 0.0;
//    char c = 'a';
//    bool b = true;
//    
//    int*     p = &x;
//    
//    std::cout << x << "\n";
//    std::cout << p << "\n";
//    std::cout << *p << "\n";
//    
//    *p = 13;
//    
//    std::cout << x << "\n";
//    
//    double a[] = {2,3,42,24,12,131,0};
//    
//    process(a);
//
//    int size = sizeof(a)/sizeof(*a);
//    print(a, size);
//    
//    double * end = a + size;
//    print(a, end);
}




#endif



#if 0
#include <iostream>
#include <string>
#include "Set.h"

int main()
{
    Set<> s;
    Set<char, 100> t;
    
    s.add('a');
    s.add('b');
    s.add('z');
    s.add('x');
    s.add('a');
    s.add('z');

    s.print();
    
    Set<int, 100> si;
    
    si.add(2);
    si.add(5);
    si.add(17);
    si.add(3);
    si.add(2);
    si.add(17);
    
    si.print();

//    SetChar s;
//    
//    s.add('a');
//    s.add('b');
//    s.add('z');
//    s.add('x');
//    s.add('a');
//    s.add('z');
//    
//    s.print();
//    
//    SetInt si;
//    
//    si.add(2);
//    si.add(5);
//    si.add(17);
//    si.add(3);
//    si.add(2);
//    si.add(17);
//    
//    si.print();
}


#endif

#if 0
#include <iostream>
#include <string>

struct Person {
    std::string name_; int age_;
    
    virtual void birthday() final {
        ++age_;
    }
    
    virtual void print() const {
        std::cout << name_ << " is " << age_ << " years young.";
    }
};

struct Student :  public Person {
    int id_;
    void print() const override {
        Person::print();
        std::cout << " Id is " << id_;
    }
};

struct Employee : public Person {
    std::string dept_; double salary_;
    
    virtual void print() const override {
        Person::print();
        std::cout << " Dept : " << dept_ << " Salary : " << salary_;
    }
    void promote() {
        salary_ *= 1.1;
    }
};

struct Staff : Employee {
    
};

struct Faculty : Employee {
    bool tenure_ = false;
    
    void print() const {
        Employee::print();
        std::cout << " Has tenure " << std::boolalpha << tenure_;
    }
    
    void promote() {
        salary_ *= 1.2;
        tenure_ = true;
    }
};


void process(Person const & p) {
    p.print();
    std::cout << "\n";
}

int main()
{
    Student s;
    s.name_ = "Bradley";
    s.age_ = 25;
    s.id_ = 1001;
    
    s.birthday();
//    s.print();
//    std::cout << "\n";
    
    
    Staff e;
    e.name_ = "Paul";
    e.age_ = 32;
    e.dept_ = "IS";
    e.salary_ = 1800;
    
    e.promote();
    
   // std::cout << e.salary_ << "\n";
    
    Faculty f;
    f.name_ = "Mike";
    f.age_ = 32;
    f.dept_ = "IS";
    f.salary_ = 1800;
    
    f.promote();
    
    //std::cout << f.salary_ << "\n";
    
    process(s);
    process(e);
    process(f);

}





#endif




#if 0
#include <iostream>
#include "Time.h"

void print(Time const & t) {
    std::cout << t.hours() << ":";
    std::cout << t.minutes() << ":";
    std::cout << t.seconds() << "\n";
}


int main()
{
    Time t, r, s;
    
    t.set(8, 34, 72);
    s.set(4356);
    
    if (t.ticks() > s.ticks()) {
        std::cout << "t is longer\n";
    }

    print(t);
    print(s);
    
    r = add(t, s);
    
    print(r);

    std::cout << t.ticks() << "\n";
    std::cout << s.ticks() << "\n";
    
    
}



#endif







#if 0
#include <iostream>
#include <string>

struct Point {
    int x, y;
};

Point points[100];

struct Position {
    std::string name_ = "NA";
    double price_ = 5.5;
    double shares_ = 100;
    
    Position() {}
    Position(std::string const & name);
    Position(std::string const & name, double price, double shares);
    ~Position() {
        std::cout << "Position destroyed\n";
    }
    
    void buy(double shares);
    
    void sell(double shares) {
        shares_ -= shares;
    }
    
    void setPrice(double price);
    
    double price() const { return price_; }
    double shares() const { return shares_; }
    
    double value() const;
    
    void print() const {
        std::cout << name_ << " : " << price_ << " : " << shares_ << "\n";
    }
    
    void init(std::string const & name, double price, double shares) {
        name_ = name;
        price_ = price;
        shares_ = shares;
    }
};

//void process(Position const& p) {
//    if (p.value() > 1000) {
//        std::cout << "good news!\n";
//    }
//}


Position::Position(std::string const & name) {
    init(name, 0, 0);
    std::cout << "Single arg\n";
}

Position::Position(std::string const & name, double price, double shares) {
    init(name, price, shares);
    std::cout << "Three args\n";

}

void Position::buy(double shares) {
    shares_ += shares;
}

void Position::setPrice(double price) {
    price_ = price;
}

double Position::value() const {
    return price_ * shares_;
}

void process() {
    Position a;
    a.print();
}

void process(Position x) {
    
}

int main() {

    process(Position("APPL"));

    
    Position appl = Position();
    
    auto msft = Position("MSFT");
    Position goog("GOOG", 650, 50);
    
    
    msft.buy(100);
    
    
    msft.setPrice(122);
    
    double msftVal = msft.value();
    
    msft.print();
    goog.print();
    appl.print();
    
    std::cout << "before\n";
    process();
    std::cout << "after\n";
    
}


#endif


#if 0

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Pollen;

const int NCELLS = 20;
const int NBEES  = 10;
const int FSIZE = 11;

const Pollen PATCH_CAPACITY = 9;


template<typename T>
T minimum(T x, T y)
{
    return x < y ? x : y;
}


template<typename T>
T maximum(T x, T y)
{
    return x > y ? x : y;
}


struct Patch
{
    Pollen pollen_;
    int    bees_;
    
    void init();

    void produce()
    {
        if (pollen_ < PATCH_CAPACITY)
        {
            if (rand() % 10 == 0)
                pollen_++;
        }
    }
    
    void print() const
    {
        cout << pollen_;
        
        switch (bees_)
        {
            case 0: cout << ' '; break;
            case 1: cout << '.'; break;
            case 2: cout << ':'; break;
                
            default: cout << '*'; break;
        }
    }
};


void Patch::init()
{
    pollen_ = PATCH_CAPACITY;
    bees_   = 0;
}








struct Field
{
    Patch patch_[FSIZE][FSIZE];


    void init()
    {
        for (int i = 0; i < FSIZE; i++)
        {
            for (int j = 0; j < FSIZE; j++)
            {
                patch_[i][j].init();
            }
        }
    }

    void produce()
    {
        for (int i = 0; i < FSIZE; i++)
        {
            for (int j = 0; j < FSIZE; j++)
            {
                patch_[i][j].produce();
            }
        }
    }
    
    void print() const
    {
        for (int i = 0; i < FSIZE; i++)
        {
            for (int j = 0; j < FSIZE; j++)
            {
                patch_[i][j].print();
                
                cout << ' ';
            }
            
            cout << endl;
        }
    }
};


Field field;












enum BeeState { SEARCHING, GATHERING, RETURNING, DEPOSITING };


struct Bee
{
    BeeState state;
    int      x, y;
    Pollen   pollen;
};


Bee  bees[NBEES];


void init(Bee& bee, int x, int y)
{
    bee.state = SEARCHING;
    bee.x = x;
    bee.y = y;
    bee.pollen = 0;
    
    field.patch_[bee.x][bee.y].bees_++;
}


void work(Bee& bee)
{
    switch (bee.state)
    {
        case SEARCHING:
        {
            cout << "searching with " << bee.pollen << " from (" << bee.x << ", " << bee.y << ")";
            
            field.patch_[bee.x][bee.y].bees_--;
            
            switch (rand() % 4)
            {
                case 0: bee.x = maximum(bee.x - 1, 0); break;
                case 1: bee.y = maximum(bee.y - 1, 0); break;
                case 2: bee.x = minimum(bee.x + 1, FSIZE - 1); break;
                case 3: bee.y = minimum(bee.y + 1, FSIZE - 1); break;
            }
            
            Patch& patch = field.patch_[bee.x][bee.y];
            
            patch.bees_++;
            
            cout << " to (" << bee.x << ", " << bee.y << ")";
            
            if (patch.pollen_ > 0)
            {
                bee.state = GATHERING;
                
                cout << ", commencing to gather";
            }
            
            break;
        }
        case GATHERING:
        {
            Patch& patch = field.patch_[bee.x][bee.y];
            
            cout << "gathering with " << bee.pollen << " at (" << bee.x << ", " << bee.y << ")";
            
            if (patch.pollen_ > 0)
            {
                bee.pollen   += 1;
                patch.pollen_ -= 1;
            }
            else
            {
                bee.state = SEARCHING;
                
                cout << ", recommencing to search";
            }
            
            break;
        }
        case RETURNING:
        {
            break;
        }
        case DEPOSITING:
        {
            break;
        }
    }
    
    cout << endl;
}


int main()
{
    field.init();
    
    for (int i = 0; i < NBEES; i++)
        init(bees[i], FSIZE/2, FSIZE/2);
    
    while (true)
    {
        field.produce();
        
        for (int i = 0; i < NBEES; i++)
        {
            work(bees[i]);
        }
        
        field.print();
        
        cout << endl;
        
        cin.get();
    }
}









#endif



#if 0
#include <iostream>
#include <string>

struct Position {
    std::string name_;
    double price_;
    double shares_;

    void init(std::string const & name);
    
    void buy(double shares);
    
    void sell(double shares) {
        shares_ -= shares;
    }
    
    void setPrice(double price);
    
    double price() const { return price_; }
    double shares() const { return shares_; }
    
    double value() const;
};

void process(Position const& p) {
    if (p.value() > 1000) {
        std::cout << "good news!\n";
    }
}


void Position::init(std::string const & name) {
    name_ = name;
    price_ = 0;
    shares_ = 0;
}

void Position::buy(double shares) {
    shares_ += shares;
}

void Position::setPrice(double price) {
    price_ = price;
}

double Position::value() const {
    return price_ * shares_;
}


int main() {
    Position msft;
    Position goog;
    
    msft.init("MSFT");
    goog.init("GOOG");
    
    
    msft.buy(100);
    
    
    msft.setPrice(122);
    
    double msftVal = msft.value();
}









#endif
#if 0
#include <iostream>
#include <string>

struct Point {
    int x, y;
};

template<typename T>
T maximum(T x, T y) {
    std::cout << "template version\n";
    return x > y ? x : y;
}

Point maximum(Point const & x, Point const & y) {
    std::cout << "Point version\n";
    return x.x > y.x ? x : y;
}

//int maximum(int x, int y) {
//    std::cout << "int version\n";
//    return x > y ? x : y;
//}


int main() {
    int a = 4.1, b = 9.2;
    
    Point p { 2,3 };
    Point q { 4,3 };
    
    std::cout << maximum(a, b) << "\n";
    maximum(p, q);
}







#endif


#if 0
#include <iostream>
#include <string>

using std::string;
using namespace std;

struct Position {
    string name;
    double price;
    double shares;
};

void print(Position const & p) {
    std::cout << "Name : " << p.name
    << " price " << p.price << " shares " << p.shares << "\n";
}

void print(string const & str) {
    size_t size = str.length();
    for (int i = 0; i < size; ++i) {
        cout << str[i];
    }
    std::cout << "\n";
}

int main() {
    string s = "hello";
    string t = s;
    
    t += " there";
    
    print(t);
    
    Position msft;
    msft.name = "Microsoft";
    msft.price = 50;
    msft.shares = 100;
    
    print(msft);
    
   // std::cout << msft.price << "\n";
    
}








#endif


#if 0
#include <iostream>
#include <cstring>

void print(char const str[]) {
    int i = 0;
    while (str[i] != 0) {
        std::cout << str[i++];
    }
    std::cout << "\n";
}

int main() {
    const char s[] = "hello";
    size_t size = sizeof(s)/sizeof(*s);
    std::cout << size << "\n";
    char z[size * 2];
    
    strcpy(z, s);
    
    strcat(z, "hi");
    
    print(z);
}

#endif










#if 0
#include <iostream>

enum Day : uint8_t {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

int main() {
    Day today = MONDAY;
    
    switch (today) {
        case SATURDAY:
        case SUNDAY:
            std::cout << "Enjoy the weekend!\n";
            break;
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
            std::cout << "Another day at work.\n";
            break;
        case FRIDAY:
            std::cout << "Almost the weekend.\n";
            break;
        default:
            break;
    }
  
}










#endif

#if 0
#include <iostream>

void process(const int arr[]) {
    //arr[0] *= arr[0];
    std::cout << "First element is " << arr[0] << "\n";
}

void process(double x) {
    //arr[0] *= arr[0];
    std::cout << "The double is " << x << "\n";
}


int main() {
    int a[] = {3,3,45,2,32,32,3};
    
    int size = sizeof(a)/sizeof(*a);
    
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    process(a);
    process(5.4);
    
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

#endif










#if 0
#include <iostream>
#include "GlobalAccess.h"


int main() {
    std::cout << getFive() << "\n";
    
    getFive() = 6;
    
    std::cout << getFive() << "\n";

}

#endif

#if 0
#include <iostream>

int five = 5;

double average( double & a, double  & b) {
    return (a + b) / 2;
}

void print(std::string s) {
    std::cout << "Printing " << s << "\n";
}

int& getFive() {
    return five;
}

int main() {
    double x = 0.0;
    double z = 4.5, y = 6.7;
    
    std::cout << "z = " << z << "\n y = " << y << "\n";
    x = average(z, y);
    std::cout << "z = " << z << "\n y = " << y << "\n";

    
//    average(3.3, 9.2);
//    
//    std::cout << average(3.3, 9.2) << "\n";
    std::cout << x << "\n";
    
    print("hello");
    
    std::cout << getFive() << "\n";
}

#endif







#if 0
#include <iostream>

int main()
{
    double p;
    
    std::cout << "Percision: ";
    std::cin >> p;
    
    double t = 0;
    int k = 0;
    double piq = 0;
    
    do {
        t = 1.0 / (2 * k + 1);
        
        piq += (k % 2 == 0) ? t : -t;
        
        std::cout << k << ": " << t << "\n";
        ++k;
    } while (t > p)
        ;
    
    std::cout << "After " << k << " terms pi is " << piq * 4 << "\n";
    return 0;
    
}

#endif






#if 0
#include <iostream>

int main() {
//    int x = 5;
//
//    int y = x++;
//    
//    std::cout << x++ << "\n";
//    
//    std::cout << ++x << "\n";
//
//    for (int i = 0; i < x; ++i) {
//        
//    }
    
    int a[] = { 123,25,346,2,32 };
    
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    for (auto v : a) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}


#endif




#if 0
#include <iostream>

int main() {

//    std::cout << "What type? (\nint = 0\n double = 1\n, char = 2\n, bool = 3 )\n ? ";
//    
//    auto type = 4;
//    std::cin >> type;
//
//    switch (type) {
//        case 0:
//            std::cout << "int is " << sizeof(int) << "\n";
//            break;
//        case 1:
//            std::cout << "double is " << sizeof(double) << "\n";
//            break;
//        case 2:
//            std::cout << "char is " << sizeof(char) << "\n";
//            break;
//        case 3:
//            std::cout << "bool is " << sizeof(bool) << "\n";
//            break;
//            
//        default:
//            std::cout << "unknown type" << "\n";
//            break;
//    }
    
    
    //bool done = false;
    
//    while (!done) {
    for (bool done = false; !done; ) {
        std::cout << "What type? (int, double, char, bool) or Quit? ";
        
        std::string theType = "";
        std::cin >> theType;
        
        std::cout << "You entered: " << theType << "\n";
        
        if (theType == "char") {
            std::cout << "char is " << sizeof(char) << "\n";
        } else if (theType == "bool") {
            std::cout << "bool is " << sizeof(bool) << "\n";
        } else if (theType == "Quit") {
            done = true;
        }else {
            std::cout << "unknown type" << "\n";
        }
    }
    
    for (int i = 0; i < 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    
    //    std::cout << "All the sizes.\n";
//    std::cout << "int is " << sizeof(int) << "\n";
//    std::cout << "long is " << sizeof(long) << "\n";
//    std::cout << "unsigned is " << sizeof(unsigned) << "\n";
//    std::cout << "unsigned long is " << sizeof(unsigned long) << "\n";
//    std::cout << "short is " << sizeof(short) << "\n";
//    std::cout << "double is " << sizeof(double) << "\n";
//    std::cout << "float is " << sizeof(float) << "\n";
//    std::cout << "bool is " << sizeof(bool) << "\n";
//    std::cout << "char is " << sizeof(char) << "\n";

}
#endif
#if 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>

template<typename COL>
void print(COL col) {
//    for (int i = 0; i < col.size(); ++i) {
//        std::cout << col[i] << " ";
//    }
//    typedef typename COL::iterator Iter;
//    for (Iter i = col.begin(); i != col.end(); ++i) {

    for (auto i = col.begin(); i != col.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

}

int main()
{
    //    std::vector<int> col {23,245,2,23,42352,3,232,3};
    int a[] =  {23,245,2,23,42352,3,232,3};
    std::list<int> col(a, a + sizeof(a)/sizeof(*a));
    print(col);
    col.push_back(324);
    col.push_back(32);
    print(col);
    
   //std::sort(col.begin(), col.end());
    col.sort();
    print(col);
    
    std::map<std::string, int> m;
    
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 4;
    
    try {
        m.at("three") = 3;
    } catch (std::out_of_range& ex) {
        std::cout << "nothing at three\n";
    }
    
    std::cout << m["three"] << "\n";
}






#endif



#if 0
#include <iostream>
#include <algorithm>


bool isEven(int val) {
    return val % 2 == 0;
}

struct IsMultOf
{
    int mult;
    IsMultOf(int m) : mult(m) {}
    
    bool operator()(int val) {
        return val % mult == 0;
    }
};

template<typename FUNC>
int cif(int* begin, int* end, FUNC fn) {
    int c = 0;
    while (begin != end) {
        if (fn(*begin)) {
            ++c;
        }
        ++begin;
    }
    return c;
}

int main()
{
    int arr[] {23,42,45,2,62,45613,41,34,13,2,41,341,10,3,64,2,725,734,5234,2};
    
    auto c = std::count_if(std::begin(arr), std::end(arr), isEven);
    std::cout << "number of even's is " << c << "\n";

    c = std::count_if(std::begin(arr), std::end(arr), IsMultOf(3));
    std::cout << "number of mults of 3 is " << c << "\n";

    int mult = 7;
    c = std::count_if(std::begin(arr), std::end(arr),
                      
                      [mult](int val) {
                          return val % mult == 0;
                      }
                      
                      );
    
    std::cout << "number of mults of " << mult << " is " << c << "\n";
}







#endif




#if 0
#include <iostream>

struct LCom
{
    double a_, b_, c_;
    
    LCom(double a, double b, double c);
    
    double operator()(double x, double y) const;
};

LCom::LCom(double a, double b, double c) : a_(a), b_(b), c_(c)
{}

double LCom::operator()(double x, double y) const
{
    return a_ * x + b_ * y + c_;
}

double sumSquares(double x, double y)
{
    return x*x + y*y;
}

double add(double x, double y)
{
    return x + y;
}

template<typename BinaryMathFunc>
void combine(double a[], double b[], double c[], int n, BinaryMathFunc fn)
{
    for (int i = 0; i < n; i++)
        c[i] = fn(a[i], b[i]);
}


int main()
{
    LCom lc3(3, 2, 5);
    LCom lc4(4, 3, 7);
    
    double r = lc3.operator()(4.0, 7.0);
    
    r = lc3(4.0, 7.0);
    
    double d[] {3,2,45,235,23,2,234}, e[]{323,3,45,23,23,2,5}, f[7];
    
    combine(d, e, f, 7, sumSquares);
    for (auto val : f) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    combine(d, e, f, 7, lc3);
    for (auto val : f) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

#endif
#if 0

#include <iostream>

struct Door
{
    int id_;
    Door(int id) : id_(id) {}
    void open () { std::cout << "open " << id_ << "\n"; }
    void close() { std::cout << "close " << id_ << "\n"; }
};

typedef void (Door::*DoorAction)();

void apply(Door d[], int n, DoorAction fn)
{
    for (int i = 0; i < n; i++)
        (d[i].*fn)();
    
//    for (Door* dp = d; dp < d + n; dp++)
//        (dp->*fn)();
}

int main()
{
    Door doors[] { 1,2,3,4,5,6,7,8,9,10 };
    
    apply(doors, 10, &Door::open );
    apply(doors, 10, &Door::close);
}











#endif


















#if 0
#include <iostream>

double sumSquares(double x, double y)
{
    return x*x + y*y;
}

double add(double x, double y)
{
    return x + y;
}

typedef double (*BinaryMathFunc)(double x, double y);

void combine(double a[], double b[], double c[], int n, BinaryMathFunc fn)
{
    for (int i = 0; i < n; i++)
        c[i] = fn(a[i], b[i]);
}

int main()
{
    double d[] {3,2,45,235,23,2,234}, e[]{323,3,45,23,23,2,5}, f[7];
    
    combine(d, e, f, 7, sumSquares);
    for (auto val : f) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    combine(d, e, f, 7, add);
    for (auto val : f) {
        std::cout << val << " ";
    }
    std::cout << "\n";

 
}



#endif








#if 0
#include <iostream>

struct Set
{
    char * elements_;
    explicit Set(int capacity) {
        ///...
        elements_ = new char[capacity];
    }
};

struct Rational
{
    int num_, den_;
    Rational(int num) : den_(1) {}
    Rational(int num, int den) : num_(num), den_(den) {}
    
    explicit operator double() const
    {
        return double(num_) / den_;
    }

};

void process(int r)
{
    std::cout << "this is an int\n";
}

void process(Rational r)
{
    std::cout << r.num_ << "/" << r.den_ << "\n";
}

void process(Set s) {
    
}

void doubleFunction(double z){
    
}

int main()
{
    Rational r(1,4);
    
    process(r);
    
    int x = 3;
    
    process(x);
    
    doubleFunction((double)r);
    
    double z = (double)r;
    
    std::cout << z << "\n";
}





#endif






#if 0
#include <iostream>

struct Rational
{
    int num_, den_;
    Rational() : num_(0), den_(1) {}
    Rational(int num, int den) : num_(num), den_(den) {}
};


// type with vtable
// you do not own. 3rd party
struct Person
{
    virtual void birthday() {}
    virtual ~Person() {}
};

struct Student : Person
{
    int id_;
};

struct Employee : Person
{
    double salary_;
    void func() const {}
};

void process(Person* p) {
//    Student* s = static_cast<Student*>(p);
    Student* s = dynamic_cast<Student*>(p);
    
    if (s != nullptr) {
        std::cout << s->id_ << "\n";
    } else {
        std::cout << "Object is not a Student.\n";
    }
}

void process(Person& p) {

    try {
        Student& s = dynamic_cast<Student&>(p);
        std::cout << s.id_ << "\n";
    } catch (std::bad_cast& ex) {
        std::cout << "Object is not a Student.\n";
    }
}

int main()
{
    
    Employee e; e.salary_ = 40000.02345234562346234624360000;

    process(&e);
    process(e);
    
    const Employee* ce = &e;
    {
        ce->func();
    }
    
    Employee* ep = const_cast<Employee*>(ce);
    
    std::cout << typeid(Employee).name() << "\n";
    std::cout << typeid(*ep).name() << "\n";
    std::cout << typeid(ep).name() << "\n";
}



//    int n = 3, k = 7, p = 0;
//    double a, b, c;
//    char * d;
//
//    a = double(n) / k;
////    b = Rational(n, 2) * 5;
//
//    c = ((double)n) / k;
//    d = (char*)p;
//
//    std::cout << a << "\n" << c << "\n";




#endif



#if 0
#include <iostream>

class Array
{
public:
    void set(int i, char item);
    char get(int i);
};

class Stack
{
public:
    void push(char item);
    char pop();
private:
    int top_;
    Array items_;
};

void Stack::push(char item) { items_.set(top_++, item);  }
char Stack::pop ()          { return items_.get(--top_); }


int main()
{
    Stack s;
    
    s.push('a');
    s.push('z');
    
//    s.set(0, 'x');
   
}





#endif






#if 0
#include <iostream>
#include "Item.h"

static int Item_defaultSize = 7;

//using Things::Item;
//using Things::printDefaultSize;

using namespace Things;
using std::cout;

int count = 0;

struct Counter
{
    int count = 10;
    
    void print() {
        std::cout << "Global count : " << ::count << "\n"
        << "Member count : " << count << "\n";
    }
};

// std::count
int main()
{
//    Things::Item a;
    Item a;
    
    cout << Item::getDefaultSize() << "\n";
    cout << Item_defaultSize << "\n";

    if (count < 10) {
        cout << "hello\n";
    }
    printDefaultSize();
    
    Counter c;
    c.print();
}






#endif




#if 0
#include <iostream>
#include <memory>

struct Point
{
    int x, y;
};

struct Shape
{
    Shape() { std::cout << "Shape::Shape\n"; }
    virtual ~Shape() { std::cout << "Shape::~Shape\n"; }
    
    virtual void draw() = 0;
    virtual void scale() { std::cout << "Shape::scale\n"; };
//    virtual void rotate() = 0;
};

struct Circle : public Shape
{
    Circle() { std::cout << "Shape::Circle\n"; }
    ~Circle() { std::cout << "Shape::~Circle\n"; }
    int data;
    void draw() { std::cout << "Circle::draw\n"; }
};

struct Line : public Shape
{
    Line() { std::cout << "Shape::Line\n"; }
    ~Line() { std::cout << "Shape::~Line\n"; }
    void draw() { std::cout << "Line::draw\n"; }
};

struct Rect : public Shape
{
    Rect() { std::cout << "Shape::Rect\n"; }
    ~Rect() { std::cout << "Shape::~Rect\n"; }
    void draw() { std::cout << "Rect::draw\n"; }
    void scale() { std::cout << "Rect::scale\n"; };
};

typedef std::shared_ptr<Shape> ShapePtr;
//typedef Shape* ShapePtr;

void render(ShapePtr* begin, ShapePtr* end) {
    while (begin != end) {
        (*begin)->draw();
        (*begin)->scale();
        ++begin;
    }
}

//void cleanup(ShapePtr* begin, ShapePtr* end) {
//    while (begin != end) {
//        delete *begin;
//        ++begin;
//    }
//}

int main()
{
    std::cout << "sizeof Shape = " << sizeof(Shape) << "\n";
    std::cout << "sizeof Circle = " << sizeof(Circle) << "\n";
    
    ShapePtr shapes[] = {
        ShapePtr(new Rect()),
        ShapePtr(new Circle()),
        ShapePtr(new Line()),
        ShapePtr(new Rect()),
        ShapePtr(new Circle()),
        ShapePtr(new Line())
    };
    
    int size = sizeof(shapes)/sizeof(*shapes);
    render(shapes, shapes + size);
    
//    cleanup(shapes, shapes + size);
}




#endif




#if 0
#include <iostream>

template<typename T>
struct ScopedPtr
{
    T* dataMember;
    
    ScopedPtr(T* data) : dataMember(data){}
    ~ScopedPtr()
    {
        delete dataMember; //free memory
    }
    
    void set(T const & n)
    {
        *dataMember=n;
    }
    
    T const & get()
    {
        return *dataMember;
    }
    
    T& value()
    {
        return *dataMember;
    }
    
    T& operator*()
    {
        return *dataMember;
    }
};

void process() {
    ScopedPtr<int> ip(new int);
    
    ip.set(7);
    std::cout << ip.get() << "\n";
    ip.value() = 11;
    std::cout << ip.value() << "\n";
   *ip = 13;
    std::cout << *ip << "\n";
    // do something with ip
}

struct One
{
    int x;
    void foo() { std::cout << "foo\n"; }
};
int main()
{
    process();
}

#endif


#if 0
#include <iostream>
#include <string>

struct Base
{
    Base() { std::cout << "Base default\n"; }
    Base(Base const & other) { std::cout << "Base copy\n"; }
    
    ~Base() { std::cout << "Base destructor\n"; }
};

struct Sub : Base
{
    Sub() { std::cout << "Sub default\n"; }
    Sub(Sub const & other) : Base(other) { std::cout << "Sub copy\n"; }
    
    ~Sub() { std::cout << "Sub destructor\n"; }
};

struct Point
{
    int x, y;
};

struct Text
{
    Text() {}
    Text(std::string const &s) {}
};

struct Rect
{
    int height;
    Rect() {}
    Rect(Point const &p, Point const &q) {}
    Rect(int h, int w) : height(h) {}
};

struct Graphic
{
    int size;
    Graphic(int s) : size(s) {}
};

struct Label : Graphic
{
    Text text_;
    Rect bound_;
    
    Label() : Graphic(5), text_("hello"), bound_() { }
    Label(Text msg) : Graphic(3), text_("") {}
    Label(int h, int w) :  Graphic(h), bound_(h,w){}
    
    ~Label() {}
};

void process(Sub s) {
    
}

int main()
{
    Sub s;
    
    process(s);
    
//    Text t ("hello");
//    
//    Point p;
//    
//    Label l(4,5);
//    
//    std::cout << l.size << "\n";
    
    
    
}











#endif



#if 0
#include <iostream>

struct Monitor
{
    Monitor() { std::cout << "Monitor()\n"; }
    ~Monitor() { std::cout << "~Monitor()\n"; }
};
struct BaseEx
{
    int data;
    BaseEx(int d = 0) { data = d; }
};

struct SubEx : BaseEx
{
    std::string msg;
    SubEx(int d, std::string m) { data = d; msg = m; }
};

struct OutOfRange
{
    int index; int size;
    std::string msg;
    OutOfRange(int i, int s, std::string m) { index = i; size = s; msg = m; }
};

void process(int x)
{
    std::cout << "start\n";
    Monitor m;
    if (x % 2 == 0) {
        throw OutOfRange(4, 2, "root");
    } else if (x % 3 == 0) {
        throw SubEx(2, "Sub exception thrown");
        //throw BaseEx(3);
    } else if (x % 5 == 0) {
        throw 5;
    }
    std::cout << "end\n";
}

void process()
{
    std::cout << "begin process()\n";
    try {
        std::cout << "call process\n";
        process(3);
        std::cout << "process returned\n";
    } catch (OutOfRange& ex) {
        std::cout << "caught exception\n";
        
        std::cout << ex.index << " : " << ex.size << " : " << ex.msg << "\n";
        ex.msg += " caught and rethrown";
        throw;
    } catch (BaseEx& ex) {
        std::cout << "caught base exception\n";
        
        std::cout << ex.data << "\n";
        std::cout << ((SubEx&)ex).msg << "\n";
        throw;
    } catch (...) {
        std::cout << "caught unknown exception\n";
    }
    std::cout << "exiting process()\n";
}

int main()
{
    try {
        std::cout << "call process\n";
        process();
        std::cout << "process returned\n";
    } catch (OutOfRange& ex) {
        std::cout << "caught exception\n";

        std::cout << ex.index << " : " << ex.size << " : " << ex.msg << "\n";
    } catch (SubEx& ex) {
        std::cout << "caught sub exception\n";
        
        std::cout << ex.data << "\n";
        std::cout << ex.msg << "\n";
    } catch (BaseEx& ex) {
        std::cout << "caught base exception\n";
        
        std::cout << ex.data << "\n";
    }
    
    std::cout << "exiting\n";
    
}














#endif


#if 0
#include <iostream>
#include "Set.h"

void process()
{
    Set<char> s;
    Set<char> t;
    
    for (int i = 0; i < 100; i++)
    {
        s.add(i % 26 + 64);
    }
    
    s.print();
    
    t = s;
    
    for (int i = 0; i < 100; i++)
    {
        t.add(i % 52 + 90);
    }
    
    t.print();
    
    Set<char>& u = s;
    
    s = u;
}

void process(Set<char> set) {
    
}

int main()
{
    //process();
    
    Set<char> s;
    
    for (int i = 0; i < 100; i++)
    {
        s.add(i % 26 + 64);
    }
    
    s.print();
    
    process(s);
    
}











#endif

#if 0
#include <iostream>

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) { x = _x; y = _y; }
};

Point operator+(Point const &p, Point const &q)
{
    Point r;
    
    r.x = p.x + q.x;
    r.y = p.y + q.y;
    
    return r;
}

void print(Point const & p) {
    std::cout << "(" << p.x << ", " << p.y << ")";
}

std::ostream& operator<<(std::ostream& os, Point const & p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    Point p (4,3);
    Point q (2,4);
    
    Point z;
    
    z = operator+(q, p);
    z = q + p;

    std::cout << "z is = to " << z << "\n";
}



#endif



















#if 0
#include <iostream>
#include <memory>

struct One
{
     One(int x = 0) { std::cout << "One(" << x << ")\n"; }
    ~One() { std::cout << "~One()\n"; }
    
    void func() { std::cout << "One::func\n"; }
};

std::shared_ptr<One> createOne() {
    return std::shared_ptr<One>(new One);
}

void process(int size) {
    std::shared_ptr<One> data(new One(size));
    std::shared_ptr<One> another(data);
    
    data->func();
    another->func();
    // forget delete
}

void process(std::shared_ptr<One> p) {
    
}

int main()
{
    // RAII (Resource Acuqisition Is Initialization)
    //process(10);
    //process(12);
    
    std::shared_ptr<One> x = createOne();
    
    
    {
        std::shared_ptr<One> another(x);

        process(x);
        std::cout << "another leaving scope\n";
    }
    std::cout << "x leaving scope\n";

}

#endif










#if 0
#include <iostream>

struct Point
{
    int x, y;
    
    Point() { std::cout << "Point()\n"; }
    ~Point() { std::cout << "~Point()\n"; }
    
    void scale(double by)  {

    }
};

int main()
{
    int x = 10;
    
    int* p = &x;
    
    *p = 12;
    
    std::cout << x << "\n";
    
    Point q;
    
    q.x = 10;
    q.y = 34;
    
    Point* pq = &q;
    
    (*pq).x = 139;
    pq->x = 139;
    
    pq->scale(2.0);
    
    Point * ap = new Point[10];
    
    delete [] ap;
}


#endif






#if 0
#include <iostream>


void print(int arr[], int size) {
    std::cout << "for loop\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template<typename Iter>
void print(Iter begin, Iter end) {
    std::cout << "iterator version\n";
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << "\n";
}

template<typename Iter>
void reversePrint(Iter begin, Iter end) {
    while (begin != end) {
        --end;
        std::cout << *end << " ";
    }
    std::cout << "\n";
}

template<typename Iter>
void printEverOther(Iter begin, Iter end) {
    while (begin < end) {
        std::cout << *begin << " ";
        begin += 2;
    }
    std::cout << "\n";
}

int main()
{
    int a[] = {234,6,2432,52,7,2,23,52,46,42};
    
    int b = 0, e = 10;
    
    print(a, 10);
    print(a, a + 10);
    reversePrint(a, a + 10);
    printEverOther(a, a + 10);
}



#endif










#if 0
#include <iostream>
#include "Set.h"

int main()
{
    Set<> s;
    
    s.add('x');
    s.add('z');
    s.add('q');
    s.add('w');
    
    s.add('z');

    s.print();
    
    Set<int, 10> intSet;
    
    intSet.add(1);
    intSet.add(3);
    intSet.add(4);
    intSet.add(3);
    
    intSet.print();

}


#endif






















#if 0
#include <iostream>
#include <string>
#include "Person.h"
#include "utils.h"



int main()
{
    Student s;
    
    s.id = 42;
    s.name = "Bradley";
    s.age = 25;

//    s.print();
//    s.birthday();
    
//    aYearPasses(s);
    
//    UGrad ug;
//    
//    ug.name = "Mark";
//    ug.age = 19;
//    
//    ug.birthday();
    
  //  ug.computeGPA();
    
    
    Employee e; e.name = "Paul"; e.age = 24;
    
//    aYearPasses(e);

    process(s);
    process(e);
    
    
}

#endif













#if 0
#include <iostream>

class Foo
{
    
};

class Bar
{
public:
    void quux();
};

class TimeSpan
{
    int ticks_;
    
    friend TimeSpan add(TimeSpan a, TimeSpan b);
    friend class Foo;
    friend void Bar::quux();
    
public:
    TimeSpan(int ticks = 0) {
        set(ticks);
    }
    
    void set(int h, int m, int s)
    {
       ticks_ = h * 3600 + m * 60 + s;
    }
    
    void set(int ticks) {
        ticks_ = ticks;
    }
    
    int hours  () const { return ticks_ / 60 / 60; }
    int minutes() const { return ticks_ / 60 % 60; }
    int seconds() const { return ticks_ % 60;      }
    int ticks  () const { return ticks_; }

    void print() const {
        std::cout << hours() << ":" << minutes() << ":" << seconds() << "\n";
    }
};

TimeSpan add(TimeSpan a, TimeSpan b)
{
    TimeSpan c;
    
    c.ticks_ = a.ticks() + b.ticks();
    
    return c;
}


void process(const TimeSpan& time) {
    time.print();
}

int main()
{
    TimeSpan t;
    
    t.set(20, 243, 423);
    
    t.print();
    
    t.set(3600);
    
    t.print();
}


//class TimeSpan
//{
//    int hours_;
//    int minutes_;
//    int seconds_;
//    
//    void normalize()
//    {
//        minutes_ += seconds_ / 60;
//        seconds_ %= 60;
//        
//        hours_ += minutes_ / 60;
//        minutes_ %= 60;
//    }
//    
//public:
//    void set(int h, int m, int s)
//    {
//        hours_   = h;
//        minutes_ = m;
//        seconds_ = s;
//        
//        normalize();
//    }
//    
//    void set(int ticks) {
//        hours_ = 0; minutes_ = 0; seconds_ = ticks;
//        normalize();
//    }
//    
//    void print() {
//        std::cout << hours_ << ":" << minutes_ << ":" << seconds_ << "\n";
//    }
//};

#endif





















#if 0

#include <iostream>

struct One {
    One() { std::cout << "One()\n"; }
    ~One() { std::cout << "~One()\n"; }
};

struct Two
{
    One one;
    Two() { std::cout << "Two()\n"; }
    ~Two() { std::cout << "~Two()\n"; }
};

struct Three
{
    Three(int x = 0) {}
};

void process(int val) {
    
}

void process(const Three& val) {
    
}

struct Point
{
    int x, y;
};

int main()
{
    int tmp = 10;
    process(tmp);
    
    process(int(10));
    
    Three tmp1(10);
    
    process(tmp1);
    
    process(Three(10));
    
    Two two;
    
    Three a[10];
    
}


#endif





















#if 0

#include <iostream>
#include <string>
#include "Position.h"

void print(const Position& p) {
    std::cout << p.name_ << "\n";
    std::cout << p.price_ << "\n";
    std::cout << p.shares_ << "\n";
    std::cout << p.value() << "\n";
}

Position foo;

struct Database
{
    int num;
    double something;
    
    Database(std::string connection) {
        // connect to database resource
        std::cout << "connecting...\n";
    }
    
    Database() {
        // connect to database resource
        std::cout << "connecting...\n";
    }
    
    ~Database() {
        // freeup database resource
        std::cout << "releasing connection...\n";
    }
};

void process() {
    Database db("mysql://");
    
    // do stuff
    
}


int main()
{
    process();
    
    Position msft("MSFT", 322, 10);
    Position goog("GOOG");
    
    Position foo;

    
    Position bar("BAR", 3);
    
    
//    print(msft);
//    print(goog);

    msft.shares_ = 10;
    msft.price_ = 201.0;
    msft.name_ = "MSFT";
    
//    print(msft);
}



//double value(const Position& self) {
//    self.shares_ *= 10;
//    return self.shares_ * self.price_;
//}


//void Position_init(Position& self, std::string const &name, double price, double shares);
//
//void Position_setPrice(Position& self, double price);
//
//void Position_buy (Position& self, double shares);
//void Position_sell(Position& self, double shares);
//
//double Position_value(Position& self);
//












#endif













#if 0
//
//  main.cpp
//  IntensiveC++
//
//  Created by Bradley Needham on 6/1/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#include <iostream>


// only difference is default access modifier

class TimeSpan
{
    int m_hours;
    int m_minutes;
    int m_seconds;
public:
    void set(int hours, int minutes, int seconds);
};

void TimeSpan::set(int hours, int minutes, int seconds) {
    // normalize or error
    m_hours = hours;
    m_minutes = minutes;
    m_seconds = seconds;
}

void process(TimeSpan const & time);

void process(const TimeSpan *       time);
void process(TimeSpan const *       time);
void process(TimeSpan       * const time);
void process(TimeSpan const * const time);

template<typename T>
T maximum(T a, T b)
{
    std::cout << "template version\n";
    return a > b ? a : b;
}

template<typename T1, typename T2>
T2 maximum(T1 a, T2 b)
{
    std::cout << "template two version\n";
    return a > b ? a : b;
}

template<typename T>
void func(T x) {
    
}

void process(int& ref) {
    std::cout << "reference\n";
}

void process(int* ptr) {
    std::cout << "pointer\n";
}

// VS2010
int main() {
    auto x = 10.8;
    func(10.9);
    
    int y = 10;
    int* p = &y;
    
    *p = 20;
    
    process(y);
    process(&y);

    int a[] = {1,2,34,451,32,1,31,31,12,};
    
    for (int val : a) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    std::cout << maximum(10, 15) << std::endl;
    std::cout << maximum(10.3, 1.5) << std::endl;
    std::cout << maximum(10.3, 1) << std::endl;
    
    
    return 0;
}

#endif

#include <iostream>
#include <memory>

struct One
{
    int tag;
    One(int t = 0) { tag=t; std::cout << "One("<<tag<<")\n"; }
    ~One() { std::cout << "~One("<<tag<<")\n"; }
    
    void print() const { std::cout << "this is one"<<tag<<"\n"; }
};

std::unique_ptr<One> process()
{
//    std::auto_ptr<One> ap(new One);
//    std::auto_ptr<int> ip(new int);
    std::unique_ptr<One> ap(new One);
    std::unique_ptr<int> ip(new int);
    
    ap->print();
    
    *ip = 10;
    std::cout << *ip << "\n";
    
    return ap;
}

struct Point
{    int tag;
    Point(int t = 0) { tag=t; std::cout << "Point("<<tag<<")\n"; }
    ~Point() { std::cout << "~Point("<<tag<<")\n"; }
    int x = 0, y = 0;
    
    void print() const { std::cout << "(" << x << ", " << y << ")"; }
    
};
void process(std::auto_ptr<One> ap)
{
    ap->print();
}
void process(std::unique_ptr<One> up)
{
    up->print();
}
void process(std::shared_ptr<One> up)
{
    up->print();
}

int main() {
    std::shared_ptr<One> p(new One);
    
    process(p);
    
    p->print();
//    std::unique_ptr<One> p(new One);
//    
//    process(p);
//    
//    p->print();
//
//    std::unique_ptr<One> p2 = p;

//    std::auto_ptr<One> p(new One);
//    
//    process(p);
//    
//    p->print();

//    std::shared_ptr<One> sp(new One);
//    {
//        std::shared_ptr<One> sp2(sp);
//        std::cout << "leaving sp2 scope\n";
//    }
//    One* op = new One;
//
//    std::shared_ptr<One> sp(op);
//    std::shared_ptr<One> sp2(op);
    
//    One* op = new One;
//    
//    std::unique_ptr<One> up(op);
//    std::unique_ptr<One> up2(op);
    
 
//    std::cout << "before process\n";
//    //auto one = process();
//    std::unique_ptr<One> one = process();
//    std::cout << "after process\n";
//    one->print();
//    
//    std::unique_ptr<Point[]> points(new Point[10]);
//    
//    points[4].x = 10;
//    points[4].y = 40;
//
//    for (int i = 0; i < 10; ++i) {
//        points[i].print();
//    }
//    return 0;
}

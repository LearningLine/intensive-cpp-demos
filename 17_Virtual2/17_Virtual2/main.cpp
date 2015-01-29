#include <iostream>
#include <memory>

struct Shape
{
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

struct Circle : public Shape
{
    virtual void draw() const override { std::cout << "Draw Circle\n"; }
    ~Circle() { std::cout << "~Circle()\n"; }

};

struct Rect : public Shape
{
    virtual void draw() const override { std::cout << "Draw Rect\n"; }
    ~Rect() { std::cout << "~Rect()\n"; }

};

struct Line : public Shape
{
    virtual void draw() const override { std::cout << "Draw Line\n"; }
    ~Line() { std::cout << "~Line()\n"; }

};

struct Elipse : public Shape
{
    virtual void draw() const override { std::cout << "Draw Elipse\n"; }
    ~Elipse() { std::cout << "~Elipse()\n"; }

};

using UPS = std::unique_ptr<Shape>;
//typedef std::unique_ptr<Shape> UPS;

void test();

struct Point
{
    int x, y;
    virtual void draw() { std::cout << "drawing a point\n"; }
    virtual void rotate() { std::cout << "drawing a point\n"; }
    virtual void scale() { std::cout << "drawing a point\n"; }
};

int main() {
    
    //std::cout << sizeof(Point) << "\n";
    
    test();
    
//    auto s = UPS(new Circle());
//    
//    s->draw();
    
    return 0;
}


void render(UPS* begin, UPS* end)
{
    while (begin != end) {
        (*begin)->draw(); ++begin;
    }
}

void test()
{
    UPS shapes[5];
    shapes[4] = UPS(new Rect());
    shapes[1] = UPS(new Elipse());
    shapes[2] = UPS(new Rect());
    shapes[0] = UPS(new Circle());
    shapes[3] = UPS(new Line());
    
    render(shapes, shapes + 5);
}


void print(int * begin, int * end)
{
    while (begin != end) {
        std::cout << *begin << " "; ++begin;
    }
    std::cout << "\n";
}

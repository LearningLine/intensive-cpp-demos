#include <iostream>
#include <memory>

struct Shape
{
    virtual void draw() const final {
        std::cout << "do some prework\n";
        doDraw();
        std::cout << "do some postwork\n";
  //      doCleanUp();
   }
private:
    virtual void doDraw() const = 0;
//    virtual void doCleanUp() const = 0;
};

struct Circle : public Shape
{
    virtual void doDraw() const override {
        std::cout << "do circle work\n";
    }
};

using UP = std::unique_ptr<Shape>;

int main() {
    UP shape( new Circle );
    
    shape->draw();
    
    Circle c;
    c.draw();
    
    return 0;
}

//struct Shape
//{// developer please chain to function first
//    virtual void draw() const {
//        std::cout << "do some prework\n";
//    }
//};
//
//struct Circle : public Shape
//{
//    virtual void draw() const override {
//        std::cout << "do circle work\n";
//        Shape::draw();
//    }
//};

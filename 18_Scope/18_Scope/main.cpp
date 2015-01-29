#include <iostream>
#include <memory>
#include "Item.h"
#include "Airplane/Engine.h"
#include "Auto/Engine.h"


//using namespace Auto;
//using namespace Airplane;
//using Airplane::Engine;
//using Auto::Wheel;

using EN = Airplane::Engine;

int Engine = 10;


struct Position
{
    void buy() {
        ::buy();
    }
};
int main()
{
//    Engine e;
    
    EN e;
    
    Auto::Wheel w;
}

//class Key
//{
//public:
//    enum Type
//    {
//        ALT, CTRL, SHIFT
//    };
//    
//    class Combo
//    { // ...
//    };
//
//    Type code_;
//};
//
//class Paint
//{
//public:
//    typedef int Color;
//    
//    enum class Type
//    {
//        FLAT, GLOSS, SATIN
//    };
//    
//    Type finish_;
//    Color color_;
//};
//
//int main() {
//    Key::Type kt = Key::CTRL;
//    Paint::Type t = Paint::Type::FLAT;
//    
//    Item i;
//    Item i2;
//    
//    i.resetSize();
//    
//    std::unique_ptr<Item> ip(new Item);
//    
// //   Item::defaultSize = 10;
//    
//    std::cout << Item::getDefaultSize() << "\n";
//    std::cout << i.getDefaultSize() << "\n";
//    return 0;
//}

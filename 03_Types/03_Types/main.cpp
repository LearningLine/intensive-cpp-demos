#include <iostream>
#include <string>

//this function comes from template_functions.cpp
void run();

using namespace std::literals;

//typedef int Color;
//const int BLUE = 0;
//const int RED = 1;
//const int GREEN = 2;
enum Type : unsigned char
{
    GLOSS, MAT
};

enum class Color
{
    BLUE = 8, RED, GREEN
};

//typedef int Mood;
//const int ANGRY = 0;
//const int HAPPY = 1;

enum Mood : short
{
    ANGRY, HAPPY, BLUE
};

struct Monster
{
    Color color;
    Mood mood;
};

void print(const Monster& m)
{
//    if (m.color == Color::BLUE) {
//        std::cout << "Blue\n";
//    } else if (m.color == Color::GREEN) {
//        std::cout << "Green\n";
//    } else {
//        std::cout << "Red\n";
//    }
    std::cout << "The monster is ";
    switch (m.color) {
        default:
            std::cout << "Unknown";
            break;
        case Color::BLUE:
            std::cout << "Blue";
            break;
            
        case Color::GREEN:
            std::cout << "Green";
            break;
            
        case Color::RED:
            std::cout << "Red";
            break;
    }
    
    std::cout << " in color and its mood is ";
    switch (m.mood) {
        default:
            std::cout << "Unknown\n";
            break;
        case Mood::ANGRY:
            std::cout << "Angry\n";
            break;
            
        case Mood::HAPPY:
            std::cout << "Happy\n";
            break;
            
        case Mood::BLUE:
            std::cout << "Blue\n";
            break;
    }
}

int main() {

    
    
//    Type t = Type::MAT;
//    unsigned char c = Type::GLOSS;
//    t = c;
//    std::cout << c << "\n";
//    
    Monster mine;
    mine.color = Color::BLUE;
    mine.mood  = Mood::ANGRY;
    std::cout << sizeof(mine) << "\n";
    Monster yours {Color::GREEN, Mood::ANGRY};

    print(mine);
    //    Color myMonstersColor = Color::BLUE;
//    Mood myMonstersMood = Mood::ANGRY;
//    
//    myMonstersColor = HAPPY;
    
    Monster arr[10];

    for (int i = 0; i < 10; ++i) {
        Monster& m = arr[i];
        m.color = Color::BLUE;
        m.mood = Mood::HAPPY;
    }
//
    for (auto& m : arr) {
        m.color = Color::BLUE;
        m.mood = Mood::HAPPY;
    }
    
    for (auto m : arr) {
        print(m);
    }
    
    auto s = std::string("hello");
    
    run();
    
    return 0;
}

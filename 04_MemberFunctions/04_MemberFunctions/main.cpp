#include <iostream>
#include <string>

struct Position
{
    std::string name_ = "";
    double price_ = 0.0;
    double shares_ = 0.0;

    Position() {
    }
    Position(std::string name, double price, double shares);
    Position(std::string name) : Position(name, 0, 0) {}
    void buy(double shares);
    void sell(double shares);
    void setPrice(double price);
    
    double value() const;
};

//void init(Position& p, std::string name, double price, double shares);
//void buy(Position& p, double shares);
//void sell(Position& p, double shares);
//void setPrice(Position& p, double price);
//double value(const Position& p);


void print(const Position& p)
{
    std::cout << "Name : " << p.name_ << "\n";
    std::cout << "Price : " << p.price_ << "\n";
    std::cout << "Shares : " << p.shares_ << "\n";
}

void cheat(const Position& p)
{
    print(p);
    std::cout << p.shares_ * p.price_ << "\n";
    std::cout << p.value() << "\n";
}

void process(int x)
{
    std::cout << x * x << "\n";
}

void process(Position p)
{
    print(p);
}


int main() {
    Position msft("MSFT", 100, 3);
    Position appl("APPL");
    
    Position pos[10];
    
    auto p = Position("MSFT");
    
    //msft.init("MSFT", 100, 3);
    print(msft);
    std::cout << "\n";
    cheat(msft);
    print(msft);
    
    
//    int tmp = 10;
//    process(tmp);
    
    process(int(10.6));
    
//    Position tmp("MSFT");
//    process(tmp);
    
    process(Position("MSFT"));
    
    return 0;
}

Position::Position(std::string name, double price, double shares)
{
    name_ = name;
    shares_ = shares;
    price_ = price;
}

void Position::buy(double shares)
{
    shares_ += shares;
}

void Position::sell(double shares)
{
    shares_ -= shares;
}

void Position::setPrice(double price)
{
    price_ = price;
}

double Position::value() const
{
    return price_ * shares_;
}
//void init(Position& p, std::string name, double price, double shares)
//{
//    p.name = name;
//    p.shares = shares;
//    p.price = price;
//}
//
//void buy(Position& p, double shares)
//{
//    p.shares += shares;
//}
//
//void sell(Position& p, double shares)
//{
//    p.shares -= shares;
//}
//
//void setPrice(Position& p, double price)
//{
//    p.price = price;
//}
//
//double value(const Position& p)
//{
//    return p.price * p.shares;
//}


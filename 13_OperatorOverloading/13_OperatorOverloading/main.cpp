#include <iostream>

struct Point
{
    Point(int _x , int _y ) { x = _x; y = _y; }
    int x, y;

    Point& operator+=(Point p) {
        std::cout << "member operator += \n";
        x += p.x;
        y += p.y;
        return *this;
    }
};

Point operator+(Point p, Point q) {
    std::cout << "operator + \n";
    return Point(p.x + q.x, p.y + q.y);
}

Point operator-(Point p, Point q) {
    std::cout << "binary operator - \n";
    return Point(p.x - q.x, p.y - q.y);
}

Point operator-(Point p) {
    std::cout << "uniary operator - \n";
    return Point(-p.x, -p.y);
}

Point operator*(Point p, Point q) {
    std::cout << "operator * \n";
    return Point(p.x * q.x, p.y * q.y);
}

Point operator*(Point p, int s) {
    std::cout << "Point first operator * \n";
    return Point(p.x * s, p.y * s);
}

Point operator*(int s, Point p) {
    std::cout << "int first operator * \n";
    return p * s;
}

bool operator==(Point p, Point q) {
    std::cout << "operator == \n";
    return p.x == q.x && p.y == q.y;
}

bool operator!=(Point p, Point q) {
    std::cout << "operator == \n";
    return !(p == q);
}

std::ostream& operator<<(std::ostream& os, Point p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point a(4,5), b(7,3);
    
    Point r = operator+(a, b);
    
    r = a + b;
    
    r = a * 3;
    r = 3 * a;

    r = b - a;
    
    r = -a;
    
    r = r + b;
    
    r += b;
    
    Point p(2,3), q(4,5);
    
    if (2*(p + q) - r == -p) {}

    //if (equal(minus(mult(2, add(p, q)), r), minus(p)) {}

    std::cout << "p=" << p << " r=" << r << " q=" << q << "\n";
    return 0;
}

#include <iostream>


template<typename T>
T maximum(T a, T b)
{
    std::cout << "template version\n";
    return a > b ? a : b;
}

//int maximum(int a, int b)
//{
//    std::cout << "int version\n";
//    return a > b ? a : b;
//}

//double maximum(double a, double b)
//{
//    std::cout << "double version\n";
//    return a > b ? a : b;
//}

void run()
{
    auto x = 5; auto y = 7;
    auto w = 17.4; auto u = 9.7;
    
    std::cout << "The max of " << x << " and " << y << " is " << maximum(x, y) << "\n";
    
    std::cout << "The max of " << w << " and " << u << " is " << maximum(w, u) << "\n";
    
    std::cout << "The max of " << w << " and " << y << " is " << maximum(w, y) << "\n";
    
    
}
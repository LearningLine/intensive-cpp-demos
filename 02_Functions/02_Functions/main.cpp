#include <iostream>

int myGlobalVal = 0;

int myfunc(std::string prompt)
{
    myGlobalVal++;
    return 42;
}

int noParamFunc()
{
 //   static int myStatic = 0;
    int myStatic = 0;
    ++myStatic;
    return myStatic;
}

void noReturnValue(const int a[])
{
//    a[2] = 42;
//    a[3] = 42;
    // bad
   // a[42] = 42;
}

void print(const int a[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

inline void defaultArg(int x = 3, int y = 7)
{
    std::cout << "x = " << x << " y = " << y;
}

void changeValue(int& x)
{
    x = 4;
}

int& getGlobal()
{
    return myGlobalVal;
}

int main() {
    
    int num = 10;
    
    std::cout << num << "\n";
    changeValue(num);
    std::cout << num << "\n";
    
    std::cout << getGlobal() << "\n";
    getGlobal() = 10;
    std::cout << getGlobal() << "\n";

    int x[] {3,1,7,2,5,67,37,212,36,23,62,};
    
    noReturnValue(x);
    
    print(x, sizeof(x)/sizeof(*x));
    
    myfunc("hello");
    noParamFunc();
    std::cout << myGlobalVal << "\n";
    
    std::cout << noParamFunc() << "\n";
    std::cout << noParamFunc() << "\n";
    
    defaultArg(4);
    std::cout << "\n";
    defaultArg(4,8);
    std::cout << "\n";

    
    return 0;
}

#if 1
#include <iostream>

class City;

class Highway
{
    City* cities;
};

class City
{
    Highway* highways;
};



int main()
{    
}
#endif












#if 0
#include <iostream>


void print(int arr[], int length)
{
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void print(int* begin, int* end)
{
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << "\n";
}

int main()
{
    int data[] {1,2,3,5,7,13,17,23};
    int* ptr = data;
    
    print(data, sizeof(data)/sizeof(*data));
    
    print(data, data + 8);
    
    data[2] = 42;
    
    print(data, data + 8);
    
    ptr += 2;
    *ptr = 67;
    
    print(data, data + 8);
}

#endif















#if 0

#include <iostream>

//class Person
//{
//    int age_ = 25;
//public:
//    void birthday(Person * const this) {
//        Person you;
//        this = &you;
//        this->age_++;
//    }
//    void print(const Person * const this) const {
//        std::cout << this->age_++ << "\n";
//    }
//};

struct Point
{
    int x, y;
};

int main() {
    Point point {2,4};
    
    Point* ptr = &point;
    
    (*ptr).x = 10;
    ptr->x = 10;
    
    int x = 7;
    int y = 17;
    
    int* p = &x;

    std::cout << *p << "\n";
    
    *p = 13;
    std::cout << x << "\n";
    
    
    const int *       cip  = &x;
    int const *       icp  = &x;
          int * const ipc  = &x;
    const int * const cipc = &x;

//    cipc = &y; // error
//    *cipc = 17;// error
//    ipc = &y;  // error
//    *ipc = 13; // ok
//
//    *cip = 5;  // error
//    *icp = 5;  // error
//    cip = &y;  // ok
    
    

    return 0;
}

#endif

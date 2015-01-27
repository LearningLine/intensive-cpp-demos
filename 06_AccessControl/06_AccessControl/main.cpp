#include <iostream>
#include "TimeSpan.h"

void print(const TimeSpan& t)
{
    std::cout << "Hours: " << t.hours()
            << " Minutes: " << t.minutes()
            << " Seconds: " << t.seconds()
            << " Ticks = " << t.ticks()
      << "\n";
    
}

int main() {
    TimeSpan t1;
    t1.set(3, 24, 72);
    print(t1);
    
    TimeSpan t2(3661);
    print(t2);
    
    if (t1.ticks() > t2.ticks()) {
        std::cout << "T1 is bigger\n";
    }
    
    TimeSpan both = add(t1, t2);
    //TimeSpan both = t1 + t2;
    
    print(both);
    
    return 0;
}

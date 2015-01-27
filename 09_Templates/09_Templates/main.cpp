#include <iostream>
#include "Set.h"


int main() {
    Set<> mySet;
    
    mySet.add('a');
    mySet.add('b');
    mySet.add('z');
    mySet.add('x');
    mySet.add('x');
    mySet.add('a');
    
    mySet.print();
    
    Set<int, 2> s2;
    
    s2.add(1);
    s2.add(2);
    s2.add(5);
    s2.add(3);
    s2.add(7);
    s2.add(2);
    
    s2.print();

    
    return 0;
}

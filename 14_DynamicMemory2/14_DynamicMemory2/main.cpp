#include <iostream>
#include "Set.h"

void process(Set<char> set)
{
    
}

int main() {
    Set<char> s;
    
    s.add('a');
    s.add('b');
    s.add('c');
    s.add('d');
    s.add('e');
    s.add('z');
    s.add('x');
    s.add('j');
    s.add('d');
    s.add('i');
    s.add('h');

    s.print();
    
    Set<char>& t = s;
    
    t = s;

    process(t);
    
    return 0;
}

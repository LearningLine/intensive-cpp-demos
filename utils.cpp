//
//  utils.cpp
//  IntensiveC++
//
//  Created by Bradley Needham on 6/1/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#include "utils.h"
#include "Person.h"

void process(const Person& p) {
    p.print();
}

void aYearPasses(Person& p) {
    p.birthday();
}

//
//  Position.h
//  IntensiveC++
//
//  Created by Bradley Needham on 6/1/15.
//  Copyright (c) 2015 DevelopMentor. All rights reserved.
//

#ifndef __IntensiveC____Position__
#define __IntensiveC____Position__

#include <string>
#include <iostream>

struct Position
{
    std::string name_ = "";
    double price_ = 0.0;
    double shares_ = 0.0;
    
    Position(std::string name, double price, double shares = 0.0) {
        name_ = name; price_ = price; shares_ = shares;
        std::cout << "Position(" << name << ", " << price_ << ", " << shares_ << ")\n";
    }
    
    Position(std::string name) : Position(name, 0, 0) { std::cout << "Position(" << name << ")\n"; }
    
    Position() { std::cout << "Position()\n"; }

    void   setPrice(double price ) { price_ = price;    }
    void   buy     (double shares) { shares_ += shares; }
    
    void   sell    (double shares);
    
    double value() const { return shares_ * price_; }
};


#endif /* defined(__IntensiveC____Position__) */

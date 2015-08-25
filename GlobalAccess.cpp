#include "GlobalAccess.h"

int five = 5;


int& getFive() {
    return five;
}
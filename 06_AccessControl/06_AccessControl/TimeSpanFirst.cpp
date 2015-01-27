#include "TimeSpan.h"

void TimeSpan::set(int hours, int minutes, int seconds)
{
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
    
    normalize();
}

void TimeSpan::set(int ticks)
{
    hours_ = 0;
    minutes_ = 0;
    seconds_ = ticks;
    
    normalize();
}

void TimeSpan::normalize()
{
    minutes_ += seconds_ / 60;
    seconds_ %= 60;
    
    hours_ += minutes_ / 60;
    minutes_ %= 60;
}
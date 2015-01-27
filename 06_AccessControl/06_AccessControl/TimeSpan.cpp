#include "TimeSpan.h"

void TimeSpan::set(int hours, int minutes, int seconds)
{
    ticks_ = hours * 3600 + minutes * 60 + seconds;
}

void TimeSpan::set(int ticks)
{
    ticks_ = ticks;
}

//TimeSpan operator+(TimeSpan lhs, TimeSpan rhs)
TimeSpan add(TimeSpan lhs, TimeSpan rhs)
{
    return TimeSpan(lhs.ticks_ + rhs.ticks_);
}
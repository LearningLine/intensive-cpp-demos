#ifndef ___6_AccessControl__TimeSpan__
#define ___6_AccessControl__TimeSpan__

class TimeSpan
{
public:
    TimeSpan(int hours, int minutes, int seconds) {
        set(hours, minutes, seconds);
    }
    
    TimeSpan(int ticks = 0) {
        set(ticks);
    }
    
    void set(int hours, int minutes, int seconds);
    void set(int ticks);
    
    int hours() const { return ticks_ / 3600; }
    int minutes() const { return ticks_ % 3600 / 60; }
    int seconds() const { return ticks_ % 60; }
    int ticks() const {
        return ticks_;
    }
    
    //friend TimeSpan operator+(TimeSpan lhs, TimeSpan rhs);
    friend TimeSpan add(TimeSpan lhs, TimeSpan rhs);

private:

     int ticks_ = 0;
};

//Hours: 3 Minutes: 25 Seconds: 12 Ticks = 12312
//Hours: 1 Minutes: 1 Seconds: 1 Ticks = 3661
//T1 is bigger
//Hours: 4 Minutes: 26 Seconds: 13 Ticks = 15973

#endif /* defined(___6_AccessControl__TimeSpan__) */

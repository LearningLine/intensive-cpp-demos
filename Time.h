#ifndef __Navy20150824__TimeSpan__
#define __Navy20150824__TimeSpan__

class Time
{
public:
    Time(int ticks = 0) {
        set(ticks);
    }
    
    Time(int hours, int minutes, int seconds) {
        set(hours, minutes, seconds);
    }
    
    void set(int ticks) {
        ticks_ = ticks;
    }
    
    void set(int hours, int minutes, int seconds) {
        ticks_ = hours * 3600 + minutes * 60 + seconds;
    }
    
    int hours() const { return ticks_ / 3600; }
    int minutes() const { return ticks_ / 60 % 60  ; }
    int seconds() const { return ticks_ % 60; }
    //int ticks() const { return hours_ * 3600 + minutes_ * 60 + seconds_; }
    int ticks() const { return ticks_; }

private:
    //int hours_, minutes_, seconds_;
    int ticks_;
    void normalize();
    
    friend Time add(Time const& a, Time const& b);
}; // struct Time

Time add(Time const& a, Time const& b);

#endif /* defined(__Navy20150824__TimeSpan__) */

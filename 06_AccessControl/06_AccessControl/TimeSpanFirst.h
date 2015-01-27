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
    
    int hours() const { return hours_; }
    int minutes() const { return minutes_; }
    int seconds() const { return seconds_; }
    int ticks() const {
        return hours_ * 3600 + minutes_ * 60 + seconds_;
    }
private:
    void normalize();
    
    int hours_ = 0;
    int minutes_ = 0;
    int seconds_ = 0;
};


#endif /* defined(___6_AccessControl__TimeSpan__) */

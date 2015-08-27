#ifndef __Navy20150824__Collections__
#define __Navy20150824__Collections__

class Array
{
public:
    void set(int i, char item);
    char get(int i);
private:
    char elements_[100];
};

//class Stack : private Array
//{
//public:
//    void push(char item);
//    char pop();
//private:
//    int top_;
//};

class Stack
{
public:
    void push(char item);
    char pop();
private:
    int top_;
    Array array_;
};


#endif /* defined(__Navy20150824__Collections__) */

#ifndef INC_2_1TIMECOUNTER_TIME_H
#define INC_2_1TIMECOUNTER_TIME_H
#include <iostream>
using namespace std;
class Time {
public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }
    Time(int a, int b, int c) {
        hour = a;
        minute = b;
        second = c;
    }
    friend ostream &operator<<(ostream &in, Time &t);
    friend istream &operator>>(istream &out, Time &t);
    Time operator+(Time a);
    Time operator-(Time a);
    Time &operator++();
    //前置
    Time operator++(int);
    //后置
    Time &operator--();
    //前置
    Time operator--(int);
    //后置
    void deal();
protected:
    int hour, minute, second;
};
#endif //INC_2_1TIMECOUNTER_TIME_H

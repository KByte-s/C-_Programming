#include "Time.h"
ostream &operator<<(ostream &out, Time &t) {
    out << t.hour << ":" << t.minute << ":" << t.second << endl;
}
istream &operator>>(istream &in, Time &t) {
    in >> t.hour >> t.minute >> t.second;
    t.deal();
}
Time Time::operator+(Time a) {
    Time temp;
    temp.hour = this->hour + a.hour;
    temp.minute = this->minute + a.minute;
    temp.second = this->second + a.second;
    temp.deal();
    return temp;
}
Time Time::operator-(Time a) {
    Time temp;
    temp.hour = this->hour - a.hour;
    temp.minute = this->minute - a.minute;
    temp.second = this->second - a.second;
    temp.deal();
    return temp;
}
Time &Time::operator++() {
    this->second++;
    this->deal();
    return *this;
}
Time Time::operator++(int) {
    Time temp(*this);
    this->second++;
    this->deal();
    return temp;
}
Time &Time::operator--() {
    this->second--;
    this->deal();
    return *this;
}
Time Time::operator--(int) {
    Time temp(*this);
    this->second--;
    this->deal();
    return temp;
}
void Time::deal() {
    if (second >= 60) {
        minute += second / 60;
        second -= 60;
    } else if (second < 0) {
        minute--;
        second += 60;
    }
    if (minute >= 60) {
        hour += minute / 60;
        minute -= 60;
    } else if (minute < 0) {
        hour--;
        minute += 60;
    }
    if (hour >= 24) {
        hour -= 24;
    } else if (hour < 0) {
        hour += 24;
    }
}
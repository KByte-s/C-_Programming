#include <iostream>
#include "Time.h"
using namespace std;
int main() {
    Time t1, t2, t3;
    cout << "t1:";
    cin >> t1;
    cout << t1;
    cout << "t2:";
    cin >> t2;
    t3 = t1 + t2;
    cout << "t1+t2=" << t3;
    t3 = t1 - t2;
    cout << "t1-t2=" << t3;
    t3 = ++t1;
    cout << "++t1:" << t3;
    t3 = --t1;
    cout << "--t1:" << t3;
    t3 = t2++;
    cout << "t2++:" << t3;
    t3 = t2--;
    cout << "t2--:" << t3;
    system("pause");
    return 0;
}
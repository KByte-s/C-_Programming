#ifndef INC_3_1ROUND_POINT_H
#define INC_3_1ROUND_POINT_H
#include <iostream>
#include <cmath>
using namespace std;
class Point {
public:
    Point() {
        x = 0;
        y = 0;
    }
    virtual void in();
    int x, y;
};
#endif //INC_3_1ROUND_POINT_H

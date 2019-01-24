#ifndef INC_3_1ROUND_ROUND_H
#define INC_3_1ROUND_ROUND_H
#include "Point.h"
class Round : public Point {
public:
    Round() {
        x = 0;
        y = 0;
        r = 0;
    }
    void in();
    friend int point_round(Point p1, Round r1);//圆与点的位置关系
    int r;
};
#endif //INC_3_1ROUND_ROUND_H

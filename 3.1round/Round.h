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
    friend int point_round(Point p1, Round r1);//Բ����λ�ù�ϵ
    int r;
};
#endif //INC_3_1ROUND_ROUND_H

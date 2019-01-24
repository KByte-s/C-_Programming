#ifndef INC_3_1ROUND_LINE_H
#define INC_3_1ROUND_LINE_H
#include "Round.h"
class Line {
public:
    Line() {
        p1.x = 0;
        p1.y = 0;
        p2.x = 0;
        p2.y = 0;
    }
    void in();
    friend int line_round(Line l1, Round r1);
    Point p1, p2;
};
#endif //INC_3_1ROUND_LINE_H

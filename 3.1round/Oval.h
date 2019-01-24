#ifndef INC_3_1ROUND_OVAL_H
#define INC_3_1ROUND_OVAL_H
#include "Point.h"
class Oval : public Point {
public:
    Oval() {
        a = 0;
        b = 0;
        c = 0;
    }
    void in();
    bool point_oval();
    int type = 0; //默认长轴比短轴长
    double a, b, c;
};
#endif //INC_3_1ROUND_OVAL_H

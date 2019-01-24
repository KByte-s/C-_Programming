#ifndef INC_3_1ROUND_TRIANGLE_H
#define INC_3_1ROUND_TRIANGLE_H
#include "Line.h"
#include "Round.h"
class Triangle {
public:
    void in();
    Line line1, line2, line3;
    Round round1;
    bool triangle_round();
};
#endif //INC_3_1ROUND_TRIANGLE_H

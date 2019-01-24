#include "Round.h"
void Round::in() {
    cout << "圆心坐标与半径:";
    cin >> x >> y >> r;
}
int point_round(Point p1, Round r1) {
    int d = (p1.x - r1.x) * (p1.x - r1.x) + (p1.y - r1.y) * (p1.y - r1.y);
    if (r1.r * r1.r > d) return 1;//点A在圆内
    else if (r1.r * r1.r == d) return 2;//点在圆上
    else return 0;//点A在圆外
}
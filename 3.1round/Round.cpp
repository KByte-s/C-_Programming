#include "Round.h"
void Round::in() {
    cout << "Բ��������뾶:";
    cin >> x >> y >> r;
}
int point_round(Point p1, Round r1) {
    int d = (p1.x - r1.x) * (p1.x - r1.x) + (p1.y - r1.y) * (p1.y - r1.y);
    if (r1.r * r1.r > d) return 1;//��A��Բ��
    else if (r1.r * r1.r == d) return 2;//����Բ��
    else return 0;//��A��Բ��
}
#include "Line.h"
void Line::in() {
    cout << "p1������:";
    cin >> p1.x >> p1.y;
    cout << "p2������:";
    cin >> p2.x >> p2.y;
}
int line_round(Line l1, Round r1) {//����Բ��λ�ù�ϵ
    double a, b, c, dist1, dist2, angle1, angle2;
    if (point_round(l1.p1, r1) == 2 || point_round(l1.p2, r1) == 2)return 0;
    if (point_round(l1.p1, r1) * point_round(l1.p2, r1))return 1;//����Բ��
    if (point_round(l1.p1, r1) ^ point_round(l1.p2, r1))return 0;//һ��һ��
    if (point_round(l1.p1, r1) + point_round(l1.p2, r1) == 0) {//����Բ��
        if (l1.p1.x == l1.p2.x)//ax2+bx+c
            a = 1, b = 0, c = -l1.p1.x;
        else if (l1.p1.y == l1.p2.y)
            a = 0, b = 1, c = -l1.p1.y;
        else {
            a = l1.p1.y - l1.p2.y;
            b = l1.p2.x - l1.p1.x;
            c = l1.p1.x * l1.p2.y - l1.p1.y * l1.p2.x;
        }
        dist1 = a * r1.x + b * r1.y + c;
        dist1 *= dist1;
        dist2 = (a * a + b * b) * r1.r * r1.r;
        if (dist1 > dist2) return 1;//����
        angle1 = (r1.x - l1.p1.x) * (l1.p2.x - l1.p1.x) + (r1.y - l1.p1.y) * (l1.p2.y - l1.p1.y);
        angle2 = (r1.x - l1.p2.x) * (l1.p1.x - l1.p2.x) + (r1.y - l1.p2.y) * (l1.p1.y - l1.p2.y);
        if (angle1 > 0 && angle2 > 0) return 0;//�ཻ
        return 1;
    }
}
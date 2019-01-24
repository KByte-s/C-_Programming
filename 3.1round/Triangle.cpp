#include "Triangle.h"
void Triangle::in() {
    int a[6];
    for (int i = 0; i < 6; i += 2) {
        cout << "请输入第" << i / 2 + 1 << "个坐标:";
        cin >> a[i] >> a[i + 1];
    }
    round1.in();
    line1.p1.x = a[0];
    line1.p1.y = a[1];
    line1.p2.x = a[2];
    line1.p1.y = a[3];
    line2.p1.x = a[0];
    line2.p1.y = a[1];
    line2.p1.x = a[4];
    line2.p1.y = a[5];
    line3.p2.x = a[2];
    line3.p1.y = a[3];
    line3.p1.x = a[4];
    line3.p1.y = a[5];
}
bool Triangle::triangle_round() {
    if (line_round(line1, round1) && line_round(line2, round1) && line_round(line3, round1))return 0;//相交
    return 1;
}
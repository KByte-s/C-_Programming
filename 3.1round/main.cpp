#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Round.h"
#include "Oval.h"
#include "Triangle.h"
using namespace std;
int double_round(Round r1, Round r2);
//两个圆的位置关系
int main() {
    int choose;
    Round round1, round2;
    Point point1;
    Line line1;
    Oval oval1;
    Triangle triangle1;
    while (true) {
        system("cls");
        cout << "********************************" << endl
             << "0.退出" << endl
             << "1.判断点是否在圆内" << endl
             << "2.判断线段是否与圆相交" << endl
             << "3.判断两个圆是否相交" << endl
             << "4.判断点是否在椭圆内" << endl
             << "5.判断三角形是否与圆相交" << endl
             << "********************************" << endl;
        cout << "请输入:";
        cin >> choose;
        if (choose == 0) break;
        else if (choose == 1) {
            round1.in();
            point1.in();
            if (point_round(point1, round1) == 0)
                cout << "点A在圆外" << endl;
            else
                cout << "点A在圆内" << endl;
            system("pause");
        } else if (choose == 2) {
            round1.in();
            line1.in();
            int a = line_round(line1, round1);
            if (a == 0)
                cout << "线与圆相交" << endl;
            else if (a == 1)
                cout << "线与圆不交" << endl;
            system("pause");
        } else if (choose == 3) {
            round1.in();
            round2.in();
            int a = double_round(round1, round2);
            if (a == 0)
                cout << "两圆相交" << endl;
            else if (a == 1)
                cout << "两圆不交" << endl;
            system("pause");
        } else if (choose == 4) {
            //判断点是否在椭圆内
            oval1.in();
            if (oval1.point_oval() == 1)
                cout << "点在椭圆外" << endl;
            else
                cout << "点在椭圆内" << endl;
            system("pause");
        } else if (choose == 5) {
            // 判断三角形是否与圆相交
            triangle1.in();
            if (triangle1.triangle_round() == 1)
                cout << "三角形与圆相交" << endl;
            else
                cout << "三角形与圆不相交" << endl;
            system("pause");
        }
    }
    system("pause");
}
int double_round(Round r1, Round r2) {
    int d = (r1.x - r2.x) * (r1.x - r2.x) + (r1.y - r2.y) * (r1.y - r2.y);
    if (d >= (r1.r - r2.r) * (r1.r - r2.r) && d <= (r1.r + r2.r) * (r1.r + r2.r)) return 0;//相交
    else return 1;//不交
}
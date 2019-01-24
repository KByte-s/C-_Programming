#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Round.h"
#include "Oval.h"
#include "Triangle.h"
using namespace std;
int double_round(Round r1, Round r2);
//����Բ��λ�ù�ϵ
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
             << "0.�˳�" << endl
             << "1.�жϵ��Ƿ���Բ��" << endl
             << "2.�ж��߶��Ƿ���Բ�ཻ" << endl
             << "3.�ж�����Բ�Ƿ��ཻ" << endl
             << "4.�жϵ��Ƿ�����Բ��" << endl
             << "5.�ж��������Ƿ���Բ�ཻ" << endl
             << "********************************" << endl;
        cout << "������:";
        cin >> choose;
        if (choose == 0) break;
        else if (choose == 1) {
            round1.in();
            point1.in();
            if (point_round(point1, round1) == 0)
                cout << "��A��Բ��" << endl;
            else
                cout << "��A��Բ��" << endl;
            system("pause");
        } else if (choose == 2) {
            round1.in();
            line1.in();
            int a = line_round(line1, round1);
            if (a == 0)
                cout << "����Բ�ཻ" << endl;
            else if (a == 1)
                cout << "����Բ����" << endl;
            system("pause");
        } else if (choose == 3) {
            round1.in();
            round2.in();
            int a = double_round(round1, round2);
            if (a == 0)
                cout << "��Բ�ཻ" << endl;
            else if (a == 1)
                cout << "��Բ����" << endl;
            system("pause");
        } else if (choose == 4) {
            //�жϵ��Ƿ�����Բ��
            oval1.in();
            if (oval1.point_oval() == 1)
                cout << "������Բ��" << endl;
            else
                cout << "������Բ��" << endl;
            system("pause");
        } else if (choose == 5) {
            // �ж��������Ƿ���Բ�ཻ
            triangle1.in();
            if (triangle1.triangle_round() == 1)
                cout << "��������Բ�ཻ" << endl;
            else
                cout << "��������Բ���ཻ" << endl;
            system("pause");
        }
    }
    system("pause");
}
int double_round(Round r1, Round r2) {
    int d = (r1.x - r2.x) * (r1.x - r2.x) + (r1.y - r2.y) * (r1.y - r2.y);
    if (d >= (r1.r - r2.r) * (r1.r - r2.r) && d <= (r1.r + r2.r) * (r1.r + r2.r)) return 0;//�ཻ
    else return 1;//����
}
#include "Oval.h"
void Oval::in() {
    cout << "��Բ���᳤�����᳤:";
    cin >> a >> b;
    cout << "������:";
    cin >> x >> y;
    if (b > a)type = 1; // ����ȳ��᳤
    a /= 2;
    b /= 2;
    c = sqrt(a * a - b * b);
}
bool Oval::point_oval() {
    double pf1, pf2;
    if (type == 0) {
        pf1 = y * y + (x - c) * (x - c);
        pf2 = y * y + (x + c) * (x + c);
    } else {
        pf1 = x * x + (y - c) * (y - c);
        pf2 = x * x + (y + c) * (y + c);
    }
    if (sqrt(pf1) + sqrt(pf2) > 2 * a)return 1;//��Բ��
    else return 0;//��Բ��
}
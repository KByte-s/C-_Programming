#include <iostream>
using namespace std;

class Smile {
public:
    Smile(string n) {
        name = n;
        cout << "Hi " << name << "!" << endl;
    }

    ~Smile() {
        cout << "Goodbye " << name << "!" << endl;
    }

    string name;
};

Smile s1("Rose"), s2("Jose");

int main() {
    cout << "���ջ�ӭ�㣡" << endl;
    return 0;
}
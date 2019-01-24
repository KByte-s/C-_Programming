#ifndef INC_1_2WELCOME_SMILE_H
#define INC_1_2WELCOME_SMILE_H
#include <iostream>
#include <string>
using namespace std;
class Smile {
public:
    Smile() {
        dis = "Welcome!";
    }
    inline void Display() {
        cout << dis << endl;
    }
    void Set(string n);
    void talk();
    string Get();
    ~Smile() {
        cout << "Goodbye!" << endl;
    }
    string dis, in;
};
#endif //INC_1_2WELCOME_SMILE_H

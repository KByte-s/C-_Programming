//
// Created by 11039 on 2018/11/21.
//

#ifndef INC_1_1WELCOME_SMILE_H
#define INC_1_1WELCOME_SMILE_H

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


#endif //INC_1_1WELCOME_SMILE_H

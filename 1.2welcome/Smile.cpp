#include "Smile.h"
void Smile::Set(string n) {
    in = n;
}
string Smile::Get() {
    return in;
}
void Smile::talk() {
    while (true) {
        cout << "����:";
        getline(cin, in);
        if (in == "OK") {
            cout << "All right" << endl;
            cout << "Goodbye!" << endl;
            dis = in;
            break;
        } else cout << "���:" << Get() << endl;
    }
}
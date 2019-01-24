#include <iostream>
#include "Smile.h"
using namespace std;
int main() {
    Smile we;
    Smile you(we);
    you.Display();
    you.Set("Thank you.");
    cout << you.Get() << endl;
    you.talk();
    you.Display();
    //system("pause");
    return 0;
}
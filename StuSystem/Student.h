#ifndef STUSYSTEM_STUDENT_H
#define STUSYSTEM_STUDENT_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Student {
public:
    friend istream &operator>>(istream &in, Student &s);//重载输入输出流
    friend ostream &operator<<(ostream &in, Student &s);
    int ifvoid = 0;
    string outputid();
    string outputname();
    int outputmath();
    int outputchinese();
    double outputaver();
    friend int savefile(vector<Student> &vs, const string &address);
    friend int readfile(vector<Student> &vs, const string &address);
    ~Student() = default;
private:
    string id, name;
    int score_math, score_chinese;
    double aver;
};
#endif //STUSYSTEM_STUDENT_H
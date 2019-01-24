#ifndef STUSYSTEM_FUNCTION_H
#define STUSYSTEM_FUNCTION_H
#include <iostream>
#include "Student.h"
#include <vector>
#include <fstream>
using namespace std;
class Function {
public:
    void major();
    int menu();
    int menu(int choose);
    void add(vector<Student> &vs);
    void out(vector<Student> &vs);
    void deletefile(vector<Student> &vs, int n);
    void seek(vector<Student> &vs, int n);
    vector<Student> fail(vector<Student> &vs);
    vector<Student> pass(vector<Student> &vs);
    void outmean(vector<Student> &vs);
};
#endif //STUSYSTEM_FUNCTION_H

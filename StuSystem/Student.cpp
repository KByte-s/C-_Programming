#include "Student.h"
istream &operator>>(istream &in, Student &s) {
    cout << "学号：";
    in >> s.id;
    if (s.id == "0") {
        s.ifvoid = 1;
        return in;
    }
    cout << "姓名：";
    in >> s.name;
    cout << "数学：";
    in >> s.score_math;
    cout << "语文：";
    in >> s.score_chinese;
    s.aver = ((double) s.score_chinese + (double) s.score_math) / 2;
    return in;
}
ostream &operator<<(ostream &out, Student &s) {
    out << s.id << "\t" << s.name << "\t"
        << s.score_math << "\t"
        << s.score_chinese << "\t"
        << s.aver;
    return out;
}
string Student::outputid() {
    return id;
}
string Student::outputname() {
    return name;
}
int Student::outputmath() {
    return score_math;
}
int Student::outputchinese() {
    return score_chinese;
}
double Student::outputaver() {
    return aver;
}
int savefile(vector<Student> &vs, const string &address) {
    ofstream tofile(address, ios::out | ios::trunc | ios::binary);
    int Strlen;
    int count = 0;
    for (auto i:vs) {
        count++;
        Strlen = (int) i.id.length();
        tofile.write((char *) &Strlen, sizeof(int));
        tofile.write(i.id.c_str(), Strlen);
        Strlen = (int) i.name.length();
        tofile.write((char *) &Strlen, sizeof(int));
        tofile.write(i.name.c_str(), Strlen);
        tofile.write((char *) &i.score_math, sizeof(int));
        tofile.write((char *) &i.score_chinese, sizeof(int));
        tofile.write((char *) &i.aver, sizeof(double));
    }
    tofile.close();
    return count;
}
int readfile(vector<Student> &vs, const string &address) {
    vs.clear();
    fstream fromfile(address, ios::in | ios::binary);
    if (!fromfile)
        return 0;
    Student temp;
    int count = 0, StrLen;
    char tChar;
    while (fromfile.read((char *) &StrLen, sizeof(int))) {
        count++;
        while (StrLen--) fromfile.read(&tChar, sizeof(char)), temp.id.push_back(tChar);
        fromfile.read((char *) &StrLen, sizeof(int));
        while (StrLen--) fromfile.read(&tChar, sizeof(char)), temp.name.push_back(tChar);
        fromfile.read((char *) &temp.score_math, sizeof(int));
        fromfile.read((char *) &temp.score_chinese, sizeof(int));
        fromfile.read((char *) &temp.aver, sizeof(double));
        vs.push_back(temp);
        temp.id.clear();
        temp.name.clear();
    }
    fromfile.close();
    return count;
}

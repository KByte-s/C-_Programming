#include "Function.h"
void Function::major() {
    int cho;
    vector<Student> vStuAll;
    vector<Student> vStuBad;
    vector<Student> vStuMean(vStuAll);
    vector<Student> vStuPass;
    readfile(vStuAll, "stud.dat");
    while (true) {
        cho = menu();
        if (cho == 9){system("pause");exit(0);}
        else if (cho == 1) {
            //1.增加原始记录
            fstream ifempty("stud.dat", ios::in | ios::binary);
            if (!ifempty)
                cout << "还没有建立文件，退出时别忘记保存！" << endl;
            ifempty.close();
            add(vStuAll);
        } else if (cho == 2) {
            //2.显示各种文件
            cho = menu(cho);
            if (cho == 1) {
                //源文件
                //判断记录数量
                cout << "现在共有如下" << vStuAll.size() << "条记录" << endl;
                out(vStuAll);
            } else if (cho == 2) {
                //简明文件
                vStuMean.clear();
                cout << "取文件...." << endl;
                readfile(vStuMean, "studmean.dat");
                outmean(vStuMean);
            } else if (cho == 3) {
                //均不及格文件
                vStuBad.clear();
                cout << "取文件...." << endl;
                readfile(vStuBad, "bad.dat");
                out(vStuBad);
            } else if (cho == 4) {
                //输出高于或等于平均成绩的学生名单
                vStuPass = pass(vStuAll);
                out(vStuPass);
            }
        } else if (cho == 3) {
            //3.保存原始文件
            cout << "存文件" << endl;
            cout << savefile(vStuAll, "stud.dat") << "条记录已经存入文件，请继续操作。" << endl;
        } else if (cho == 4) {
            //4.读取原始文件
            cout << "取文件...." << endl;
            cout << "取入" << readfile(vStuAll, "stud.dat") << "条记录。" << endl;
        } else if (cho == 5) {
            //5.删除原始记录
            cho = menu(cho);
            deletefile(vStuAll, cho);
        } else if (cho == 6) {
            //6.建立简明文件
            cout << "存文件" << endl;
            vStuMean = vStuAll;
            cout << savefile(vStuMean, "studmean.dat") << "条记录已经存入文件，内容如下：" << endl;
            outmean(vStuMean);
        } else if (cho == 7) {
            cout << "两科均不及格的学生信息如下：" << endl;
            vStuBad = fail(vStuAll);
            out(vStuBad);
            savefile(vStuBad, "bad.dat");
            cout << "文件存储成功" << endl;
            //7.均不及格文件
        } else if (cho == 8) {
            //8.寻找链表记录
            cho = menu(cho);
            seek(vStuAll, cho);
        }
    }
}
int Function::menu() {
    int choose;
    while (true) {
        cout << "1.增加原始记录" << endl
             << "2.显示各种文件" << endl
             << "3.保存原始文件" << endl
             << "4.读取原始文件" << endl
             << "5.删除原始记录" << endl
             << "6.建立简明文件" << endl
             << "7.均不及格文件" << endl
             << "8.寻找链表记录" << endl
             << "9.结束程序运行" << endl;
        cout << "左边数字对应相应功能选择，请选1-9：";
        cin >> choose;
        cin.clear();
        cin.sync();
        if (choose >= 1 && choose <= 9)break;
        else cout << "输入错误！" << endl;
    }
    return choose;
}
int Function::menu(int choose) {
    if (choose == 2) {//第二项的二级菜单
        cout << "选择要看的文件类别" << endl
             << "1.原文件" << endl
             << "2.简明文件" << endl
             << "3.均不及格文件" << endl
             << "4.输出高于或等于平均成绩的学生名单" << endl;
        cout << "请选1-4：";
        cin >> choose;
        cin.clear();
        cin.sync();
        return choose;
    } else if (choose == 8 || choose == 5) {//第八,五项的二级菜单
        cout << "1.通过学号寻找" << endl
             << "2.通过名字寻找" << endl;
        cout << "请选1-2：";
        cin >> choose;
        cin.clear();
        cin.sync();
        return choose;
    }
}
void Function::add(vector<Student> &vs) {
    Student temp;
    cout << "输入数据，输入0时结束。" << endl;
    while (true) {
        cin >> temp;
        if (temp.ifvoid == 1)
            break;
        vs.push_back(temp);//添加到容器中
    }
}
void Function::out(vector<Student> &vs) {
    cout << "学号\t姓名\t数学\t语文\t平均" << endl;
    vector<Student>::iterator iter;//迭代器使用
    for (iter = vs.begin(); iter != vs.end(); iter++) {
        cout << *iter << endl;
    }
}
void Function::deletefile(vector<Student> &vs, int n) {
    //fstream file("stud.dat", ios::trunc);
    string info;
    int num = 0, count = 0;
    if (n == 1)cout << "请输入学号：";
    else if (n == 2)cout << "请输入名字：";
    cin >> info;
    cout << "被删除记录信息如下：" << endl;
    cout << "学号\t姓名\t数学\t语文\t平均" << endl;
    for (auto i :vs) {
        if (n == 1) {
            if (info == i.outputid()) {
                cout << i << endl;
                num++;
                vs.erase(vs.begin() + count);
            }
        } else if (n == 2) {
            if (info == i.outputname()) {
                cout << i << endl;
                num++;
                vs.erase(vs.begin() + count);
            }
        }
        count++;
    }
    if (num == 0) {
        cout << "没有找到此人" << endl;
        return;
    }
    cout << "当前选择保存记录之后，才能确定删除。" << endl;
}
void Function::seek(vector<Student> &vs, int n) {
    string info;
    int count = 0;
    vector<Student>::iterator iter;
    if (n == 1)cout << "请输入学号：";
    else if (n == 2)cout << "请输入名字：";
    cin >> info;
    cout << "找到信息如下：" << endl;
    cout << "学号\t姓名\t数学\t语文\t平均" << endl;
    for (iter = vs.begin(); iter != vs.end(); iter++) {
        if (n == 1) {
            if (info == iter->outputid()) {
                cout << *iter << endl;
                count++;
            }
        } else if (n == 2) {
            if (info == iter->outputname()) {
                cout << *iter << endl;
                count++;
            }
        }
    }
    if (count == 0)
        cout << "没有找到此人" << endl;
}
vector<Student> Function::fail(vector<Student> &vs) {
    vector<Student> temp;
    for (auto i : vs) {
        if (i.outputchinese() < 60 && i.outputmath() < 60)
            temp.push_back(i);
    }
    return temp;
}
vector<Student> Function::pass(vector<Student> &vs) {
    vector<Student> temp;
    double average = 0;
    for (auto i : vs)
        average += i.outputaver();
    average /= vs.size();
    for (auto i : vs) {
        if (i.outputaver() >= average)
            temp.push_back(i);
    }
    return temp;
}
void Function::outmean(vector<Student> &vs) {
    cout << "姓名\t平均成绩" << endl;
    vector<Student>::iterator iter;//迭代器使用
    for (iter = vs.begin(); iter != vs.end(); iter++) {
        cout << iter->outputname() << "\t" << iter->outputaver() << endl;
    }
}
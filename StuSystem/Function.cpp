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
            //1.����ԭʼ��¼
            fstream ifempty("stud.dat", ios::in | ios::binary);
            if (!ifempty)
                cout << "��û�н����ļ����˳�ʱ�����Ǳ��棡" << endl;
            ifempty.close();
            add(vStuAll);
        } else if (cho == 2) {
            //2.��ʾ�����ļ�
            cho = menu(cho);
            if (cho == 1) {
                //Դ�ļ�
                //�жϼ�¼����
                cout << "���ڹ�������" << vStuAll.size() << "����¼" << endl;
                out(vStuAll);
            } else if (cho == 2) {
                //�����ļ�
                vStuMean.clear();
                cout << "ȡ�ļ�...." << endl;
                readfile(vStuMean, "studmean.dat");
                outmean(vStuMean);
            } else if (cho == 3) {
                //���������ļ�
                vStuBad.clear();
                cout << "ȡ�ļ�...." << endl;
                readfile(vStuBad, "bad.dat");
                out(vStuBad);
            } else if (cho == 4) {
                //������ڻ����ƽ���ɼ���ѧ������
                vStuPass = pass(vStuAll);
                out(vStuPass);
            }
        } else if (cho == 3) {
            //3.����ԭʼ�ļ�
            cout << "���ļ�" << endl;
            cout << savefile(vStuAll, "stud.dat") << "����¼�Ѿ������ļ��������������" << endl;
        } else if (cho == 4) {
            //4.��ȡԭʼ�ļ�
            cout << "ȡ�ļ�...." << endl;
            cout << "ȡ��" << readfile(vStuAll, "stud.dat") << "����¼��" << endl;
        } else if (cho == 5) {
            //5.ɾ��ԭʼ��¼
            cho = menu(cho);
            deletefile(vStuAll, cho);
        } else if (cho == 6) {
            //6.���������ļ�
            cout << "���ļ�" << endl;
            vStuMean = vStuAll;
            cout << savefile(vStuMean, "studmean.dat") << "����¼�Ѿ������ļ����������£�" << endl;
            outmean(vStuMean);
        } else if (cho == 7) {
            cout << "���ƾ��������ѧ����Ϣ���£�" << endl;
            vStuBad = fail(vStuAll);
            out(vStuBad);
            savefile(vStuBad, "bad.dat");
            cout << "�ļ��洢�ɹ�" << endl;
            //7.���������ļ�
        } else if (cho == 8) {
            //8.Ѱ�������¼
            cho = menu(cho);
            seek(vStuAll, cho);
        }
    }
}
int Function::menu() {
    int choose;
    while (true) {
        cout << "1.����ԭʼ��¼" << endl
             << "2.��ʾ�����ļ�" << endl
             << "3.����ԭʼ�ļ�" << endl
             << "4.��ȡԭʼ�ļ�" << endl
             << "5.ɾ��ԭʼ��¼" << endl
             << "6.���������ļ�" << endl
             << "7.���������ļ�" << endl
             << "8.Ѱ�������¼" << endl
             << "9.������������" << endl;
        cout << "������ֶ�Ӧ��Ӧ����ѡ����ѡ1-9��";
        cin >> choose;
        cin.clear();
        cin.sync();
        if (choose >= 1 && choose <= 9)break;
        else cout << "�������" << endl;
    }
    return choose;
}
int Function::menu(int choose) {
    if (choose == 2) {//�ڶ���Ķ����˵�
        cout << "ѡ��Ҫ�����ļ����" << endl
             << "1.ԭ�ļ�" << endl
             << "2.�����ļ�" << endl
             << "3.���������ļ�" << endl
             << "4.������ڻ����ƽ���ɼ���ѧ������" << endl;
        cout << "��ѡ1-4��";
        cin >> choose;
        cin.clear();
        cin.sync();
        return choose;
    } else if (choose == 8 || choose == 5) {//�ڰ�,����Ķ����˵�
        cout << "1.ͨ��ѧ��Ѱ��" << endl
             << "2.ͨ������Ѱ��" << endl;
        cout << "��ѡ1-2��";
        cin >> choose;
        cin.clear();
        cin.sync();
        return choose;
    }
}
void Function::add(vector<Student> &vs) {
    Student temp;
    cout << "�������ݣ�����0ʱ������" << endl;
    while (true) {
        cin >> temp;
        if (temp.ifvoid == 1)
            break;
        vs.push_back(temp);//��ӵ�������
    }
}
void Function::out(vector<Student> &vs) {
    cout << "ѧ��\t����\t��ѧ\t����\tƽ��" << endl;
    vector<Student>::iterator iter;//������ʹ��
    for (iter = vs.begin(); iter != vs.end(); iter++) {
        cout << *iter << endl;
    }
}
void Function::deletefile(vector<Student> &vs, int n) {
    //fstream file("stud.dat", ios::trunc);
    string info;
    int num = 0, count = 0;
    if (n == 1)cout << "������ѧ�ţ�";
    else if (n == 2)cout << "���������֣�";
    cin >> info;
    cout << "��ɾ����¼��Ϣ���£�" << endl;
    cout << "ѧ��\t����\t��ѧ\t����\tƽ��" << endl;
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
        cout << "û���ҵ�����" << endl;
        return;
    }
    cout << "��ǰѡ�񱣴��¼֮�󣬲���ȷ��ɾ����" << endl;
}
void Function::seek(vector<Student> &vs, int n) {
    string info;
    int count = 0;
    vector<Student>::iterator iter;
    if (n == 1)cout << "������ѧ�ţ�";
    else if (n == 2)cout << "���������֣�";
    cin >> info;
    cout << "�ҵ���Ϣ���£�" << endl;
    cout << "ѧ��\t����\t��ѧ\t����\tƽ��" << endl;
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
        cout << "û���ҵ�����" << endl;
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
    cout << "����\tƽ���ɼ�" << endl;
    vector<Student>::iterator iter;//������ʹ��
    for (iter = vs.begin(); iter != vs.end(); iter++) {
        cout << iter->outputname() << "\t" << iter->outputaver() << endl;
    }
}
#pragma once
#include "Experience.h"
#include "Jobtitle.h"
#include "Subordinates.h"

class Salary
{
public:
    Salary(int overtimecost, int weekendcost, int exppercent, int subspercent, bool expstatus, \
        bool subsstatus);
    Salary(int allfields);
    Salary();
    void set(Salary salary);
    void input();
    void output();
    int overtimeweekends(int overtime, int weekends);
    int allmoney(int salary, Subordinates subs);
    int allmoney(int salary, Experience experience);
    Salary operator + (Salary salary);
    Salary& operator++(); //����������
    Salary operator++(int); //�����������
    void tofile(ofstream& file, string filename);
    void getfromfile(ifstream& file, string filename);
private:
    int overtimecost; //������� ���������� ������ ������������ ����� 
    int weekendcost; //������� ���������� ������ ����� ������������ � ��������
    int exppercent; //������� ���������� ������ �� ����
    int subspercent; //������� ���������� ������ �� ������� �����������
    bool expstatus; //���� �����
    bool subsstatus; //���� ������� �����������
};


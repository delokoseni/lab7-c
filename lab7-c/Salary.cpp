#include "Salary.h"
#include "Experience.h"
#include "Jobtitle.h"
#include "checkfileextension.h"
#include <iostream>
using namespace std;

//����������� �� ����� �����������
Salary::Salary(int overtimecost, int weekendcost, int exppercent, int subspercent, bool expstatus, \
    bool subsstatus) {
    if (overtimecost >= 0)
        this->overtimecost = overtimecost;
    else {
        cout << "������� ������������ �������� overtimecost." << endl;
        this->overtimecost = 0;
    }
    if (weekendcost >= 0)
        this->weekendcost = weekendcost;
    else {
        cout << "������� ������������ �������� weekendcost." << endl;
        this->weekendcost = 0;
    }
    if (exppercent >= 0)
        this->exppercent = exppercent;
    else {
        cout << "������� ������������ �������� exppercent." << endl;
        this->exppercent = 0;
    }
    if (subspercent >= 0)
        this->subspercent = subspercent;
    else {
        cout << "������� ������������ �������� subspercent." << endl;
        this->subspercent = 0;
    }
    this->expstatus = expstatus;
    this->subsstatus = subsstatus;
}

//����������� � ����� ����������
Salary::Salary(int allfields) {
    if (allfields >= 0) {
        overtimecost = allfields;
        weekendcost = allfields;
        exppercent = allfields;
        subspercent = allfields;
        if (allfields > 0) {
            expstatus = true;
            subsstatus = true;
        }
        else {
            expstatus = false;
            subsstatus = false;
        }
    }
    else {
        cout << "������� ������������ �������� allfields." << endl;
        overtimecost = 0;
        weekendcost = 0;
        exppercent = 0;
        subspercent = 0;
        expstatus = false;
        subsstatus = false;
    }
}

//����������� ��� ����������
Salary::Salary() {
    overtimecost = 0;
    weekendcost = 0;
    exppercent = 0;
    subspercent = 0;
    expstatus = false;
    subsstatus = false;
}

//����� ��������� ��������
void Salary::set(Salary salary) {
    this->overtimecost = salary.overtimecost;
    this->weekendcost = salary.weekendcost;
    this->exppercent = salary.exppercent;
    this->subspercent = salary.subspercent;
    this->expstatus = salary.expstatus;
    this->subsstatus = salary.subsstatus;
}

//����� �����
void Salary::input() {
    int a, overtimecost, weekendcost, exppercent = 0, subspercent = 0;
    bool expstatus = false, subsstatus = false;
    cout << "�� ������� ��������� ����������� ��������� ������ ������������: ";
    cin >> overtimecost;
    cout << "�� ������� ��������� ����������� ��������� ������ � ��������: ";
    cin >> weekendcost;
    cout << "��������� �� ���� (0 - ���, ����� - ��): ";
    cin >> a;
    if (a != 0) {
        cout << "�� ������� ��������� �������� �������� �� ����: ";
        cin >> exppercent;
        expstatus = true;
    }
    cout << "��������� �� ������� �����������(0 - ���, ����� - ��) : ";
    cin >> a;
    if (a != 0) {
        cout << "�� ������� ��������� �������� �������� �� ������� �����������: ";
        cin >> subspercent;
        subsstatus = true;
    }
    Salary salary(overtimecost, weekendcost, exppercent, subspercent, expstatus, subsstatus);
    this->set(salary);
}

//����� ������
void Salary::output() {
    cout << "\n����������� ��������� ������ ������������ �����: " << overtimecost;
    cout << "\n����������� ��������� ������ ����� ������������ � ��������: " << weekendcost;
    cout << "\n����������� ��������� ������ �� ����: " << exppercent;
    cout << "\n����������� ��������� ������ �� ������� �����������: " << subspercent;
    cout << "\n���� �����: " << expstatus;
    cout << "\n���� ������� �����������: " << subsstatus;
}

//��������������� ����� ��� ���������� ��������
int Salary::overtimeweekends(int overtime, int weekends) {
    int x = 0;
    x += overtime * overtimecost;
    x += weekends * weekendcost;
    return x;
}

//��������������� ����� ��� ���������� ��������
int Salary::allmoney(int salary, Subordinates subs) {
    if (subsstatus)
        salary += (float)salary / 100 * subspercent * subs.getamount();
    return salary;
}

//��������������� ����� ��� ���������� ��������
int Salary::allmoney(int salary, Experience exp) {
    if (expstatus)
        salary += (float)salary / 100 * exppercent * exp.allexp();
    return salary;
}

//���������� ��������� +
Salary Salary::operator + (Salary s1) {
    overtimecost += s1.overtimecost;
    weekendcost += s1.weekendcost;
    exppercent += s1.exppercent;
    subspercent += s1.subspercent;
    if (expstatus || s1.expstatus)
        expstatus = true;
    else
        expstatus = false;
    if (subsstatus || s1.subsstatus)
        subsstatus = true;
    else
        subsstatus = false;
    return *this;
}

//���������� ��������� ++ ����������
Salary& Salary::operator++() {
    this->overtimecost += 1;
    this->weekendcost += 1;
    this->exppercent += 1;
    this->subspercent += 1;
    this->expstatus = true;
    this->subsstatus = true;
    return *this;
}

//���������� ��������� ++ �����������
Salary Salary::operator++(int) {
    Salary temp = *this;
    ++* this;
    return temp;
}

//����� ������ � ����
void Salary::tofile(ofstream& file, string filename) {
    if (!checkfileextension(filename))
        throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
    file << overtimecost << "\t";
    file << weekendcost << "\t";
    file << exppercent << "\t";
    file << subspercent << "\t";
    file << expstatus << "\t";
    file << subsstatus << "\t";
}

//����� ������ �� �����
void Salary::getfromfile(ifstream& file, string filename) {
    if (!checkfileextension(filename))
        throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
    try {
        file >> overtimecost;
        file >> weekendcost;
        file >> exppercent;
        file >> subspercent;
        file >> expstatus;
        file >> subsstatus;
    }
    catch (exception& e) {
        throw exception("� ����� ������������ ������ ��� ������  ��� ������� ������� ��� �����.\n");
    }
}
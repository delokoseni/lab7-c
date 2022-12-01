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
    Salary& operator++(); //префиксный
    Salary operator++(int); //постфиксный
    void tofile(ofstream& file, string filename);
    void getfromfile(ifstream& file, string filename);
private:
    int overtimecost; //Процент увеличения оплаты сверхурочных часов 
    int weekendcost; //Процент увеличения оплаты часов отработанных в выходные
    int exppercent; //Процент увеличения оплаты за стаж
    int subspercent; //Процент увеличения оплаты за наличие подчененных
    bool expstatus; //Учет стажа
    bool subsstatus; //Учет наличия подчиненных
};


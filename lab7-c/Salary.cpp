#include "Salary.h"
#include "Experience.h"
#include "Jobtitle.h"
#include "checkfileextension.h"
#include <iostream>
using namespace std;

//Конструктор со всеми параметрами
Salary::Salary(int overtimecost, int weekendcost, int exppercent, int subspercent, bool expstatus, \
    bool subsstatus) {
    if (overtimecost >= 0)
        this->overtimecost = overtimecost;
    else {
        cout << "Указано недопустимое значение overtimecost." << endl;
        this->overtimecost = 0;
    }
    if (weekendcost >= 0)
        this->weekendcost = weekendcost;
    else {
        cout << "Указано недопустимое значение weekendcost." << endl;
        this->weekendcost = 0;
    }
    if (exppercent >= 0)
        this->exppercent = exppercent;
    else {
        cout << "Указано недопустимое значение exppercent." << endl;
        this->exppercent = 0;
    }
    if (subspercent >= 0)
        this->subspercent = subspercent;
    else {
        cout << "Указано недопустимое значение subspercent." << endl;
        this->subspercent = 0;
    }
    this->expstatus = expstatus;
    this->subsstatus = subsstatus;
}

//Конструктор с одним параметром
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
        cout << "Указано недопустимое значение allfields." << endl;
        overtimecost = 0;
        weekendcost = 0;
        exppercent = 0;
        subspercent = 0;
        expstatus = false;
        subsstatus = false;
    }
}

//Конструктор без параметров
Salary::Salary() {
    overtimecost = 0;
    weekendcost = 0;
    exppercent = 0;
    subspercent = 0;
    expstatus = false;
    subsstatus = false;
}

//метод установки значений
void Salary::set(Salary salary) {
    this->overtimecost = salary.overtimecost;
    this->weekendcost = salary.weekendcost;
    this->exppercent = salary.exppercent;
    this->subspercent = salary.subspercent;
    this->expstatus = salary.expstatus;
    this->subsstatus = salary.subsstatus;
}

//метод ввода
void Salary::input() {
    int a, overtimecost, weekendcost, exppercent = 0, subspercent = 0;
    bool expstatus = false, subsstatus = false;
    cout << "На сколько процентов увеличивать почасовую оплату сверхурочных: ";
    cin >> overtimecost;
    cout << "На сколько процентов увеличивать почасовую оплату в выходные: ";
    cin >> weekendcost;
    cout << "Учитывать ли стаж (0 - нет, иначе - да): ";
    cin >> a;
    if (a != 0) {
        cout << "На сколько процентов умножать зарплату за стаж: ";
        cin >> exppercent;
        expstatus = true;
    }
    cout << "Учитывать ли наличие подчиненных(0 - нет, иначе - да) : ";
    cin >> a;
    if (a != 0) {
        cout << "На сколько процентов умножать зарплату за наличие подчиненных: ";
        cin >> subspercent;
        subsstatus = true;
    }
    Salary salary(overtimecost, weekendcost, exppercent, subspercent, expstatus, subsstatus);
    this->set(salary);
}

//метод вывода
void Salary::output() {
    cout << "\nКоэффициент умножения оплаты сверхурочных часов: " << overtimecost;
    cout << "\nКоэффициент умножения оплаты часов отработанных в выходные: " << weekendcost;
    cout << "\nКоэффициент умножения оплаты за стаж: " << exppercent;
    cout << "\nКоэффициент умножения оплаты за наличие подчененных: " << subspercent;
    cout << "\nУчет стажа: " << expstatus;
    cout << "\nУчет наличия подчиненных: " << subsstatus;
}

//Вспомогательный метод при вычислении зарплаты
int Salary::overtimeweekends(int overtime, int weekends) {
    int x = 0;
    x += overtime * overtimecost;
    x += weekends * weekendcost;
    return x;
}

//Вспомогательный метод при вычислении зарплаты
int Salary::allmoney(int salary, Subordinates subs) {
    if (subsstatus)
        salary += (float)salary / 100 * subspercent * subs.getamount();
    return salary;
}

//Вспомогательный метод при вычислении зарплаты
int Salary::allmoney(int salary, Experience exp) {
    if (expstatus)
        salary += (float)salary / 100 * exppercent * exp.allexp();
    return salary;
}

//перегрузка оператора +
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

//перегрузка оператора ++ префиксный
Salary& Salary::operator++() {
    this->overtimecost += 1;
    this->weekendcost += 1;
    this->exppercent += 1;
    this->subspercent += 1;
    this->expstatus = true;
    this->subsstatus = true;
    return *this;
}

//перегрузка оператора ++ постфиксный
Salary Salary::operator++(int) {
    Salary temp = *this;
    ++* this;
    return temp;
}

//метод записи в файл
void Salary::tofile(ofstream& file, string filename) {
    if (!checkfileextension(filename))
        throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
    file << overtimecost << "\t";
    file << weekendcost << "\t";
    file << exppercent << "\t";
    file << subspercent << "\t";
    file << expstatus << "\t";
    file << subsstatus << "\t";
}

//метод записи из файла
void Salary::getfromfile(ifstream& file, string filename) {
    if (!checkfileextension(filename))
        throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
    try {
        file >> overtimecost;
        file >> weekendcost;
        file >> exppercent;
        file >> subspercent;
        file >> expstatus;
        file >> subsstatus;
    }
    catch (exception& e) {
        throw exception("В файле недостаточно данных для записи  или неверно указано имя файла.\n");
    }
}
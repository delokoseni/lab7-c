#include "Hours.h"
#include "Salary.h"
#include "checkfileextension.h"
#include <iostream>
#include <fstream>
using namespace std;

//конструктор класса hours со всеми параметрами
Hours::Hours(int normal, int overtime, int weekends) {
	if (normal >= 0)
		this->normal = normal;
	else {
		cout << "”казано недопустимое значение normal." << endl;
		this->normal = 0;
	}
	if (overtime >= 0)
		this->overtime = overtime;
	else {
		cout << "”казано недопустимое значение overtime." << endl;
		this->overtime = 0;
	}
	if (weekends >= 0)
		this->weekends = weekends;
	else {
		cout << "”казано недопустимое значение weekends." << endl;
		this->weekends = 0;
	}
}

//конструктор класса hours с одним параметром
Hours::Hours(int allfields) {
	if (allfields >= 0) {
		normal = allfields;
		overtime = allfields;
		weekends = allfields;
	}
	else {
		cout << "”казано недопустимое значение allfields." << endl;
		normal = 0;
		overtime = 0;
		weekends = 0;
	}
}

//конструктор класса hours без параметров
Hours::Hours() {
	normal = 0;
	overtime = 0;
	weekends = 0;
}

//метод установки значений
void Hours::set(Hours h) {
	this->normal = h.normal;
	this->overtime = h.overtime;
	this->weekends = h.weekends;
}

//метод ввода класса hours
void Hours::input() {
	int normal, overtime, weekends;
	cout << "¬ведите кол-во отработанных за мес€ц часов(всего): ";
	cin >> normal;
	cout << "¬ведите кол-во сверхурочных часов: ";
	cin >> overtime;
	cout << "¬ведите кол-во отработанных за мес€ц часов в выходные: ";
	cin >> weekends;
	Hours h(normal, overtime, weekends);
	this->set(h);
}

//метод вывода
void Hours::output() {
	cout << "ќтработано часов за мес€ц(по графику): " << normal << endl;
	cout << "ќтработано часов за мес€ц(сверхурочно): " << overtime << endl;
	cout << "ќтработано часов за мес€ц(в выходные дни): " << weekends << endl;
}

//метод получени€ отработанных за мес€ц часов
int Hours::allhours() {
	int all = 0;
	all += normal;
	all += overtime;
	all += weekends;
	return all;
}

//метод возвращающий зарплаты за все отработанные часы
int Hours::hoursmoney(Jobtitle jt, Salary sal) {
	int salary = 0;
	//использование дружественной функции
	salary += normhcost(*(this), jt);
	salary += sal.overtimeweekends(overtime, weekends);
	return salary;
}

//перегрузка оператора +
Hours Hours::operator + (Hours h2) {
	normal += h2.normal;
	overtime += h2.overtime;
	weekends += h2.weekends;
	return *this;
}

//перегрузка оператора ++ префиксный
Hours& Hours::operator++() {
	this->normal += 1;
	this->overtime += 1;
	this->weekends += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Hours Hours::operator++(int) {
	Hours temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Hours::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("»спользовано недопустимое расширение файла. ƒопустимое расширение: \".txt\".\n");
	file << normal << "\t";
	file << overtime << "\t";
	file << weekends << "\t";
}

//метод вывода из файла
void Hours::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("»спользовано недопустимое расширение файла. ƒопустимое расширение: \".txt\".\n");
	try {
		file >> normal;
		file >> overtime;
		file >> weekends;
	}
	catch (exception& e) {
		throw exception("¬ файле недостаточно данных дл€ записи  или неверно указано им€ файла.\n");
	}
}

ostream& operator<< (ostream& os, Hours& hours) {
	os << "normal: " << hours.normal << " ";
	os << "overtime: " << hours.overtime << " ";
	os << "weekends: " << hours.weekends << " ";
	return os;
}
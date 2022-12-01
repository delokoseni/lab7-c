#include "Subemployee.h"
#include "Employee.h"
#include <fstream>
using namespace std;

//конструктор класса employee без параметров
Subemployee::Subemployee() : Employee() {
	managerid = 0;
}


//конструктор класса employee со всеми параметрами
Subemployee::Subemployee(Experience e, Hours h, Jobtitle j, int managerid) : Employee(e, h, j) {
	this->managerid = managerid;
}

//конструктор класса employee с одним параметром
Subemployee::Subemployee(int allfields) : Employee(allfields) {
	if (allfields >= 0) {
		managerid = allfields;
	}
	else {
		managerid = 0;
	}
}

//метод вывода Subemployee
void Subemployee::output() {
	this->Employee::output();
	cout << "ID ”правл€ющего: " << managerid << endl;
}

//метод ввода
void Subemployee::input() {
	this->Employee::input();
	cout << "¬ведите ID ”правл€ющего: ";
	cin >> managerid;
}


//метод записи в файл
void Subemployee::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("»спользовано недопустимое расширение файла. ƒопустимое расширение: \".txt\".\n");
	file << id << "\t";
	exp.tofile(file, filename);
	hour.tofile(file, filename);
	jt.tofile(file, filename);
	file << managerid << "\n";
}

//метод записи из файла
void Subemployee::getfromfile(ifstream& file, string filename) {
	try {
		this->Employee::getfromfile(file, filename);
		file >> managerid;
	}
	catch (exception& e) {
		throw exception("¬ файле недостаточно данных дл€ записи.\n");
	}
}

//перегрузка оператора присваивани€
Subemployee Subemployee::operator= (Subemployee sub) {
	this->id = sub.id;
	this->exp = sub.exp;
	this->hour = sub.hour;
	this->jt = sub.jt;
	this->managerid = sub.managerid;
	return *this;
}

//перегрузка оператора <<
ostream& operator<< (ostream& out, Subemployee& subemployee) {
	out << "Counter: " << subemployee.counter << " ";
	out << "ID: " << subemployee.id << endl;
	out << subemployee.exp << endl;
	out << subemployee.hour << endl;
	out << subemployee.jt << endl;
	out << "managerid: " << subemployee.managerid;
	return out;
}

//перегрузка оператора >>
istream& operator>> (istream& os, Subemployee& subemployee) {
	subemployee.Employee::input();
	cout << "¬ведите ID ”правл€ющего: ";
	os >> subemployee.managerid;
	return os;
}
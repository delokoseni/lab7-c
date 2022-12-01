#include "Experience.h"
#include "checkfileextension.h"
#include <iostream>
#include <fstream>
using namespace std;

//конструктор класса experience со всеми параметрами
Experience::Experience(int workingyears, int army, int maternityleave) {
	if (workingyears >= 0)
		this->workingyears = workingyears;
	else {
		cout << "Указано недопустимое значение workingyears." << endl;
		this->workingyears = 0;
	}
	if (army >= 0)
		this->army = army;
	else {
		cout << "Указано недопустимое значение army." << endl;
		this->army = 0;
	}
	if (maternityleave >= 0)
		this->maternityleave = maternityleave;
	else {
		cout << "Указано недопустимое значение maternityleave." << endl;
		this->maternityleave = 0;
	}
}

//конструктор класса experience с одним параметром
Experience::Experience(int allfields) {
	if (allfields >= 0) {
		workingyears = allfields;
		army = allfields;
		maternityleave = allfields;
	}
	else {
		cout << "Указано недопустимое значение allfields." << endl;
		workingyears = 0;
		army = 0;
		maternityleave = 0;
	}
}

//конструктор класса experience без параметров
Experience::Experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//метод установки значений
void Experience::set(Experience e) {
	this->workingyears = e.workingyears;
	this->army = e.army;
	this->maternityleave = e.maternityleave;
}

//метод ввода класса experience
void Experience::input() {
	int workingyears, army, maternityleave;
	cout << "Введите общий стаж (кол-во лет): ";
	cin >> workingyears;
	cout << "Из них в армии (кол-во лет): ";
	cin >> army;
	cout << "Из них в декретном отпуске(кол - во лет): ";
	cin >> maternityleave;
	workingyears = workingyears - army - maternityleave;
	Experience e(workingyears, army, maternityleave);
	this->set(e);
}

//метод вывода
void Experience::output() {
	cout << "Стаж (отработано лет): " << workingyears << endl;
	cout << "Стаж (кол-во лет в армии): " << army << endl;
	cout << "Стаж (кол-во лет в декретном отпуске): " << maternityleave << endl;
}

//метод возвращающий совокупный стаж
float Experience::allexp() {
	int all;
	all = workingyears + army + maternityleave;
	return all;
};

//перегрузка оператора +
Experience Experience::operator + (Experience e1) {
	workingyears += e1.workingyears;
	maternityleave += e1.maternityleave;
	army += e1.army;
	return *this;
}

//перегрузка оператора ++ префиксный
Experience& Experience::operator++() {
	this->workingyears += 1;
	this->maternityleave += 1;
	this->army += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Experience Experience::operator++(int) {
	Experience temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Experience::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << workingyears << "\t";
	file << army << "\t";
	file << maternityleave << "\t";
}

//метод записи из файла
void Experience::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	try {
		file >> workingyears;
		file >> army;
		file >> maternityleave;
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи  или неверно указано имя файла.\n");
	}
}

ostream& operator<< (ostream& os, Experience& experience) {
	os << "workingyears: " << experience.workingyears << " ";
	os << "army: " << experience.army << " ";
	os << "maternityleave: " << experience.maternityleave << " ";
	return os;
}
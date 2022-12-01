#include "Subordinates.h"
#include "checkfileextension.h"
#include <iostream>
#include <fstream>
using namespace std;


//конструктор класса subordinates со всеми параметрами
Subordinates::Subordinates(int amount, float asos) {
	if (amount >= 0)
		this->amount = amount;
	else {
		cout << "Указано недопустимое значение amount." << endl;
		this->amount = 0;
	}
	if (asos >= 0)
		this->asos = asos;
	else {
		cout << "Указано недопустимое значение asos." << endl;
		this->asos = 0;
	}
}

//конструктор класса subordinates с одним параметром
Subordinates::Subordinates(int allfields) {
	if (allfields >= 0) {
		amount = allfields;
		asos = allfields;
	}
	else {
		cout << "Указано недопустимое значение allfields." << endl;
		amount = 0;
		asos = 0;
	}
}

//конструктор класса subordinates без параметров
Subordinates::Subordinates() {
	amount = 0;
	asos = 0;
}

//метод установки значений
void Subordinates::set(Subordinates s) {
	this->amount = s.amount;
	this->asos = s.asos;
}

//метод ввода класса subordinates
void Subordinates::input() {
	int YesNo, amount;
	float asos;
	cout << "Введите количество подчиненных сотрудника: ";
	cin >> amount;
	if (amount > 0) {
		cout << "Вы знаете средний стаж подчиненных? 1 - да, 0 - нет: ";
		cin >> YesNo;
		if (YesNo == 1) {
			cout << "Введите средний стаж подчиненных сотрудника: ";
			cin >> asos;
		}
		else {
			asos = this->averageseniority(this->amount);
		}
	}
	else
		asos = 0;
	Subordinates s(amount, asos);
	this->set(s);
}

//метод вывода
void Subordinates::output() {
	cout << "Кол-во подчиненных: " << amount << endl;
	cout << "Средний стаж подчиненных: " << asos << endl;
}

//метод подсчета среднего стажа
float Subordinates::averageseniority(int number) {
	float* arr = new float[2 * number];
	int i;
	float avesen = 0;
	cout << "Вводите сначала целое число лет стажа, затем месяцы!" << endl;
	for (i = 0; i < 2 * number; i++) {
		cin >> *(arr + i);
	}
	for (i = 0; i < 2 * number; i += 2) {
		avesen += *(arr + i);
		avesen += *(arr + i + 1) / 12;
	}
	avesen = avesen / number;
	return avesen;
}

//метод возвращающий количество полчиненных
int Subordinates::getamount() {
	return amount;
}

//перегрузка оператора +
Subordinates Subordinates::operator + (Subordinates s1) {
	amount += s1.amount;
	asos += s1.asos;
	return *this;
}

//перегрузка оператора ++ префиксный
Subordinates& Subordinates::operator++() {
	this->amount += 1;
	this->asos += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Subordinates Subordinates::operator++(int) {
	Subordinates temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Subordinates::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << amount << "\t";
	file << asos << "\n";
}

//метод записи из файла
void Subordinates::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	try {
		file >> amount;
		file >> asos;
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи  или неверно указано имя файла.\n");
	}
}
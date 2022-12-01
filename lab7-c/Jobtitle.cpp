#include "Jobtitle.h"
#include "checkfileextension.h"
#include "Subordinates.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//конструктор класса jobtitle со всеми параметрами
Jobtitle::Jobtitle(string jtitle, int hourlycost) {
	this->jtitle = jtitle;
	if (hourlycost >= 0)
		this->hourlycost = hourlycost;
	else {
		cout << "Указано недопустимое значение hourlycost." << endl;
		this->hourlycost = 0;
	}
}

//конструктор класса jobtitle с одним параметром
Jobtitle::Jobtitle(int allfields) {
	if (allfields >= 0) {
		jtitle = to_string(allfields);
		hourlycost = allfields;
		Subordinates s(allfields);
	}
	else {
		cout << "Указано недопустимое значение allfields." << endl;
		jtitle = "";
		hourlycost = 0;
		Subordinates s;
	}
}

//конструктор класса jobtitle без параметров
Jobtitle::Jobtitle() {
	jtitle = "";
	hourlycost = 0;
	Subordinates s;
}

//метод установки значений 
void Jobtitle::set(Jobtitle j) {
	this->jtitle = j.jtitle;
	this->hourlycost = j.hourlycost;
}

//метод ввода класса jobtitle
void Jobtitle::input() {
	string jtitle;
	int hourlycost;
	cout << "Введите должность: ";
	getline(cin, jtitle);
	cout << "Введите стоимость часа работы: ";
	cin >> hourlycost;
	Jobtitle j(jtitle, hourlycost);
	this->set(j);
}

//метод вывода
void Jobtitle::output() {
	cout << "Должность: " << jtitle << endl;
	cout << "Стоимость часа работы: " << hourlycost << endl;
}

//метод сравнения зарплаты с заданной
float Jobtitle::comparisonhc(float hcost) {
	float percent;
	float d = hourlycost;
	percent = d / (hcost / 100) - 100;
	return percent;
}

//метод для редактирования должности
void Jobtitle::editjtitle(string jtitle, string add) {
	int i;
	//строковый поток
	stringstream ss(this->jtitle);
	//посдчет количества слов в строке
	int n = count(this->jtitle.begin(), this->jtitle.end(), ' ') + 1;
	string* words = new string[n];
	this->jtitle = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for (i = 0; i < n; i++) {
		//если строки одинаковые
		if (!(*(words + i)).compare(jtitle)) {
			this->jtitle += add + " ";
		}
		this->jtitle += *(words + i) + " ";
	}
}

//перегрузка оператора +
Jobtitle Jobtitle::operator + (Jobtitle j1) {
	hourlycost += j1.hourlycost;
	jtitle += j1.jtitle;
	return *this;
}

//перегрузка оператора ++ префиксный
Jobtitle& Jobtitle::operator++() {
	this->hourlycost += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Jobtitle Jobtitle::operator++(int) {
	Jobtitle temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Jobtitle::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << jtitle << "\t";
	file << hourlycost << "\t";
}

//метод ввода из файла
void Jobtitle::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	int flag = 0;
	string buff;
	try {
		file >> jtitle;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				hourlycost = stoi(buff);
				flag = 1;
			}
			else {
				jtitle += " ";
				jtitle += buff;
			}
		}
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи  или неверно указано имя файла.\n");
	}

}

ostream& operator<< (ostream& os, Jobtitle& jobtitle) {
	os << "jtitle: " << jobtitle.jtitle << " ";
	os << "hourlycost: " << jobtitle.hourlycost << " ";
	return os;
}
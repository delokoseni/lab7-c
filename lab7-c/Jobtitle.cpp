#include "Jobtitle.h"
#include "checkfileextension.h"
#include "Subordinates.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//����������� ������ jobtitle �� ����� �����������
Jobtitle::Jobtitle(string jtitle, int hourlycost) {
	this->jtitle = jtitle;
	if (hourlycost >= 0)
		this->hourlycost = hourlycost;
	else {
		cout << "������� ������������ �������� hourlycost." << endl;
		this->hourlycost = 0;
	}
}

//����������� ������ jobtitle � ����� ����������
Jobtitle::Jobtitle(int allfields) {
	if (allfields >= 0) {
		jtitle = to_string(allfields);
		hourlycost = allfields;
		Subordinates s(allfields);
	}
	else {
		cout << "������� ������������ �������� allfields." << endl;
		jtitle = "";
		hourlycost = 0;
		Subordinates s;
	}
}

//����������� ������ jobtitle ��� ����������
Jobtitle::Jobtitle() {
	jtitle = "";
	hourlycost = 0;
	Subordinates s;
}

//����� ��������� �������� 
void Jobtitle::set(Jobtitle j) {
	this->jtitle = j.jtitle;
	this->hourlycost = j.hourlycost;
}

//����� ����� ������ jobtitle
void Jobtitle::input() {
	string jtitle;
	int hourlycost;
	cout << "������� ���������: ";
	getline(cin, jtitle);
	cout << "������� ��������� ���� ������: ";
	cin >> hourlycost;
	Jobtitle j(jtitle, hourlycost);
	this->set(j);
}

//����� ������
void Jobtitle::output() {
	cout << "���������: " << jtitle << endl;
	cout << "��������� ���� ������: " << hourlycost << endl;
}

//����� ��������� �������� � ��������
float Jobtitle::comparisonhc(float hcost) {
	float percent;
	float d = hourlycost;
	percent = d / (hcost / 100) - 100;
	return percent;
}

//����� ��� �������������� ���������
void Jobtitle::editjtitle(string jtitle, string add) {
	int i;
	//��������� �����
	stringstream ss(this->jtitle);
	//������� ���������� ���� � ������
	int n = count(this->jtitle.begin(), this->jtitle.end(), ' ') + 1;
	string* words = new string[n];
	this->jtitle = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for (i = 0; i < n; i++) {
		//���� ������ ����������
		if (!(*(words + i)).compare(jtitle)) {
			this->jtitle += add + " ";
		}
		this->jtitle += *(words + i) + " ";
	}
}

//���������� ��������� +
Jobtitle Jobtitle::operator + (Jobtitle j1) {
	hourlycost += j1.hourlycost;
	jtitle += j1.jtitle;
	return *this;
}

//���������� ��������� ++ ����������
Jobtitle& Jobtitle::operator++() {
	this->hourlycost += 1;
	return *this;
}

//���������� ��������� ++ �����������
Jobtitle Jobtitle::operator++(int) {
	Jobtitle temp = *this;
	++* this;
	return temp;
}

//����� ������ � ����
void Jobtitle::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << jtitle << "\t";
	file << hourlycost << "\t";
}

//����� ����� �� �����
void Jobtitle::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
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
		throw exception("� ����� ������������ ������ ��� ������  ��� ������� ������� ��� �����.\n");
	}

}

ostream& operator<< (ostream& os, Jobtitle& jobtitle) {
	os << "jtitle: " << jobtitle.jtitle << " ";
	os << "hourlycost: " << jobtitle.hourlycost << " ";
	return os;
}
#include "Experience.h"
#include "checkfileextension.h"
#include <iostream>
#include <fstream>
using namespace std;

//����������� ������ experience �� ����� �����������
Experience::Experience(int workingyears, int army, int maternityleave) {
	if (workingyears >= 0)
		this->workingyears = workingyears;
	else {
		cout << "������� ������������ �������� workingyears." << endl;
		this->workingyears = 0;
	}
	if (army >= 0)
		this->army = army;
	else {
		cout << "������� ������������ �������� army." << endl;
		this->army = 0;
	}
	if (maternityleave >= 0)
		this->maternityleave = maternityleave;
	else {
		cout << "������� ������������ �������� maternityleave." << endl;
		this->maternityleave = 0;
	}
}

//����������� ������ experience � ����� ����������
Experience::Experience(int allfields) {
	if (allfields >= 0) {
		workingyears = allfields;
		army = allfields;
		maternityleave = allfields;
	}
	else {
		cout << "������� ������������ �������� allfields." << endl;
		workingyears = 0;
		army = 0;
		maternityleave = 0;
	}
}

//����������� ������ experience ��� ����������
Experience::Experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//����� ��������� ��������
void Experience::set(Experience e) {
	this->workingyears = e.workingyears;
	this->army = e.army;
	this->maternityleave = e.maternityleave;
}

//����� ����� ������ experience
void Experience::input() {
	int workingyears, army, maternityleave;
	cout << "������� ����� ���� (���-�� ���): ";
	cin >> workingyears;
	cout << "�� ��� � ����� (���-�� ���): ";
	cin >> army;
	cout << "�� ��� � ��������� �������(��� - �� ���): ";
	cin >> maternityleave;
	workingyears = workingyears - army - maternityleave;
	Experience e(workingyears, army, maternityleave);
	this->set(e);
}

//����� ������
void Experience::output() {
	cout << "���� (���������� ���): " << workingyears << endl;
	cout << "���� (���-�� ��� � �����): " << army << endl;
	cout << "���� (���-�� ��� � ��������� �������): " << maternityleave << endl;
}

//����� ������������ ���������� ����
float Experience::allexp() {
	int all;
	all = workingyears + army + maternityleave;
	return all;
};

//���������� ��������� +
Experience Experience::operator + (Experience e1) {
	workingyears += e1.workingyears;
	maternityleave += e1.maternityleave;
	army += e1.army;
	return *this;
}

//���������� ��������� ++ ����������
Experience& Experience::operator++() {
	this->workingyears += 1;
	this->maternityleave += 1;
	this->army += 1;
	return *this;
}

//���������� ��������� ++ �����������
Experience Experience::operator++(int) {
	Experience temp = *this;
	++* this;
	return temp;
}

//����� ������ � ����
void Experience::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << workingyears << "\t";
	file << army << "\t";
	file << maternityleave << "\t";
}

//����� ������ �� �����
void Experience::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	try {
		file >> workingyears;
		file >> army;
		file >> maternityleave;
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������  ��� ������� ������� ��� �����.\n");
	}
}

ostream& operator<< (ostream& os, Experience& experience) {
	os << "workingyears: " << experience.workingyears << " ";
	os << "army: " << experience.army << " ";
	os << "maternityleave: " << experience.maternityleave << " ";
	return os;
}
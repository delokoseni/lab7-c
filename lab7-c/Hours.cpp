#include "Hours.h"
#include "Salary.h"
#include "checkfileextension.h"
#include <iostream>
#include <fstream>
using namespace std;

//����������� ������ hours �� ����� �����������
Hours::Hours(int normal, int overtime, int weekends) {
	if (normal >= 0)
		this->normal = normal;
	else {
		cout << "������� ������������ �������� normal." << endl;
		this->normal = 0;
	}
	if (overtime >= 0)
		this->overtime = overtime;
	else {
		cout << "������� ������������ �������� overtime." << endl;
		this->overtime = 0;
	}
	if (weekends >= 0)
		this->weekends = weekends;
	else {
		cout << "������� ������������ �������� weekends." << endl;
		this->weekends = 0;
	}
}

//����������� ������ hours � ����� ����������
Hours::Hours(int allfields) {
	if (allfields >= 0) {
		normal = allfields;
		overtime = allfields;
		weekends = allfields;
	}
	else {
		cout << "������� ������������ �������� allfields." << endl;
		normal = 0;
		overtime = 0;
		weekends = 0;
	}
}

//����������� ������ hours ��� ����������
Hours::Hours() {
	normal = 0;
	overtime = 0;
	weekends = 0;
}

//����� ��������� ��������
void Hours::set(Hours h) {
	this->normal = h.normal;
	this->overtime = h.overtime;
	this->weekends = h.weekends;
}

//����� ����� ������ hours
void Hours::input() {
	int normal, overtime, weekends;
	cout << "������� ���-�� ������������ �� ����� �����(�����): ";
	cin >> normal;
	cout << "������� ���-�� ������������ �����: ";
	cin >> overtime;
	cout << "������� ���-�� ������������ �� ����� ����� � ��������: ";
	cin >> weekends;
	Hours h(normal, overtime, weekends);
	this->set(h);
}

//����� ������
void Hours::output() {
	cout << "���������� ����� �� �����(�� �������): " << normal << endl;
	cout << "���������� ����� �� �����(�����������): " << overtime << endl;
	cout << "���������� ����� �� �����(� �������� ���): " << weekends << endl;
}

//����� ��������� ������������ �� ����� �����
int Hours::allhours() {
	int all = 0;
	all += normal;
	all += overtime;
	all += weekends;
	return all;
}

//����� ������������ �������� �� ��� ������������ ����
int Hours::hoursmoney(Jobtitle jt, Salary sal) {
	int salary = 0;
	//������������� ������������� �������
	salary += normhcost(*(this), jt);
	salary += sal.overtimeweekends(overtime, weekends);
	return salary;
}

//���������� ��������� +
Hours Hours::operator + (Hours h2) {
	normal += h2.normal;
	overtime += h2.overtime;
	weekends += h2.weekends;
	return *this;
}

//���������� ��������� ++ ����������
Hours& Hours::operator++() {
	this->normal += 1;
	this->overtime += 1;
	this->weekends += 1;
	return *this;
}

//���������� ��������� ++ �����������
Hours Hours::operator++(int) {
	Hours temp = *this;
	++* this;
	return temp;
}

//����� ������ � ����
void Hours::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << normal << "\t";
	file << overtime << "\t";
	file << weekends << "\t";
}

//����� ������ �� �����
void Hours::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	try {
		file >> normal;
		file >> overtime;
		file >> weekends;
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������  ��� ������� ������� ��� �����.\n");
	}
}

ostream& operator<< (ostream& os, Hours& hours) {
	os << "normal: " << hours.normal << " ";
	os << "overtime: " << hours.overtime << " ";
	os << "weekends: " << hours.weekends << " ";
	return os;
}
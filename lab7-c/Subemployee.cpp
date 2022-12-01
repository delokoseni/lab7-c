#include "Subemployee.h"
#include "Employee.h"
#include <fstream>
using namespace std;

//����������� ������ employee ��� ����������
Subemployee::Subemployee() : Employee() {
	managerid = 0;
}


//����������� ������ employee �� ����� �����������
Subemployee::Subemployee(Experience e, Hours h, Jobtitle j, int managerid) : Employee(e, h, j) {
	this->managerid = managerid;
}

//����������� ������ employee � ����� ����������
Subemployee::Subemployee(int allfields) : Employee(allfields) {
	if (allfields >= 0) {
		managerid = allfields;
	}
	else {
		managerid = 0;
	}
}

//����� ������ Subemployee
void Subemployee::output() {
	this->Employee::output();
	cout << "ID ������������: " << managerid << endl;
}

//����� �����
void Subemployee::input() {
	this->Employee::input();
	cout << "������� ID ������������: ";
	cin >> managerid;
}


//����� ������ � ����
void Subemployee::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << id << "\t";
	exp.tofile(file, filename);
	hour.tofile(file, filename);
	jt.tofile(file, filename);
	file << managerid << "\n";
}

//����� ������ �� �����
void Subemployee::getfromfile(ifstream& file, string filename) {
	try {
		this->Employee::getfromfile(file, filename);
		file >> managerid;
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������.\n");
	}
}

//���������� ��������� ������������
Subemployee Subemployee::operator= (Subemployee sub) {
	this->id = sub.id;
	this->exp = sub.exp;
	this->hour = sub.hour;
	this->jt = sub.jt;
	this->managerid = sub.managerid;
	return *this;
}

//���������� ��������� <<
ostream& operator<< (ostream& out, Subemployee& subemployee) {
	out << "Counter: " << subemployee.counter << " ";
	out << "ID: " << subemployee.id << endl;
	out << subemployee.exp << endl;
	out << subemployee.hour << endl;
	out << subemployee.jt << endl;
	out << "managerid: " << subemployee.managerid;
	return out;
}

//���������� ��������� >>
istream& operator>> (istream& os, Subemployee& subemployee) {
	subemployee.Employee::input();
	cout << "������� ID ������������: ";
	os >> subemployee.managerid;
	return os;
}
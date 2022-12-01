#include "Employee.h"
#include <fstream>
using namespace std;

int Employee::counter = 0;

//����������� ������ employee �� ����� �����������
Employee::Employee(Experience e, Hours h, Jobtitle j) {
	counter++;
	id = counter;
	exp = e;
	hour = h;
	jt = j;
}

//����������� ������ employee � ����� ����������
Employee::Employee(int allfields) {
	counter++;
	id = counter;
	if (allfields >= 0) {
		Experience e(allfields);
		Hours h(allfields);
		Jobtitle j(allfields);
		exp = e;
		hour = h;
		jt = j;
	}
	else {
		cout << "������� ������������ �������� allfields." << endl;
		Experience e;
		Hours h;
		Jobtitle j;
		exp = e;
		hour = h;
		jt = j;
	}
}

//����������� ������ employee ��� ����������
Employee::Employee() {
	counter++;
	id = counter;
	Experience e;
	Hours h;
	Jobtitle j;
	exp = e;
	hour = h;
	jt = j;
}

//����� ������ Employee
void Employee::output() {
	cout << "ID: " << id << endl;
	exp.output();
	hour.output();
	jt.output();
}

//����� ����� Employee
void Employee::input() {
	exp.input();
	hour.input();
	while (getchar() != '\n');
	jt.input();
}

//����� ������ �������� ���������� �����������
void Employee::printcounter() {
	cout << "���������� �����������: " << counter << endl;
}

//����� ���������� ���������� �����������
void Employee::minuscounter() {
	counter--;
	cout << "���������� ����������� ��������� �� 1." << endl;
}
//����� ���������� ���������� �����������
void Employee::minuscounter(int number) {
	int x = counter;
	counter = counter - number;
	cout << "���������� ����������� ��������� c " << x << " �� " << counter << endl;
}

//����� ��������� � ������ ����������� ������
void Employee::editjtitle(string jtitle, string add) {
	jt.editjtitle(jtitle, add);
}

//�����, ������������ �������� ����� ���������
Employee* Employee::get() {
	return this;
}

//�����, ������������ �������� ����� ������
Employee& Employee::getadress() {
	return *this;
}

//����� ������ �� �����
void Employee::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	try {
		file >> id;
		exp.getfromfile(file, filename);
		hour.getfromfile(file, filename);
		jt.getfromfile(file, filename);
	}
	catch (exception& e) {
		throw exception("� ����� ������������ ������ ��� ������ ��� ������� ������� ��� �����.\n");
	}
}

//����� �������� ��������
int Employee::getsalary(Salary sal) {
	int salary = 0;
	salary += hour.hoursmoney(jt, sal);
	salary = sal.allmoney(salary, exp);
	return salary;
}

//����� �������� ������ (�������� ��� ���)
string Employee::getpremium(int houramount) {
	if (hour.allhours() < houramount)
		return "������ �� ��������";
	else
		return "������ ��������";
}

//����� ������������ ���� exp
Experience Employee::getexp() {
	return this->exp;
}
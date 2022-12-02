#include "Managemployee.h"

Managemployee::Managemployee() : Subemployee() {
	Subordinates subs;
	subordinates = subs;
	vector<Employee*> vec(10);
	arr = vec;
}

Managemployee::Managemployee(int allfields) : Subemployee(allfields) {
	if (allfields >= 1) {
		Subordinates subs(allfields);
		subordinates = subs;
	}
	else {
		Subordinates subs;
		subordinates = subs;
	}
	vector<Employee*> vec(allfields);
	arr = vec;
	Subemployee subemployee(allfields);
	for (int j = 0; j < subordinates.getamount(); j++) {
		arr[j] = &subemployee;
	}
}

Managemployee::Managemployee(Experience exp, Hours h, Jobtitle j, int managerid,
		Subordinates subordinates, vector<Employee*> arr) : Subemployee(exp, h, j, managerid) {
	this->subordinates = subordinates;
	this->arr = arr;
}

void Managemployee::output() {
	this->Subemployee::output();
	subordinates.output();
	cout << "������ �����������:\n";
	for (int j = 0; j < subordinates.getamount(); j++) {
		(*arr[j]).output();
	}
}

void Managemployee::input(){
	this->Subemployee::input();
	subordinates.input();
	for (int j = 0; j < subordinates.getamount(); j++) {
		cout << "������� ������������: ";
		(*arr[j]).input();
	}
}

int Managemployee::getsalary(Salary sal) {
	int salary = this->Employee::getsalary(sal);
	salary += sal.allmoney(salary, subordinates);
	return salary;
}

Managemployee Managemployee::operator=(Subemployee sub) {
	Subemployee::operator=(sub);
	return *this;
}

//���������� ��������� <<
ostream& Managemployee::operator<< (ostream& out) {
	Subemployee s = *this;
	out << s;
	out << "������ �����������:\n";
	for (int j = 0; j < subordinates.getamount(); j++) {
		out << this->arr[j] << endl;
	}
	return out;
}
#include "Managemployee.h"

Managemployee::Managemployee() : Subemployee() {
	Subordinates subs;
	subordinates = subs;
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
	Subemployee subemployee(allfields);
	for (int j = 0; j < allfields; j++) {
		arr.push_back(subemployee);
	}
}

Managemployee::Managemployee(Experience exp, Hours h, Jobtitle j, int managerid,
		Subordinates subordinates, vector<Subemployee> arr) : Subemployee(exp, h, j, managerid) {
	this->subordinates = subordinates;
	this->arr = arr;
}

void Managemployee::output() {
	this->Subemployee::output();
	subordinates.output();
	cout << "Массив подчиненных:\n";
	for (int j = 0; j < arr.size(); j++) {
		cout << arr[j] << endl;
	}
}
void Managemployee::input(){
	this->Subemployee::input();
	subordinates.input();
	for (int j = 0; j < subordinates.getamount(); j++) {
		cout << "Введите подчиненного: ";
		cin >> arr[j];
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
//перегрузка оператора <<
ostream& Managemployee::operator<< (ostream& out) {
	Subemployee s = *this;
	out << s;
	out << "Массив подчиненных:\n";
	for (int j = 0; j < arr.size(); j++) {
		out << this->arr[j] << endl;
	}
	return out;
}
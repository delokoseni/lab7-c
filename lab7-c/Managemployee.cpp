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
	for (int j = 0; j < arr.size(); j++) {
		this->arr[j] = arr[j];
	}
}

//}
//void output() override {
//	this->Subemployee::output();
//	subordinates.output();
//	cout << "Массив подчиненных:\n";
//	for (int j = 0; j < i; j++) {
//		cout << arr[j] << endl;
//	}
//}
//void input() override {
//	this->Subemployee::input();
//	subordinates.input();
//	for (int j = 0; j < i; j++) {
//		cout << "Введите подчиненного: ";
//		cin >> arr[j];
//	}
//}
//int getsalary(Salary sal) override {
//	int salary = this->Employee::getsalary(sal);
//	salary += sal.allmoney(salary, subordinates);
//	return salary;
//}
//Managemployee operator=(Subemployee sub) {
//	Subemployee::operator=(sub);
//	return *this;
//}
////перегрузка оператора <<
//ostream& operator<< (ostream& out) {
//	Subemployee s = *this;
//	out << s;
//	out << "Массив подчиненных:\n";
//	for (int j = 0; j < i; j++) {
//		out << this->arr[j] << endl;
//	}
//	return out;
//}
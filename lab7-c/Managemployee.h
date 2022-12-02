#pragma once
#include "Subemployee.h"
#include <vector>

class Managemployee : public Subemployee
{
	using Subemployee::operator =;
private:
	Subordinates subordinates;
	vector<Employee*> arr;
public:
	Managemployee();
	Managemployee(int allfields);
	Managemployee(Experience exp, Hours h, Jobtitle j, int managerid, Subordinates subordinates, vector<Employee*> arr);
	void output() override;
	void input() override;
	int getsalary(Salary sal) override;
	Managemployee operator=(Subemployee sub);
	ostream& operator<< (ostream& out);
};
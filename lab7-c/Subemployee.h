#pragma once
#include "Employee.h"

class Subemployee : public Employee
{
	friend ostream& operator<< (ostream& os, Subemployee& subemployee);
	friend istream& operator>> (istream& os, Subemployee& subemployee);
private:
	int managerid;
public:
	Subemployee();
	Subemployee(int allfields);
	Subemployee(Experience exp, Hours h, Jobtitle j, int managerid);
	virtual void output() override;
	virtual void input() override;
	void tofile(ofstream& file, string filename) override;
	void getfromfile(ifstream& file, string filename) override;
	Subemployee operator= (Subemployee sub);
};


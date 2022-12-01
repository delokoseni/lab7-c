#pragma once
#include "Experience.h"
#include "Hours.h"
#include "Jobtitle.h"
#include "Subordinates.h"
#include "checkfileextension.h"
#include <iostream>
#include <fstream>
using namespace std;

class Employee {
public:
	Employee();
	Employee(int allfields);
	Employee(Experience e, Hours h, Jobtitle j);
	virtual void output();
	virtual void input();
	virtual int getsalary(Salary sal);
	string getpremium(int houramount);
	void printcounter();
	void minuscounter();
	void minuscounter(int number);
	void editjtitle(string jtitle, string add);
	Employee* get();
	Employee& getadress();
	virtual void tofile(ofstream& file, string filename) = 0;
	virtual void getfromfile(ifstream& file, string filename);
	Experience getexp();
protected:
	static int counter;
	int id; //�������������� �����
	Experience exp; //����
	Hours hour; //������������ �� ����� ����
	Jobtitle jt; //���������
};


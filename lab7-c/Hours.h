#pragma once
#include "Salary.h"
#include <string>
#include <fstream>
using namespace std;

class Jobtitle;

class Hours
{
	friend int normhcost(Hours hours, Jobtitle jobtitle);
	friend ostream& operator<< (ostream& os, Hours& subemployee);
public:
	Hours(int n, int o, int w);
	Hours(int allfields);
	Hours();
	void input();
	void output();
	int allhours();
	void set(Hours hours);
	int hoursmoney(Jobtitle jobtitle, Salary salary);
	Hours& operator++(); //префиксный
	Hours operator++(int); //постфиксный
	Hours operator + (Hours hours);
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
};


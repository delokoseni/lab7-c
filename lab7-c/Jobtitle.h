#pragma once
#include <fstream>
#include <string>
using namespace std;

class Hours;

class Jobtitle
{
	friend int normhcost(Hours hours, Jobtitle jobtititle);
	friend ostream& operator<< (ostream& os, Jobtitle& jobtitle);
public:
	Jobtitle(string jtitle, int hourlycost);
	Jobtitle(int allfields);
	Jobtitle();
	void input();
	void output();
	float comparisonhc(float hcost);
	void set(Jobtitle j);
	int getamount();
	void editjtitle(string jtitle, string add);
	Jobtitle operator + (Jobtitle jobtitle);
	Jobtitle& operator++(); //префиксный
	Jobtitle operator++(int); //постфиксный
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	string jtitle; //наименование должности
	int hourlycost; //стоимость часа работы
};

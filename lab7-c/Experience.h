#pragma once
#include <fstream>
using namespace std;

class Experience
{
	friend ostream& operator<< (ostream& os, Experience& experience);
public:
	Experience(int w, int a, int m);
	Experience(int x);
	Experience();
	void input();
	void output();
	float allexp();
	void set(Experience e);
	Experience operator + (Experience e1);
	Experience& operator++(); //префиксный
	Experience operator++(int); //постфиксный
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	int workingyears; //кол-во реально отработанных лет
	int army; //кол-во лет в армии, если сохранялось рабочее место
	int maternityleave; //кол-во лет в декретном отпуске, если сохранялось рабочее место
};



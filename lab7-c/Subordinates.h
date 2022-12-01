#pragma once
#include <fstream>
using namespace std;

class Subordinates
{
public:
	Subordinates(int amount, float asos);
	Subordinates(int allfields);
	Subordinates();
	void input();
	void output();
	float averageseniority(int number);
	void set(Subordinates subordinates);
	int getamount();
	Subordinates operator + (Subordinates subordinates);
	Subordinates& operator++(); //����������
	Subordinates operator++(int); //�����������
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	int amount; //���-�� �����������
	float asos; //average seniority of subordinates - ������� ���� �����������
};
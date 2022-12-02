#include <iostream>
#include <Windows.h>
#include "Managemployee.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Experience exp(50);
    Hours h(50);
    Jobtitle j(50);
    int managerid = 19;
    Subordinates subordinates(4);

    Subemployee sub1(1), sub2(2);
    Managemployee man1(3), man2(4);
    vector<Employee*> arr{ &sub1, &sub2, &man1, &man2 };
    Managemployee managemployee(exp, h, j, managerid, subordinates, arr), manag(1);
    managemployee.output();
    manag.input();
    return 0;
}
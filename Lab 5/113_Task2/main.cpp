#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Employee emp1, emp2;
    emp1.setInfo("Farhan", "15/05/1990", 50000);
    emp2.setInfo("Anindo", "10/08/2000", 120000);
    cout << "Employee 1 Info:" << endl;
    emp1.getInfo();
    cout << endl;
    cout << "Employee 2 Info:" << endl;
    emp2.getInfo();
    cout << endl;
    Employee elder = emp1.compareAge(emp2);
    cout << "Elder Employee Info:" << endl;
    elder.getInfo();
    return 0;
}

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string dateOfBirth;
    int salary;
public:
    void setName(const string& empName);
    string getName() const;
    void setDateOfBirth(const string& dob);
    string getDateOfBirth() const;
    void setSalary(int empSalary);
    int getSalary() const;
    void setInfo(const string& empName, const string& dob, int empSalary);
    void getInfo() const;
    const Employee compareAge(const Employee& other) const;
};
#endif

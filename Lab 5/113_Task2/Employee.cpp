#include "Employee.h"
#include <iostream>
#include<string>
using namespace std;

void Employee::setName(const string& empName){
    if (empName.length() > 2)
        name = empName;
    else
        name = "John Doe";
}
string Employee::getName() const{
    return name;
}
void Employee::setDateOfBirth(const string& dob){
    int year = stoi(dob.substr(6, 4));
    if (2024 - year >= 18){
        dateOfBirth = dob;
    }
    else{
        dateOfBirth = "01/01/2002";
    }
}
string Employee::getDateOfBirth() const{
    return dateOfBirth;
}
void Employee::setSalary(int empSalary){
    if (empSalary >= 10000 && empSalary <= 100000){
        salary = empSalary;
    }
    else{
        salary = 10000;
    }
}
int Employee::getSalary() const{
    return salary;
}
void Employee::setInfo(const string& empName, const string& dob, int empSalary){
    setName(empName);
    setDateOfBirth(dob);
    setSalary(empSalary);
}

void Employee::getInfo() const{
    cout<<"Name: "<<getName()<<endl;
    cout<<"Date of Birth: "<<getDateOfBirth()<<endl;
    cout<<"Salary: BDT "<<getSalary()<<endl;
}
const Employee Employee::compareAge(const Employee& other) const{
    int thisYear = stoi(dateOfBirth.substr(6, 4));
    int otherYear = stoi(other.dateOfBirth.substr(6, 4));
    if (thisYear<otherYear) {
        return *this;
    }
    else {
        return other;
    }
}

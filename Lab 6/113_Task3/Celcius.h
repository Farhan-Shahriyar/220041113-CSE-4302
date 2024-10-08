#ifndef CELCIUS_H
#define CELCIUS_H
#include<bits/stdc++.h>
using namespace std;

class Kelvin;
class Fahrenheit;

class Celcius{
private:
    double temp;
public:
    Celcius(double temp1 = 0);
    void Assign(double Set);
    void display();
    operator Fahrenheit() const;
    operator Kelvin() const;
};

#endif

#ifndef KELVIN_H
#define KELVIN_H
#include<bits/stdc++.h>
using namespace std;

class Fahrenheit;
class Celcius;

class Kelvin{
private:
    double temp;
public:
    Kelvin(double temp1 = 0);
    void Assign(double Set);
    void display();
    operator Fahrenheit() const;
    operator Celcius() const;
};

#endif

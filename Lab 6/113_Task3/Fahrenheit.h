#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H
#include<bits/stdc++.h>
using namespace std;

class Celcius;
class Kelvin;

class Fahrenheit{
private:
    double temp;
public:
    Fahrenheit(double temp1 = 0);
    void Assign(double Set);
    void display();
    operator Celcius() const;
    operator Kelvin() const;
};

#endif

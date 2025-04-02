#include "Celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    Celcius c1;
    c1.Assign(50);
    c1.display();
    Fahrenheit f1 = c1;
    f1.display();
    Kelvin k1 = c1;
    k1.display();
    f1.Assign(-500);
    f1.display();
    c1 = f1;
    c1.display();
    k1.Assign(0);
    k1.display();
    return 0;
}

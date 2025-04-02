#include "Celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include<bits/stdc++.h>
using namespace std;

Fahrenheit :: Fahrenheit(double temp1){
    temp = temp1;
}

void Fahrenheit :: Assign(double Set){
    if(Set<-459.67){
        cout<<"Temp is lower than absolute zero"<<endl;
    }
    else{
        temp = Set;
    }
    return;
}

void Fahrenheit :: display(){
    cout<<"The temperature is "<<temp<<" Fahrenheit"<<endl;
    return;
}

Fahrenheit :: operator Celcius() const{
    return Celcius((temp-32)*5.0/9.0);
}

Fahrenheit :: operator Kelvin() const{
    return Kelvin(((temp-32)*5.0/9.0)+273.15);
}


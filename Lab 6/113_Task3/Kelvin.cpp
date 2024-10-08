#include "Celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include<bits/stdc++.h>
using namespace std;

Kelvin :: Kelvin(double temp1){
    temp = temp1;
}

void Kelvin :: Assign(double Set){
    if(Set<0){
        cout<<"Temp is lower than absolute zero"<<endl;
    }
    else{
        temp = Set;
    }
    return;
}

void Kelvin :: display(){
    cout<<"The temperature is "<<temp<<" Kelvin"<<endl;
    return;
}

Kelvin :: operator Fahrenheit() const{
    return Fahrenheit((temp-273.15)*9.0/5.0+32);
}

Kelvin :: operator Celcius() const{
    return Celcius(temp-273.15);
}


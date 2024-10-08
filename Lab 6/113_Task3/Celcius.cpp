#include "Celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include<bits/stdc++.h>
using namespace std;

Celcius :: Celcius(double temp1){
    temp = temp1;
}

void Celcius :: Assign(double Set){
    if(Set<-273.15){
        cout<<"Temp is lower than absolute zero"<<endl;
    }
    else{
        temp = Set;
    }
    return;
}

void Celcius :: display(){
    cout<<"The temperature is "<<temp<<" Celcius"<<endl;
    return;
}

Celcius :: operator Fahrenheit() const{
    return Fahrenheit(temp*9.0/5.0+32);
}

Celcius :: operator Kelvin() const{
    return Kelvin(temp+273.15);
}


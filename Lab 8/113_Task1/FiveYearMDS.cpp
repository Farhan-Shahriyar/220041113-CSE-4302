#include "FiveYearMDS.h"
#include<bits/stdc++.h>
using namespace std;

FiveYearMDS::FiveYearMDS(string name, float initial, float ir, float maxir): MonthlyDepositScheme(name, initial, ir), maximuminterest(maxir){}

FiveYearMDS::~FiveYearMDS(){}

void FiveYearMDS::setmaximuminterest(float rate){
    if(rate>=0){
        maximuminterest = rate;
    }
    else{
        cout<<"Invalid maximum interest rate"<<endl;
    }
}

float FiveYearMDS::getmaximuminterest() const{
    return maximuminterest;
}

void FiveYearMDS::description() const{
    cout<<"Five year monthly deposit scheme with a maximum interest rate of: "<<maximuminterest<<endl;
}

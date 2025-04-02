#include "TwoYearMDS.h"
#include<bits/stdc++.h>
using namespace std;

TwoYearMDS::TwoYearMDS(string name, float initial, float ir, float maxir): MonthlyDepositScheme(name, initial, ir), maximuminterest(maxir){}

TwoYearMDS::~TwoYearMDS(){}

void TwoYearMDS::setmaximuminterest(float rate){
    if(rate>=0){
        maximuminterest = rate;
    }
    else{
        cout<<"Invalid maximum interest rate"<<endl;
    }
}

float TwoYearMDS::getmaximuminterest() const{
    return maximuminterest;
}

void TwoYearMDS::description() const{
    cout<<"Two year monthly deposit scheme with a maximum interest rate of: "<<maximuminterest<<endl;
}

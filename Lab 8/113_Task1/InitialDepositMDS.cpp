#include "InitialDepositMDS.h"
#include<bits/stdc++.h>
using namespace std;

InitialDepositMDS::InitialDepositMDS(string name, float initial, float ir, float maxir, float ida) :  MonthlyDepositScheme(name, initial, ir), maximuminterest(maxir){}

InitialDepositMDS::~InitialDepositMDS(){}

void InitialDepositMDS::setmaximuminterest(float rate){
    if(rate>=0){
        maximuminterest = rate;
    }
    else{
        cout<<"Invalid interest rate"<<endl;
    }
}

void InitialDepositMDS::setinitialDepositAmount(float amount){
    if(amount>=0){
        initialDepositAmount = amount;
    }
    else{
        cout<<"Initial Deposit amount is invalid"<<endl;
    }
}

float InitialDepositMDS::getmaximuminterest() const{
    return maximuminterest;
}

float InitialDepositMDS::getinitialDepositAmount() const{
    return initialDepositAmount;
}

void InitialDepositMDS::description() const{
    cout<<"Initial deposit monthly deposit scheme with a maximum interest rate of: "<<maximuminterest<<endl;
}

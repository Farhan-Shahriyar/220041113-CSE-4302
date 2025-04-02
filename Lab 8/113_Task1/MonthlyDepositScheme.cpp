#include "MonthlyDepositScheme.h"
#include<bits/stdc++.h>
using namespace std;

int MonthlyDepositScheme::nextAccount = 1;

MonthlyDepositScheme::MonthlyDepositScheme(string name, float initial, float ir) : Account(name, initial), interestRate(ir){
    accountNo = to_string(accountPrefix) + "-" + to_string(nextAccount++);
    nextAccount++;
}

MonthlyDepositScheme::~MonthlyDepositScheme(){}

void MonthlyDepositScheme::setinterestRate(float rate){
    if(rate>=0){
        interestRate = rate;
    }
    else{
        cout<<"Invalid interest rate"<<endl;
    }
}

void MonthlyDepositScheme::setmonthlyDepositAmount(float amount){
    if(amount>=0){
        monthlyDepositAmmount = amount;
    }
    else{
        cout<<"Invalid monthly deposit amount"<<endl;
    }
}

float MonthlyDepositScheme::getinterestRate() const{
    return interestRate;
}

float MonthlyDepositScheme::getmonthlyDepositAmount() const{
    return monthlyDepositAmmount;
}

int MonthlyDepositScheme::getaccountPrefix() const{
    return accountPrefix;
}

int MonthlyDepositScheme::getnextAccountno() const{
    return nextAccount;
}

void MonthlyDepositScheme::description() const{
    cout<<"Monthly deposit scheme with a monthly deposit amount of: "<<monthlyDepositAmmount<<endl;
}

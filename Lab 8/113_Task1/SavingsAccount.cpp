#include "SavingsAccount.h"
#include<bits/stdc++.h>
using namespace std;

int SavingsAccount::nextAccount = 1;

SavingsAccount::SavingsAccount(string name, float initial) : Account(name, initial){
    accountNo = to_string(accountPrefix) + "-" + to_string(nextAccount++);
    nextAccount++;
}

SavingsAccount::~SavingsAccount(){}

void SavingsAccount::setinterestRate(float rate){
    if(rate>=0){
        interestRate = rate;
    }
    else{
        cout<<"Invalid interest rate"<<endl;
    }
}

void SavingsAccount::setmonthlyDepositAmount(float amount){
    if(amount>=0){
        monthlyDepositAmmount = amount;
    }
    else{
        cout<<"Invalid monthly deposit amount"<<endl;
    }
}

float SavingsAccount::getinterestRate() const{
    return interestRate;
}

float SavingsAccount::getmonthlyDepositAmount() const{
    return monthlyDepositAmmount;
}

int SavingsAccount::getaccountPrefix() const{
    return accountPrefix;
}

int SavingsAccount::getnextAccountno() const{
    return nextAccount;
}

void SavingsAccount::description() const{
    cout<<"Savings account with an interest rate of: "<<interestRate<<endl;
}

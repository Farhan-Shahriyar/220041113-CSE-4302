#include "LoanAccount.h"
#include<bits/stdc++.h>
using namespace std;

int LoanAccount::nextAccount = 1;

LoanAccount::LoanAccount(string name, float initial) : Account(name, initial){
    accountNo = to_string(accountPrefix) + "-" + to_string(nextAccount++);
    nextAccount++;
}

LoanAccount::~LoanAccount(){}

void LoanAccount::setinterestRate(float rate){
    if(rate>=0){
        interestRate = rate;
    }
    else{
        cout<<"Invalid interest rate"<<endl;
    }
}

void LoanAccount::setmonthlyDepositAmount(float amount){
    if(amount>=0){
        monthlyDepositAmmount = amount;
    }
    else{
        cout<<"Invalid monthly deposit amount"<<endl;
    }
}

float LoanAccount::getinterestRate() const{
    return interestRate;
}

float LoanAccount::getmonthlyDepositAmount() const{
    return monthlyDepositAmmount;
}

int LoanAccount::getaccountPrefix() const{
    return accountPrefix;
}

int LoanAccount::getnextAccountno() const{
    return nextAccount;
}

void LoanAccount::description() const{
    cout<<"Loan account with an interest rate of: "<<interestRate<<endl;
}

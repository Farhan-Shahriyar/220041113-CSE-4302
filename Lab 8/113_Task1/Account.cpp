#include "Account.h"
#include<bits/stdc++.h>
using namespace std;

Account::Account(string name, float initial) : accountName(name), balance(initial){}

Account::~Account(){}

string Account::getaccountNo() const{
    return accountNo;
}
string Account::getaccountName() const{
    return accountName;
}
float Account::getbalance() const{
    return balance;
}

void Account::setaccountName(string name){
    accountName = name;
}

void Account::setbalance(float newbalance){
    if(newbalance>=0){
        balance = newbalance;
    }
    else{
        cout<<"Invalid amount"<<endl;
    }
}

void Account::description() const{
    cout<<"This is the base class: Account"<<endl;
}



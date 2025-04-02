#include "CurrentAccount.h"
#include<bits/stdc++.h>
using namespace std;

int CurrentAccount::nextAccount = 1;

CurrentAccount::CurrentAccount(string name, float initial) : Account(name, initial){
    accountNo = to_string(accountPrefix) + "-" + to_string(nextAccount++);
    nextAccount++;
}

CurrentAccount::~CurrentAccount(){}

int CurrentAccount::getaccountPrefix() const{
    return accountPrefix;
}

int CurrentAccount::getnextAccountno() const{
    return nextAccount;
}

void CurrentAccount::description() const{
    cout<<"Current account"<<endl;
}

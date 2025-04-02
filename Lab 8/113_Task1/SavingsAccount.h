#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"
#include<bits/stdc++.h>
using namespace std;

class SavingsAccount : public Account{
private:
    float interestRate;
    float monthlyDepositAmmount;
    const static int accountPrefix = 200;
    static int nextAccount;
public:
    SavingsAccount(string name, float initial);
    ~SavingsAccount();
    void setinterestRate(float rate);
    void setmonthlyDepositAmount(float amount);
    float getinterestRate() const;
    float getmonthlyDepositAmount() const;
    int getaccountPrefix() const;
    int getnextAccountno() const;
    void description() const;
};

#endif

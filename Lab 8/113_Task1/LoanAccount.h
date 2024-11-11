#ifndef LOANACCOUNT_H
#define LOANACCOUNT_H
#include "Account.h"
#include<bits/stdc++.h>
using namespace std;

class LoanAccount : public Account{
private:
    float interestRate;
    float monthlyDepositAmmount;
    const static int accountPrefix = 900;
    static int nextAccount;
public:
    LoanAccount(string name, float initial);
    ~LoanAccount();
    void setinterestRate(float rate);
    void setmonthlyDepositAmount(float amount);
    float getinterestRate() const;
    float getmonthlyDepositAmount() const;
    int getaccountPrefix() const;
    int getnextAccountno() const;
    void description() const;
};



#endif


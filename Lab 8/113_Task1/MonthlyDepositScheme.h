#ifndef MONTHLYDEPOSITSCHEME_H
#define MONTHLYDEPOSITSCHEME_H
#include "Account.h"
#include<bits/stdc++.h>
using namespace std;

class MonthlyDepositScheme : public Account{
private:
    float interestRate;
    float monthlyDepositAmmount;
    const static int accountPrefix = 300;
    static int nextAccount;
public:
    MonthlyDepositScheme(string name, float initial, float ir);
    ~MonthlyDepositScheme();
    void setinterestRate(float rate);
    void setmonthlyDepositAmount(float amount);
    float getinterestRate() const;
    float getmonthlyDepositAmount() const;
    int getaccountPrefix() const;
    int getnextAccountno() const;
    void description() const;
};



#endif

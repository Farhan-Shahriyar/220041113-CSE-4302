#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H
#include "Account.h""
#include<bits/stdc++.h>
using namespace std;

class CurrentAccount : public Account{
private:
    const static int serviceCharge = 100;
    const static int accountPrefix = 100;
    static int nextAccount;
public:
    CurrentAccount(string name, float initial);
    ~CurrentAccount();
    int getaccountPrefix() const;
    int getnextAccountno() const;
    void description() const;
};

#endif

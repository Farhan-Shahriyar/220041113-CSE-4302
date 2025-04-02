#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<bits/stdc++.h>
using namespace std;

class Account{
private:
    string accountName;
    float balance;
protected:
    string accountNo;
public:
    Account(string name, float initial);
    ~Account();
    string getaccountNo() const;
    string getaccountName() const;
    float getbalance() const;
    void setaccountName(string name);
    void setbalance(float newbalance);
    void description() const;
};

#endif

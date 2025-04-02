#ifndef INITIALDEPOSITMDS_H
#define INITIALDEPOSITMDS_H
#include "MonthlyDepositScheme.h"
#include<bits/stdc++.h>
using namespace std;

class InitialDepositMDS : public MonthlyDepositScheme{
private:
    float maximuminterest;
    float initialDepositAmount;
public:
    InitialDepositMDS(string name, float initial, float ir, float maxir, float ida);
    ~InitialDepositMDS();
    void setmaximuminterest(float rate);
    void setinitialDepositAmount(float amount);
    float getmaximuminterest() const;
    float getinitialDepositAmount() const;
    void description() const;
};

#endif

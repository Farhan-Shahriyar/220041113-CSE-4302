#ifndef TWOYEARMDS_H
#define TWOYEARMDS_H
#include "MonthlyDepositScheme.h"
#include<bits/stdc++.h>
using namespace std;

class TwoYearMDS : public MonthlyDepositScheme{
private:
    float maximuminterest;
public:
    TwoYearMDS(string name, float initial, float ir, float maxir);
    ~TwoYearMDS();
    void setmaximuminterest(float rate);
    float getmaximuminterest() const;
    void description() const;
};

#endif

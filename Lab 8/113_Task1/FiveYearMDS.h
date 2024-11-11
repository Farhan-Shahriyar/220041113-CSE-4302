#ifndef FIVEYEARMDS_H
#define FIVEYEARMDS_H
#include "MonthlyDepositScheme.h"
#include<bits/stdc++.h>
using namespace std;

class FiveYearMDS : public MonthlyDepositScheme{
private:
    float maximuminterest;
public:
    FiveYearMDS(string name, float initial, float ir, float maxir);
    ~FiveYearMDS();
    void setmaximuminterest(float rate);
    float getmaximuminterest() const;
    void description() const;
};

#endif


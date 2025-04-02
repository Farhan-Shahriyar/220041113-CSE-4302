#ifndef COUNTER_H
#define COUNTER_H
#include<bits/stdc++.h>
using namespace std;

class Counter{
private:
    int totalcount;
    int stepsize;
public:
    Counter();
    void setIncrementStep(int step_val);
    int getCount();
    void increment();
    void resetCount(int step = 1);
    Counter operator+(const Counter &obj) const;
    Counter operator+=(const Counter &obj);
    bool operator>(const Counter &obj) const;
    bool operator<(const Counter &obj) const;
    bool operator>=(const Counter &obj) const;
    bool operator<=(const Counter &obj) const;
    bool operator==(const Counter &obj) const;
    bool operator!=(const Counter &obj) const;
    Counter operator++(int);
    Counter operator++();
};

#endif

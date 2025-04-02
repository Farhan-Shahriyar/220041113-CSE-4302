#include "Counter.h"
#include<bits/stdc++.h>
using namespace std;

Counter :: Counter() : totalcount(0), stepsize(1){}

void Counter :: setIncrementStep(int step_val){
     if(totalcount!=0){
        cout<<"Cannot set increment step"<<endl;
     }
     else if(step_val<0){
        cout<<"Increment step will remain the default value 1"<<endl;
     }
     else{
        stepsize = step_val;
     }
}

int Counter :: getCount(){
    return totalcount;
}

void Counter :: increment(){
    totalcount += stepsize;
}

void Counter :: resetCount(int step){
    totalcount = 0;
    stepsize = (step < 0) ? 1 : step;
}

Counter Counter :: operator+(const Counter& obj) const{
    Counter result;
    if (stepsize == obj.stepsize){
        result.totalcount = totalcount + obj.totalcount;
        result.stepsize = stepsize;
    }
    else{
        cout<<"Increment steps are not the same, operation cannot be completed."<<endl;
    }
    return result;
}

Counter Counter :: operator+=(const Counter& obj){
    if(stepsize == obj.stepsize){
        totalcount = totalcount + obj.totalcount;
    }
    else{
        cout<<"Increment steps are not the same, operation cannot be completed."<<endl;
    }
    return *this;
}

bool Counter :: operator==(const Counter& obj) const{
    return totalcount == obj.totalcount;
}

bool Counter :: operator!=(const Counter& obj) const{
    return totalcount != obj.totalcount;
}

bool Counter :: operator>(const Counter& obj) const{
    return totalcount > obj.totalcount;
}

bool Counter :: operator<(const Counter& obj) const{
    return totalcount < obj.totalcount;
}

bool Counter :: operator>=(const Counter& obj) const{
    return totalcount >= obj.totalcount;
}

bool Counter :: operator<=(const Counter& other) const{
    return totalcount <= other.totalcount;
}

Counter Counter :: operator++(int){
    Counter temp = *this;
    increment();
    return temp;
}

Counter Counter :: operator++(){
    increment();
    return *this;
}

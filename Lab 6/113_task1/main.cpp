#include "Counter.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    Counter c1, c2, c3;
    c1.setIncrementStep(5);
    c2.setIncrementStep(5);
    c1.increment();
    c2.increment();
    c3 = c1+c2;
    cout<<c3.getCount()<<endl;
    return 0;
}

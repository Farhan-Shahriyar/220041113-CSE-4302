#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "MonthlyDepositScheme.h"
#include "LoanAccount.h"
#include "TwoYearMDS.h"
#include "FiveYearMDS.h"
#include "InitialDepositMDS.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    CurrentAccount c("Farhan", 20000.0);
    SavingsAccount s("Anika", 50000.0);
    MonthlyDepositScheme m("Safwat", 3000.0, 6.4);
    LoanAccount l("Rafi", 25000.0);
    TwoYearMDS tm("Zahin", 54000.0, 4.4, 9.0);
    FiveYearMDS fm("Messi", 900000, 5.4, 12.3);
    InitialDepositMDS idm("Cristiano", 500000, 4.5, 13.3, 9000);
    cout<<c.getnextAccountno()<<endl;
    s.setinterestRate(9.9);
    s.description();
    cout<<m.getaccountPrefix()<<endl;
    l.description();
    cout<<tm.getaccountName()<<endl;;
    fm.description();
    cout<<idm.getbalance()<<endl;

    return 0;

}

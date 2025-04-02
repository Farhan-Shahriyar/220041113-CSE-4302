#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class SavingsAccount{
private:
    string accountName;
    string address;
    float interestRate;
    float currentBalance;
    float minBalance;
public:
    SavingsAccount();
    void setAccountName(string name);
    string getAccountName() const;
    void setAddress(string data);
    string getAddress() const;
    void setInterestRate(float rate);
    float getInterestRate() const;
    void setCurretBalance(float balance);
    float getCurrentBalance() const;
    float getMinBalance() const;
    void depositAmount(float amount);
    void withdrawAmount(float amount);
    double calculateInterest(int periodInMonths) const;
    void disburseInterest(int periodInMonths);
};

void EditInformationByKeyboard(SavingsAccount &acc);

string getRandomName(vector<string> &randomNames);

string getRandomAddress(vector<string> &randomAddress);

void generateInformationRandom(SavingsAccount &acc);

void ShowInterestAll(SavingsAccount ar[]);

bool compareByName(const SavingsAccount& a, const SavingsAccount& b);

void ShowAllAlphabetically(SavingsAccount ar[]);

#endif

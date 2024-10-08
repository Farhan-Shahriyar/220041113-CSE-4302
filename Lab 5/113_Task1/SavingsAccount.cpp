#include "SavingsAccount.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

SavingsAccount :: SavingsAccount() : accountName(""), address(""), interestRate(0.0), currentBalance(0.0), minBalance(0.0){};

void SavingsAccount :: setAccountName(string name){
    accountName = name;
}

string SavingsAccount :: getAccountName() const{
    return accountName;
}

void SavingsAccount :: setAddress(string data){
    address = data;
}

string SavingsAccount :: getAddress() const{
    return address;
}

void SavingsAccount :: setInterestRate(float rate){
    interestRate = rate;
}

float SavingsAccount :: getInterestRate() const{
    return interestRate;
}

void SavingsAccount :: setCurretBalance(float balance){
    currentBalance = balance;
    if((minBalance == 0.0) || (minBalance>currentBalance)){
        minBalance = currentBalance;
    }
}

float SavingsAccount :: getCurrentBalance() const{
    return currentBalance;
}

float SavingsAccount :: getMinBalance() const{
    return minBalance;
}

void SavingsAccount :: depositAmount(float amount){
    currentBalance+=amount;
    return;
}

void SavingsAccount :: withdrawAmount(float amount){
     if(currentBalance-amount<=0){
        cout<<"Not sufficient Balance"<<endl;
        return;
    }
    else{
        currentBalance-=amount;
    }
    if(minBalance>currentBalance){
        minBalance = currentBalance;
    }
}

double SavingsAccount :: calculateInterest(int periodInMonths) const{
    double interestAmount = periodInMonths * (interestRate/(100*12)) * minBalance;
    return interestAmount;
}

void SavingsAccount :: disburseInterest(int periodInMonths){
    currentBalance += calculateInterest(periodInMonths);
    minBalance = currentBalance;
}

void EditInformationByKeyboard(SavingsAccount &acc){
    string name, data;
    float interest, balance;
    cout<<"Enter Account Name: ";
    getline(cin, name);
    acc.setAccountName(name);
    cout<<"Enter Account Holder's Address: ";
    getline(cin, data);
    acc.setAddress(data);
    cout<<"Enter interest rate (between 2.0 and 4.0) : ";
    cin>>interest;
    acc.setInterestRate(interest);
    cout<<"Enter current balance: ";
    cin>>balance;
    acc.setCurretBalance(balance);
    cin.ignore();
    return;
}

string getRandomName(vector<string> &randomNames){
    return randomNames[rand() % randomNames.size()];
}

string getRandomAddress(vector<string> &randomAddress){
    return randomAddress[rand() % randomAddress.size()];
}

void generateInformationRandom(SavingsAccount &acc){
    vector<string> randomNames = {"Farhan Shahriyar", "Asif Hossain", "Charles Henry", "Hasan Tareq", "Arafat Islam", "Abrar Mahmum", "Shahriyar Kamal", "Abdul Kader"};
    vector<string> randomAddress = {"Bashundhara Residential Block F", "Board Bazar Gazipur Dhaka", "Merul Badda Brac University", "Gulshan 2 DCC market"};
    string name = getRandomName(randomNames);
    string data = getRandomAddress(randomAddress);
    float interestRate = 2.0 + (rand() % 21) / 10.0;
    float balance = rand() % 10000;
    acc.setAccountName(name);
    acc.setAddress(data);
    acc.setInterestRate(interestRate);
    acc.setCurretBalance(balance);
}

void ShowInterestAll(SavingsAccount ar[]){
    for(int i = 0; i<100; i++){
        cout<<ar[i].getAccountName()<<": "<<ar[i].calculateInterest(12)<<endl;
    }
    cout<<"Confirm disbursement? : (y for yes)";
    char c;
    cin>>c;
    if(c=='y'){
        for(int i = 0; i<100; i++){
            ar[i].disburseInterest(12);
        }
    }
    return;
}

bool compareByName(const SavingsAccount& a, const SavingsAccount& b) {
    return a.getAccountName() < b.getAccountName();
}

void ShowAllAlphabetically(SavingsAccount ar[]){
    sort(ar, ar+100, compareByName);
    for(int i=0; i<100; i++){
        cout<<ar[i].getAccountName()<<" "<<ar[i].getCurrentBalance()<<endl;
    }
    return;
}



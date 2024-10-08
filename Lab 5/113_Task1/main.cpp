#include "SavingsAccount.h"
#include <ctime>
#include <iostream>
using namespace std;

int main(){
    srand(time(0));
    const int NUM_ACCOUNTS = 100;
    SavingsAccount ar[NUM_ACCOUNTS];
    for(int i = 0; i < 2; i++){
        EditInformationByKeyboard(ar[i]);
    }
    for(int i = 2; i < NUM_ACCOUNTS; i++) {
        generateInformationRandom(ar[i]);
    }
    ShowInterestAll(ar);
    ShowAllAlphabetically(ar);
    return 0;
}

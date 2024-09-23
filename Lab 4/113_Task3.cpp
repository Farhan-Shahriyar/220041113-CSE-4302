#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private:
    int accountNumber;
    string accountHolderName;
    string accountType;
    float currentBalance;
    const float minimumBalance;
public:
    static int totalAccounts;
    static int activeAccounts;
    static float totalSourceTax;
    int getCurrentBalance() const{
        int balance = currentBalance;
        return balance;
    }
    BankAccount(int accNum, string holderName, string accType, float balance, float minBalance) : accountNumber(accNum), accountHolderName(holderName), accountType(accType), currentBalance(balance), minimumBalance(minBalance) {
        if (balance<minimumBalance){
            cout << "Initial balance is less than minimum balance. Setting current balance to minimum balance." << endl;
            currentBalance = minimumBalance;
        }
        totalAccounts++;
        activeAccounts++;
    }
    ~BankAccount(){
        cout<<"Account of Mr./Ms. "<<accountHolderName << " with account no "<<accountNumber<<" is destroyed with a balance BDT "<<currentBalance<<endl;
        activeAccounts--;
    }
    void showInfo() const {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder Name: "<<accountHolderName<<endl;
        cout<<"Account Type: "<<accountType<<endl;
        cout<<"Current Balance: BDT "<<currentBalance<<endl;
        cout<<"Minimum Balance: BDT "<<minimumBalance<<endl;
    }
    void showBalance() const {
        cout<<"Current Balance: BDT "<<currentBalance<<endl;
    }
    void deposit(float amount) {
        if(amount>0){
            currentBalance += amount;
            cout<<"Deposited: BDT "<<amount<<". New Balance: BDT "<<currentBalance<<endl;
        }
        else{
            cout <<"Invalid deposit amount."<<endl;
        }
    }
    void withdraw(float amount){
        if(amount<=0){
            cout<<"Invalid withdrawal amount."<<endl;
        }
        else if(currentBalance-amount<minimumBalance){
            cout<<"Cannot withdraw. Balance would fall below the minimum required balance."<<endl;
        }
        else{
            currentBalance -= amount;
            cout <<"Withdrawn: BDT "<< amount<<". New Balance: BDT "<<currentBalance<<endl;
        }
    }
    void giveInterest(float interestRate=3.0){
        float interest = (currentBalance * interestRate) / 100.0;
        float sourceTax = interest * 0.10;
        totalSourceTax += sourceTax;
        currentBalance += (interest - sourceTax);
        cout<<"Interest of BDT "<<interest - sourceTax<<" credited after 10% source tax deduction."<<endl;
        cout<<"New Balance: BDT "<<currentBalance<<endl;
    }
};

int BankAccount::totalAccounts = 0;
int BankAccount::activeAccounts = 0;
float BankAccount::totalSourceTax = 0.0;
BankAccount Larger(const BankAccount& A, const BankAccount& B){
    return (A.getCurrentBalance() > B.getCurrentBalance()) ? A : B;
}

static void showStatistics(){
        cout<<"Total Bank Accounts created: " <<BankAccount::totalAccounts<<endl;
        cout<<"Total Active Bank Accounts: "<<BankAccount::activeAccounts<<endl;
        cout<<"Total Source Tax collected: BDT "<<BankAccount::totalSourceTax<<endl;
}

int main(){
    BankAccount acc1(1234, "Alice", "savings", 5000.0, 1000.0);
    BankAccount acc2(5678, "Bob", "current", 10000.0, 2000.0);
    acc1.showInfo();
    acc2.showInfo();
    acc1.deposit(2000);
    acc2.withdraw(3000);
    acc1.giveInterest();
    acc2.giveInterest(4.5);
    BankAccount largerAcc = Larger(acc1, acc2);
    cout<<"Account with larger balance belongs to: "<<endl;
    largerAcc.showInfo();
    showStatistics();
    return 0;
}

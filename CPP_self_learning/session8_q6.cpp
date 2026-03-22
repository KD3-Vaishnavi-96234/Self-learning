#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : accountNumber(0), accountHolderName(""), balance(0.0) {}
    BankAccount(int accNum, string accHolderName, double initialBalance)
    {
        accountNumber = accNum;
        accountHolderName = accHolderName;
        balance = initialBalance;
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }
    void displayBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc(123456, "Vaishnavi", 10000.0);

    acc.displayBalance();

    acc.deposit(5000.0);
    acc.displayBalance();

    acc.withdraw(2000.0);
    acc.displayBalance();

    acc.withdraw(1500.0);
    acc.displayBalance();

    return 0;
}

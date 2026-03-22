#include <iostream>
#include <string>
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
            throw amount; 
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else if (amount <= 0)
        {
            throw amount; 
        }
        else
        {
            throw string("Invalid withdrawal amount or insufficient funds!"); 
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
    try
    {
        acc.deposit(-500.0); 
    }
    catch (double amount)
    {
        cout << "Error: Cannot deposit a negative amount: " << amount << endl;
    }
    acc.displayBalance();
    try
    {
        acc.withdraw(20000.0); 
    }
    catch (double amount)
    {
        cout << "Error: Cannot withdraw a negative amount: " << amount << endl;
    }
    catch (string &errorMessage)
    {
        cout << "Error: " << errorMessage << endl;
    }
    acc.displayBalance();
    return 0;
}

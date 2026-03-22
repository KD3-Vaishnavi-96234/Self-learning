#include <iostream>
#include <string>
using namespace std;
class Payment
{   
public:
    virtual void makePayment(double amount) = 0; 
    virtual ~Payment() {}
};      
class CreditCard : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Payment of $" << amount << " made using Credit Card." << endl;
    }
};
class UPI : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Payment of $" << amount << " made using UPI." << endl;
    }
};
class Cash : public Payment
{
public:
    void makePayment(double amount)
    {
        cout << "Payment of $" << amount << " made using Cash." << endl;
    }
};
class PaymentFactory
{
public:
    static Payment* create(const string& mode)
    {
        if (mode == "CreditCard")
            return new CreditCard();
        else if (mode == "UPI")
            return new UPI();
        else if (mode == "Cash")
            return new Cash();
        else
            return nullptr; 
    }
};
int main()
{
    string mode;
    double amount;
    cout << "Enter payment mode (CreditCard/UPI/Cash): ";
    cin >> mode;
    cout << "Enter payment amount: ";
    cin >> amount;

    Payment* payment = PaymentFactory::create(mode);
    if (payment)
    {
        payment->makePayment(amount);
        delete payment; 
    }
    else
    {
        cout << "Invalid payment mode!" << endl;
    }
    return 0;
}


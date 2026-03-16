#include <iostream>
using namespace std;    
// Swap using Call by Value
void swapByValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// Swap using Call by Reference
void swapByReference(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int num1 = 10;
    int num2 = 20;
    cout << "Before swapByValue: ";
    cout << num1 << " " << num2 << endl;
    swapByValue(num1, num2);
    cout << "After swapByValue: ";
    cout << num1 << " " << num2 << endl;
    cout << "\nBefore swapByReference: ";
    cout << num1 << " " << num2 << endl;
    swapByReference(num1, num2);
    cout << "After swapByReference: ";
    cout << num1 << " " << num2 << endl;
    return 0;
}

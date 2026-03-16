#include <iostream>
using namespace std;    
// Inline function to calculate factorial
inline int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}   
// Inline function to calculate power
inline double power(double base, int exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}
int main()
{
    int num = 5;
    double base = 2.0;
    int exponent = 3;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    cout << base << " raised to the power of " << exponent << " is: " << power(base, exponent) << endl;
    return 0;
}

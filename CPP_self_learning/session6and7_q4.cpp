#include <iostream>
using namespace std;
class laptop
{
private:
    int brandId;
    double price;

public:
    laptop() : brandId(1), price(50000.0)
    {
        cout << "Laptop Constructor Called" << endl;
    }
    ~laptop()
    {
        cout << "Laptop Destructor Called" << endl;
    }
    void display()
    {
        cout << "Brand ID: " << brandId << endl;
        cout << "Price: " << price << endl;
    }
};
int main()
{
    laptop l1;
    l1.display();
    return 0;
}
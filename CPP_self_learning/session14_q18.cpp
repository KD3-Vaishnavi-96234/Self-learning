#include <iostream>
using namespace std;
template <typename T>
class Array
{
private:
    T *arr;
    int size;

public:
    Array(int s) : size(s)
    {
        arr = new T[size];
    }
    ~Array()
    {
        delete[] arr;
    }
    T &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }
};
int main()
{
    try
    {
        Array<int> intArray(5);
        for (int i = 0; i < 5; i++)
        {
            intArray[i] = i + 1;
        }
        cout << "Integer Array: ";
        for (int i = 0; i < 5; i++)
        {
            cout << intArray[i] << " ";
        }
        cout << endl;

        Array<double> doubleArray(5);
        for (int i = 0; i < 5; i++)
        {
            doubleArray[i] = (i + 1) * 1.1;
        }
        cout << "Double Array: ";
        for (int i = 0; i < 5; i++)
        {
            cout << doubleArray[i] << " ";
        }
        cout << endl;
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

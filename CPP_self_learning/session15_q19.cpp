#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    list<int> numbers;
    for (int i = 0; i < 10; i++)
    {
        numbers.push_back(rand() % 100); 
    }
    cout << "Original list: ";
    for (const auto &num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "List in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        *it += 5; 
    }
    cout << "List after incrementing by 5: ";
    for (const auto &num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end());
    cout << "Sorted list: ";
    for (const auto &num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

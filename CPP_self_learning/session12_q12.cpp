#include <iostream>
#include <string>
using namespace std;
class Product
{
protected:
    string title;
    double price;
public:
    virtual void accept() = 0; 
    virtual void display() = 0; 
};
class Book : public Product
{
private:
    int pages;
public:
    void accept()
    {
        cout << "Enter book title: ";
        cin >> title;
        cout << "Enter book price: ";
        cin >> price;
        cout << "Enter number of pages: ";
        cin >> pages;
    }
    void display()
    {
        cout << "Book Title: " << title << endl;
        cout << "Book Price: " << price << endl;
        cout << "Number of Pages: " << pages << endl;
    }
};

class Tape : public Product
{
private:
    double playtime;
public:
    void accept()
    {
        cout << "Enter tape title: ";
        cin >> title;
        cout << "Enter tape price: ";
        cin >> price;
        cout << "Enter playtime in minutes: ";
        cin >> playtime;
    }
    void display()
    {
        cout << "Tape Title: " << title << endl;
        cout << "Tape Price: " << price << endl;
        cout << "Playtime (minutes): " << playtime << endl;
    }
};
int main()
{
    Product *arr[5];
    int choice;
    for (int i = 0; i < 5; i++)
    {
        cout << "1. Book, 2. Tape, Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            arr[i] = new Book;
            arr[i]->accept();
            break;
        case 2:
            arr[i] = new Tape;
            arr[i]->accept();
            break;
        default:
            cout << "Invalid choice!" << endl;
            i--; 
            break;
        }
    }
    cout << "\nDisplaying pages and playtime values:\n";
    for (int i = 0; i < 5; i++)
    {
        arr[i]->display();
    }
    for (int i = 0; i < 5; i++)
    {
        delete arr[i];
    }
    return 0;
}

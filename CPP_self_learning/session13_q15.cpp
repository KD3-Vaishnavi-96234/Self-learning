#include <iostream>
#include <string>
using namespace std;
class NegativeMarksException : public exception
{
    private:
    string message; 
public:
    NegativeMarksException(const string& msg) : message(msg) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};
class Student
{
private:
    int rollno;
    double marks;
public:
    Student() : rollno(0), marks(0.0) {}
    Student(int r, double m) : rollno(r), marks(m) {}
    int getRollno()
    {
        return rollno;
    }
    double getMarks()
    {
        return marks;
    }
    void acceptData()
    {
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks: ";
        cin >> marks;
        if (marks < 0)
        {
            throw NegativeMarksException("Marks cannot be negative!"); 
        }
        cout << endl;
    }
    void displayData()
    {
        cout << "Roll number: " << rollno << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main()
{
    Student s;
    try
    {
        s.acceptData();
        s.displayData();
    }
    catch (const NegativeMarksException& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
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
            throw string("Marks cannot be negative!"); 
        }
        cout << endl;
    }
    void displayData()
    {
        cout << "Roll number: " << rollno << endl;
        cout << "Marks: " << marks << endl;
    }
};
class StudentPtr
{
private:
    Student *ptr;
public:
    StudentPtr(Student *p = nullptr) : ptr(p) {}
    ~StudentPtr()
    {
        delete ptr;
    }
    Student* operator->()
    {
        return ptr;
    }
};
int main()
{
    try
    {
        StudentPtr s(new Student);
        s->acceptData();
        s->displayData();
    }
    catch (const string& e)
    {
        cout << "Error: " << e << endl;
    }
    return 0;
}

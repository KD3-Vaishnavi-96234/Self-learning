#include<iostream>
using namespace std;
class student
{
private:
    int rollno;
    double marks;

public:
    student() : rollno(0), marks(0.0) {}
    student(int r, double m) : rollno(r), marks(m) {}
    int getRollno()
    {
        return rollno;
    }
    double getMarks()
    {
        return marks;
    }
    void accpetData()
    {
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks: ";
        cin >> marks;
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
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    student *s = new student[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        s[i].accpetData();
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        s[i].displayData();
    }
    int highestmarksIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].getMarks() > s[highestmarksIndex].getMarks())
        {
            highestmarksIndex = i;
        }
    }
    cout << "Student with highest marks:" << endl;
    s[highestmarksIndex].displayData();

    delete[] s;
    return 0;
}
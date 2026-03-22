#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student
{
private:
    int rollno;
    string name;
    double marks;
public:
    Student() : rollno(0), name(""), marks(0.0) {}
    Student(int r, string n, double m) : rollno(r), name(n), marks(m) {}
    void display()
    {
        cout << "Roll number: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
    void saveToFile(const string& filename)
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            outFile << rollno << endl;
            outFile << name << endl;
            outFile << marks << endl;
            outFile.close();
            cout << "Student data saved to " << filename << endl;
        }
        else
        {
            cout << "Unable to open file for writing!" << endl;
        }
    }
    void loadFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            inFile >> rollno;
            inFile.ignore(); 
            getline(inFile, name);
            inFile >> marks;
            inFile.close();
            cout << "Student data loaded from " << filename << endl;
        }
        else
        {
            cout << "Unable to open file for reading!" << endl;
        }
    }
};
int main()
{
    Student s1(101, "Vaishnavi", 95.5);
    s1.display();
    s1.saveToFile("student_data.txt");
    Student s2;
    s2.loadFromFile("student_data.txt");
    s2.display();
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
class Programmer
{
public:
    Programmer()
    {
        cout << "Programmer constructor called." << endl;
    }
    void work()
    {
        cout << "Programmer is working." << endl;
    }
};
class Teacher
{
public:
    Teacher()
    {
        cout << "Teacher constructor called." << endl;
    }
    void work()
    {
        cout << "Teacher is working." << endl;
    }
};
class ProgrammingTeacher : public Programmer, public Teacher
{
public:
    ProgrammingTeacher()
    {
        cout << "ProgrammingTeacher constructor called." << endl;
    }
};

int main()
{
    ProgrammingTeacher pt;
    
    pt.Programmer::work();
    pt.Teacher::work();
    return 0;
}
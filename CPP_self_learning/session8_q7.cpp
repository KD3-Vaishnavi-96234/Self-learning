#include <iostream>
using namespace std;

namespace college
{
    class Student
    {
    private:
        int studentID;
        string studentName;

    public:
        Student() : studentID(0), studentName("") {}
        Student(int id, string name) : studentID(id), studentName(name) {}

        void setStudentID(int id)
        {
            studentID = id;
        }
        int getStudentID()
        {
            return studentID;
        }
        void setStudentName(string name)
        {
            studentName = name;
        }
        string getStudentName()
        {
            return studentName;
        }
        void display()
        {
            cout << "Student ID: " << studentID << endl;
            cout << "Student Name: " << studentName << endl;
        }
    };

    class Teacher
    {
    private:
        int teacherID;
        string teacherName;

    public:
        Teacher() : teacherID(0), teacherName("") {}
        Teacher(int id, string name) : teacherID(id), teacherName(name) {}
        void setTeacherID(int id)
        {
            teacherID = id;
        }
        int getTeacherID()
        {
            return teacherID;
        }
        void setTeacherName(string name)
        {
            teacherName = name;
        }

        string getTeacherName()
        {
            return teacherName;
        }
        void display()
        {
            cout << "Teacher ID: " << teacherID << endl;
            cout << "Teacher Name: " << teacherName << endl;
        }
    };
}
int main()
{
    college::Student student1(101, "Vaishnavi");
    college::Teacher teacher1(201, "Jyoti Pal");

    cout << "Student Details:" << endl;
    student1.display();

    cout << "\nTeacher Details:" << endl;
    teacher1.display();

    return 0;
}

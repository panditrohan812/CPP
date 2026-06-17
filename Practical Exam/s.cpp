#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;

public:
    Student(string n, int r)
    {
        name = n;
        rollNumber = r;
    }

    void display()
    {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

int main()
{
    Student students[3] = {
        Student("Raj Patel", 101),
        Student("Diya Pandya", 102),
        Student("Kabir Mehta", 103)};

    cout << "Student Details:" << endl;
    cout << "-------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        students[i].display();
    }
}
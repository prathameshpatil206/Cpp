#include<iostream>
using namespace std;

class Student
{
    public:
        string name;
        int age;
        int roll_no;

};

class Employee
{
    public:
        int emp_id;
        string sector;
};

class Intern:public Student,public Employee
{
    public:
        void getInfo()
        {
            cout<<"Student name: "<<this->name<<endl;
            cout<<"Employee no: "<<this->emp_id<<endl;
        }
};

int main()
{

    Intern i;
    i.name="Sohan";
    i.age=18;
    i.roll_no=123;
    i.emp_id=23654;
    i.getInfo();
    return 0;
}
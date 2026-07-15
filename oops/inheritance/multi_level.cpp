#include<iostream>
using namespace std;

class Person
{
    public:
        string name;
        int age;
};

class Student: public Person
{
    public:
        int roll_no;

        void StudInfo()
        {
            cout<<"Name: "<<this->name<<endl;
            cout<<"Age: "<<this->age<<endl;
            cout<<"Roll No: "<<this->roll_no<<endl;
        }
};

class GradStudent: public Student
{
    public:
        string Area_research;

        void gradInfo()
        {
            this->StudInfo();
            cout<<"Area of research: "<<this->Area_research<<endl;
        }
};

int main()
{
    GradStudent g;
    g.name="Chandu";
    g.age=18;
    g.roll_no=629;
    g.Area_research="Space";
    g.gradInfo();
    return 0;
}
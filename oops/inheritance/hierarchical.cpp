#include<iostream>
using namespace std;

class Person
{
    public:
        string name;
        int age;

        void perInfo()
        {
            cout<<"Name: "<<this->name<<endl;
            cout<<"Age: "<<this->age<<endl;
        }
};

class Student: public Person
{
    public:
        int roll_no;

        void StudInfo()
        {
            this->perInfo();
            cout<<"Roll No: "<<this->roll_no<<endl;
        }
};

class Teacher: public Person
{
    public:
        string depart;

        void TeacherInfo()
        {
            this->perInfo();
            cout<<"Department: "<<this->depart<<endl;
        }
};

int main()
{

    Student s;
    s.name="Sohan";
    s.age=18;
    s.roll_no=123;
    s.StudInfo();
    cout<<endl;
    Teacher t;
    t.name="Mohan";
    t.age=28;
    t.depart="Physics";
    t.TeacherInfo();
    return 0;
}
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

        void getInfo()
        {
            cout<<"Name: "<<this->name<<endl;
            cout<<"Age: "<<this->age<<endl;
            cout<<"Roll No: "<<this->roll_no<<endl;
        }
};

int main()
{
    Student s;
    s.name="Chandu";
    s.age=18;
    s.roll_no=629;

    s.getInfo();
    return 0;
}
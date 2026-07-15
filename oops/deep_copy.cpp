#include<iostream>
#include<string>
using namespace std;

/*
Shallow & Deep Copy
A shallow copy of an object copies all of the member values from one object to another.

A deep copy, on the other hand, not only copies the member values but also makes copies of
any dynamically allocated memory that the members point to.
*/

/*
For dynamic memory allocation, we need to write our
own copy constructor for deep copy...orelse by default shallow copy will be followed 
which leads to confusions....
*/

class Student
{
    public:
        string name;
        double *cgpaPtr;

        Student(string name,float cgpa)
        {
            this->name=name;
            this->cgpaPtr=new double;
            *(this->cgpaPtr)=cgpa;
        }

        //copy constructor for deep copy
        Student(Student &obj)
        {
            this->name=obj.name;
            this->cgpaPtr=new double;
            *(this->cgpaPtr)=*(obj.cgpaPtr);
        }

        void getInfo()
        {
            cout<<"Name  : "<<this->name<<endl;
            cout<<"CGPA  : "<<*(this->cgpaPtr)<<endl<<endl;
        }
};

int main()
{
    Student s1("Mohan",8.9);
    s1.getInfo();
    Student s2(s1);
    *(s2.cgpaPtr)=9.2;
    s1.getInfo();
    s2.getInfo();
    return 0;
}
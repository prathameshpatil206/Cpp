#include<iostream>
using namespace std;

class Student
{
    public:
        string name;

        //constructor overloading
        Student()
        {
            cout<<"I am a Student"<<endl;
        }

        Student(string name)
        {
            this->name=name;
        }

        //function overloading
        void display()
        {
            cout<<this->name<<endl;
        }

        void display(string n)
        {
            cout<<n<<endl;
        }

        void display(int d)
        {
            cout<<d<<endl;
        }

        //read online about operator overloading
};

int main()
{
    Student s("Mohan");
    s.display();
    s.display(s.name);
    s.display(10);
    return 0;
}
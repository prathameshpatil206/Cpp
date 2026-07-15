#include<iostream>
using namespace std;

class Parent
{
    public:
        void getInfo()
        {
            cout<<"Parent class"<<endl;
        }

        //virtual function
        virtual void hello()
        {
            cout<<" hello from parent\n";
        }

};

class Child:public Parent
{
    public:
        void getInfo()
        {
            cout<<"child class\n";
        }

        void hello()
        {
            cout<<" hello from child\n";
        }
    
};

int main()
{
    Parent p;
    Child c;
    p.getInfo();
    p.hello();
    c.getInfo();//child class getinfo gets priority....parent class getInfo is overridden.
    // this is called function overriding.

    c.hello();//child class hello is directly called..
    return 0;
}
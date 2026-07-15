#include<iostream>
#include<string>
using namespace std;

// private
// data & methods accessible inside class

// public
// data & methods accessible to everyone

// protected
// data & methods accessible inside class & to its
// derived class
class Product
{
    public:
        string name;
        string description;
        string category;
        float cost;
        float discount;

        //methods
        void change_discount(float newdis)
        {
            discount=newdis;
        }
};

int main()
{
    Product p1;

    cout<<"Enter name: ";
    getline(cin,p1.name);

    cout<<"Enter description: ";
    getline(cin,p1.description);

    cout<<"Enter category: ";
    getline(cin,p1.category);

    cout<<"Enter cost: ";
    cin>>p1.cost;

    cout<<"Enter discount: ";
    cin>>p1.discount;

    cout<<"Details: "<<endl;
    cout<<"Name: "<<p1.name<<endl;
    cout<<"Description: "<<p1.description<<endl;
    cout<<"Category: "<<p1.category<<endl;
    cout<<"Cost: "<<p1.cost<<endl;
    cout<<"Discount: "<<p1.discount<<endl;

    p1.change_discount(23.43);
    cout<<"New Discount: "<<p1.discount<<endl;

    return 0;
}
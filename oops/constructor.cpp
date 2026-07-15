#include<iostream>
#include<string>
using namespace std;

// Special method invoked automatically at time of object creation. Used for Initialisation.
// · Same name as class
// . Constructor doesn't have a return type
// . Only called once (automatically), at object creation
// . Memory allocation happens when constructor is called

// this is a special pointer in C++ that points to the current object.
// this->prop is same as (*this).prop

class Car
{
    public:
        string color;
        string model;
        string number;
        float cost;

        //non-parameterized constructor
        Car(){
            cout<<"Hi....I am a car"<<endl;
            this->color="blue";
        }

        //parameterized constructor
        //more than one constructor leads to constructor overloding which is
        //an example of polymorphism.
        Car(string color, string model, string number, float cost){
            this->color= color;
            this->model= model;
            (*this).number= number;
            this->cost=cost;
        }

        //copy constructor
        Car(Car &orgObj)
        {
            this->color=orgObj.color;
            this->model=orgObj.model;
            this->number=orgObj.number;
            this->cost=orgObj.cost;
        }

        void display()
        {
            cout<<"Color    : "<<this->color<<endl;
            cout<<"Model    : "<<this->model<<endl;
            cout<<"Number   : "<<this->number<<endl;
            cout<<"Cost     : "<<this->cost<<endl<<endl;
        }
};

int main()
{
    Car c1("Blue","Maruit Suzuki","KA2206EF56",660000.89);
    c1.display();

    Car c2(c1);
    c2.display();

    Car c3;
    return 0;
}
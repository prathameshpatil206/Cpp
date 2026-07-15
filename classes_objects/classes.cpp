#include<iostream>
using namespace std;

class Car{
public:
    string num;
    string name;
    string color;
    float price;
    void display(){
        cout<<name;
    }
};
int main()
{
    Car c;

    cout<<"Enter name: ";
    getline(cin, c.name);

    c.display();
    return 0;
}
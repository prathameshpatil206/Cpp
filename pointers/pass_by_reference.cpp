#include<iostream>
using namespace std;

void changeA(int* ptr) //pass by reference using pointers
{
    *ptr=*ptr+20;
}

void change_A(int &b) //pass by reference using alias
{
    b=b+20;
}

int main()
{
    int a=10;
    changeA(&a);
    cout<<a<<endl;
    change_A(a);
    cout<<a<<endl;
    return 0;
}
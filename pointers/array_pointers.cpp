#include <iostream>
#include <vector>
using namespace std;

int main() {
int a[]={1,2,3,4,5}; //an array is a pointer in C++
int b=10,i;
//a is constant pointer.It cannot be modified.Eg: a=&b; gives error.
cout<<a<<endl;//gives address of zeroth index of the array
cout<<*a<<endl;//gives value at zeroth index

for(i=0;i<5;i++)
{
    cout<<*(a+i)<<" ";
}
cout<<endl;

int* j;
for(j=a;j<a+5;j++)
{
    cout<<*(j)<<" ";
}
return 0;
}
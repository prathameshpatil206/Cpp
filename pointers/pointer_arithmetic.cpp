#include <iostream>
using namespace std;

int main() {
int a=10;
int* ptr=&a;
cout<<ptr<<endl;
//Increament
ptr++;              //ponts to the next memory address by adding size of datatype.
cout<<ptr<<endl;
cout<<&a<<endl;
cout<<*ptr<<endl;   //here,gives garbage value.

//decreament
ptr--;
cout<<ptr<<endl;
cout<<*ptr<<endl; 

//Addition
ptr=ptr+2;              //points to the memory address after two slot sizes of datatype 
cout<<ptr<<endl;
cout<<*ptr<<endl;   //here,gives garbage value.

//Subtraction
ptr=ptr-2;              
cout<<ptr<<endl;
cout<<*ptr<<endl;   

//subtraction of two pointers gives the number of blocks between them.
int b=20;
int* ptrb=&b;
int* ptrb2=ptrb +5;
int sub=ptrb2-ptrb;//gives no. of intergers between these two pointers.
cout<<sub<<endl;

//Comparision
cout<<(ptrb<ptrb2)<<endl;
cout<<(ptrb>ptrb2)<<endl;
cout<<(ptrb!=ptrb2)<<endl;
cout<<(ptrb==ptrb2)<<endl;
return 0;
}
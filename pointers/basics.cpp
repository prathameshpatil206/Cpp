#include <iostream>
#include <vector>
using namespace std;

int main() {
int a = 10;
int* ptr = &a;
int** ptr2 = &ptr; //pointer to pointer approach...
int* nullpt=NULL; //null ptr

cout<<"ptr          = "<<ptr<<endl;
cout<<"&a           = "<<&a<<endl;
cout<<"ptr2         = "<<ptr2<< endl;
cout<<"&ptr         = "<<&ptr<< endl;
cout<<"a            = "<<a<< endl;
cout<<"*(ptr)       = "<<*(ptr)<<endl;
cout<<"*(&a)        = "<< *(&a) << endl;
cout<<"*(ptr2)      = "<< *(ptr2) << endl;
cout<<"**(ptr2)     = "<< **(ptr2) << endl;
cout<<"nullpt       = "<< nullpt << endl;
return 0;
}
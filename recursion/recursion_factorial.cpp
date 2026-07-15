#include<iostream>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);;
}

int main(){
int n,fact;
cout<<"Enter a number: ";
cin>>n;
fact=factorial(n);
cout<<fact;
return 0;
}
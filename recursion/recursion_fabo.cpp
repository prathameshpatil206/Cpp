#include<iostream>
using namespace std;

void fab(int a,int b,int n){
    if(n==0)
    {
        return;
    }
    cout<<a+b<<endl;
    fab(b,a+b,n-1);
}

int main(){
int n,fact;
cout<<"Enter the number of terms: ";
cin>>n;
cout<<0<<endl<<1<<endl;
fab(0,1,n-2);
return 0;
}
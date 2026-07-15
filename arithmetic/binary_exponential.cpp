#include<iostream>
using namespace std;

void exp(int n, int x){
    float ans=1;
    int h;
    h=n;
    if(h<0)
    {
        n=n*(-1);
    }
    while(n>0)
    {
        if(n%2!=0)
        {
            ans=ans*x;
        }        
        x=x*x;
        n=n/2;
    }

    if(h<0)
    {
        ans=1/ans;
    }
    cout<<"Ans: "<<ans;
}

int main(){
    int n,x;
    cout<<"Enter base and power: ";
    cin>>x>>n;
    exp(n,x);
    return 0;
}
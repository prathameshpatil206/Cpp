#include<iostream>
using namespace std;

int fact(int n ){
    int fact=1;

    for(int i=1;i<=n;i++){
        fact *=i;
    }
    return fact;
}

int main(){
    int n,r;
    float ncr;
    cout<<"Enter value of n and r: ";
    cin>>n>>r;
    ncr=fact(n)/(fact(n-r)*fact(r));
    cout<<"C("<<n<<","<<r<<")= "<<ncr;
    return 0;
}
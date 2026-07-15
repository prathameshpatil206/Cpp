#include<iostream>
using namespace std;

void bin(int num){
    int res=0, rem,pow=1;
    
    while(num>0){
        rem=num%10;
        res =res+rem*pow ;
        pow=pow*2;
        num =num/10;
    }
    cout<<"Decimal: "<<res;
}

int main(){
    int num;
    cout<<"Enter binary number: ";
    cin>>num;
    bin(num);
    return 0;
}
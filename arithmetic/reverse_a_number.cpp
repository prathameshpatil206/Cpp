#include<iostream>
using namespace std;

int reverse(int num){
    int res=0, rem;

    while(num>0){
        rem=num%10;
        res =res*10+rem;
        num =num/10;
    }
    return res;
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Reverse: "<<reverse(num);
    return 0;
}
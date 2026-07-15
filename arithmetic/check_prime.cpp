#include<iostream>
using namespace std;

void prime(int num){
    
    for(int i=2;i<=int(num/2);i++){
       if(num%i==0){
        cout<<num<<" is not a prime number.";
        return ;
       } 
    }
    cout<<num<<" is a prime number.";
}

int input(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    if(num<=1){
        cout<<"Invalid number! Enter a integer greater than 1."<<endl;
        num = input();
    }

    return num;
}

int main(){
    prime(input());
    return 0;
}
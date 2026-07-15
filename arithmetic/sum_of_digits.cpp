#include<iostream>
using namespace std;

int sumOfDigits(int num){
    int sum=0, rem;

    while(num!=0){
        rem=num%10;
        sum =sum+rem;
        num =num/10;
    }
    return sum;
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Sum of digits: "<<sumOfDigits(num);
    return 0;
}
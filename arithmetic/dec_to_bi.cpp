#include<iostream>
#include<math.h>
using namespace std;

void bin(int num){
    int res=0, rem,i=0;
    
    while(num!=0){
        rem=num%2;
        res =res+rem*pow(10,i) ;
        i++;
        num =num/2;
    }
    cout<<"Binary: "<<res;
}

int main(){
    int num;
    cout<<"Enter decimal number: ";
    cin>>num;
    bin(num);
    return 0;
}
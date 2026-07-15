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
    for(int j=1;j<=9-i;j++){
        cout<<"0";
    }
    cout<<res;
}

int main(){
    int num;
    cout<<"Enter decimal number: ";
    cin>>num;
    for(int i=0;i<=num;i++){
        bin(i);
        cout<<endl;
    }
    return 0;
}
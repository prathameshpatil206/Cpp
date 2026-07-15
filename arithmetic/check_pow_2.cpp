#include<iostream>
using namespace std;

//with loop
void check(int num){

    while(num>1){
        
        if(num%2==1){
            cout<<"Its not a power of 2";
            return;
        }
        num =num/2;
    }
    cout<<"Its a power is 2";
}

//without loop
void check2(int num){
    if((num & (num-1)) == 0){
        cout<<"Its a power of 2";
    }else{
        cout<<"Its not a power of 2";
    }
}

int main(){
    int num;
    cout<<"Enter a positive integer: ";
    cin>>num;
    check(num);
    cout<<endl;
    check2(num);
    return 0;
}
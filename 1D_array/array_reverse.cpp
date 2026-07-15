#include<iostream>
using namespace std;

void reverse(int a[], int n){
    if(n%2 ==0){
       for(int i=0;i<n/2;i++)
       {
        int temp = a[i];
        a[i]= a[n-1-i];
        a[n-1-i]= temp;
       } 
    }else{
        for(int i=0;i<(n-1)/2;i++)
       {
        int temp = a[i];
        a[i]= a[n-1-i];
        a[n-1-i]= temp;
       }
    }

    cout<<"Reversed array(in function): ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter size of array        : ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements       : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    reverse(a,n);
    cout<<"Reversed array(in main)    : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
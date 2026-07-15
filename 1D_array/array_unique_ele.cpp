#include<iostream>
using namespace std;

void Unique(int a[],int n){

cout<<"Unique elements of the array are: ";
cout<<a[0]<<" ";
    for(int i=1;i<n;i++){
        bool print=true;
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
               print = false;
            }
        }
        if(print){
            cout<<a[i]<<" ";
        }
    }

}


int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    Unique(a,n);

    return 0;
}
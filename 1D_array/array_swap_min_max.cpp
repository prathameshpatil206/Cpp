#include<iostream>
using namespace std;

void Swap(int a[],int n){
int sum=0, product=1,max=a[0],min=a[0],pmax,pmin;
for(int i=1;i<n;i++){
    if(a[i]>max){
        max=a[i];
        pmax=i;
    }
    if(a[i]<min){
        min=a[i];
        pmin=i;
    }
}

swap(a[pmax],a[pmin]);

cout<<"Swaped min and max element: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
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

    Swap(a,n);

    return 0;
}
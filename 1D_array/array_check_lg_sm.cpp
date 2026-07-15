#include<iostream>
using namespace std;

void findLarSmall(int a[],int n){
    
int lar=a[0], sm=a[0];
for(int i=1;i<n;i++){
    
    if(a[i]>lar)
    {
        lar=a[i];
    }

    if(a[i]<sm)
    {
        sm=a[i];
    }
    
}

cout<<"Smallest: "<<sm<<endl;
cout<<"Largest: "<<lar;

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

    findLarSmall(a,n);

    return 0;
}
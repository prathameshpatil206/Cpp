#include<iostream>
using namespace std;

void Intersection(int a[],int n,int b[], int s){

    cout<<"Elements common in both arrays are: ";
    for(int i=0;i<n;i++){
        bool run = true;
        for(int k=0;k<i;k++){
            if(a[k]==a[i]){
                run=false;
            }
        }

        if(run){
        int count=1;
        for(int j=0;j<s;j++){
            if(b[j]==a[i]){
                if(count==1){
                   cout<<a[i]<<" "; 
                }
                count++;
            }
        }
        }

        
    }

}


int main(){
    int n;
    cout<<"Enter size of array1: ";
    cin>>n;
    int a[n];
    cout<<"Enter array1 elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int s;
    cout<<"Enter size of array2: ";
    cin>>s;
    int b[s];
    cout<<"Enter array2 elements: ";
    for(int i=0;i<s;i++){
        cin>>b[i];
    }

    Intersection(a,n,b,s);

    return 0;
}
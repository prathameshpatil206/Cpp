#include<iostream>
using namespace std;

void search(int a[],int n,int s){
    int b=0,ps=1;
    int pos[n]={INT_MIN};
    for(int i=0;i<n;i++){
        if(a[i]==s){
            pos[b]=i;
            b++;
        }
    }

    for(int i=n-1;i>0;i--){
        if(pos[i]!=0){
            ps=i+1;
            break;
        }
    }

    if(pos[0]==INT_MIN){
        cout<<"Element not found";
    }else{
        cout<<"Element present at position";
        if(ps>1){
            cout<<"s";    
        }
        cout<<" ";
        for(int i=0;i<ps;i++){

            cout<<pos[i];

            if(ps>1 && i>=0 && i<=ps-2)
            {
                if(i !=ps-2){
                 cout<<", ";   
                }else{
                 cout<<" ";
                }
                
            }
            if(ps>1 && i==ps-2){
                cout<<"and ";
            }
        }
        cout<<" of the array";
    }
    
    
}

int main(){
    int n,s;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Element to be searched: ";
    cin>>s;
    search(a,n,s);
    return 0;
}
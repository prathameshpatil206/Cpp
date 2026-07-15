#include<iostream>
#include<vector>
using namespace std;

void pairSum(vector<int> a, int n,int tar){
    cout<<"Normal Method"<<endl;
    int sum=0;
    for(int i=0;i<n;i++)
    {   
        for(int j=i+1;j<n;j++)
        {
            sum=a[i]+a[j];
            if(sum==tar){
                cout<<"Pair at positions: "<<i<<" , "<<j<<endl<<endl;
            }
        }  
    }
 
}

void Optimised(vector<int> a, int n,int tar){
    // Array needs to be in ascending order.
    cout<<"Two pointer Method"<<endl;
    int i=0, j=n-1;
    while(i!=j)
    {
        int sum=a[i]+a[j];
        if(sum==tar)
        {
            cout<<"Pair at positions: "<<i<<" , "<<j<<endl;
            return;
        }
        if(sum>tar)
        {
            j--;
        }
        if(sum<tar)
        {
            i++;
        }
    }
 
}

int main()
{   
    vector<int> a={1,3,6,7,12,13};
    int target=10, n=a.size();
    pairSum(a,n,target);
    Optimised(a,n,target);
    return 0;
}
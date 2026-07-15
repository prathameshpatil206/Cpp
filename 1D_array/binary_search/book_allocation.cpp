#include<iostream>
#include<vector>
using namespace std;


bool isValid(vector<int> a,int n,int m,int mid)
{
    int sum=0,i,sc=1;
    for(i=0;i<n;i++)
    {   
        if(a[i]>mid)
        {
            return false;
        }
        int k=sum+a[i];
        if(k>mid)
        {
            sc++;
            sum=a[i];
        }else{
            sum=k;
        }
    }
    if(sc>m){
        return false;
    }
    return true;
}


void bin(vector<int> a,int m)
{
    int start=0,n=a.size(),ans=-1,mid,end,i,sum=0;
    if(m>n){
        cout<<ans<<endl;
        return;
    }
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    end=sum;

    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(isValid(a,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    vector<int> a={10, 20, 30, 40};
    int m=3;
    bin(a,m);   //113
    return 0;
}
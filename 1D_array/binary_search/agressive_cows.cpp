#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isValid(vector<int> a,int n, int c,int mid)
{
    int i,lsp=a[0],cc=1;
    for(i=1;i<n;i++)
    {
        if((a[i]-lsp)>=mid)
        {
            cc++;
            lsp=a[i];
        }
        if(cc==c)
        {
            return true;
        }
    }
    return false;
}

void bin(vector<int> a, int c)
{
    sort(a.begin(),a.end());
    int n=a.size(),start=1,end,mid,maxDis=-1,i;
    end=a[n-1]-a[0];
    if(c>n)
    {
        cout<<maxDis;
        return;
    }
    while(start<=end)
    {   
        mid=start+(end-start)/2;
        if(isValid(a,n,c,mid))
        {   
            maxDis=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }

    cout<<maxDis;
}
int main()
{
    vector<int> a={1,2,8,4,9};
    int c=3;
    bin(a,c);
    return 0;
}
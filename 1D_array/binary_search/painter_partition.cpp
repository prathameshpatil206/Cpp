#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> a, int n, int m, int mid)
{
    int sum=0,pc=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>mid)
        {
            return false;
        }

        if(sum+a[i]<=mid)
        {
            sum=sum+a[i];
        }else{
            pc++;
            sum=a[i];
        }
    }

    if(pc>m)
    {
        return false;
    }else{
        return true;
    }
}

void bin(vector<int> a, int m)
{
    int start=a[1],end,n=a.size(),mid,i,sum=0,minTime=-1;

    if(m>n)
    {
        cout<<minTime;
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
            minTime=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }

    cout<<minTime<<endl;
}

int main()
{
    vector<int> a={40,30,10,20};    //60
    int m=2;
    bin(a,m);
    return 0;
}
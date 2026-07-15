#include<bits/stdc++.h>
using namespace std;

void binary(vector<int> a,int st,int end,int tar)
{
    if(st>end)
    {
        cout<<tar<<"not found";
        return;
    }

    int mid=(st+end)/2;

    if(tar>a[mid])
    {
        binary(a,mid+1,end,tar);
    }else if(tar<a[mid]){
        binary(a,st,mid-1,tar);
    }else{
        cout<<"Element "<<tar<<" found at pos: "<<mid;
        return;
    }
    
}


//TC=log2(n)
//SC=log2(n)
int main()
{
    vector<int> a={1,2,3,4,5,6,7,8,9};
    int tar=3;

    binary(a,0,a.size()-1,tar);
    return 0;
}

//(a,0,8,3)->(a,0,3,3)->(a,2,3,3)
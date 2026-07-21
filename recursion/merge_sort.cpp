#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& a,int st,int mid, int end)
{
    int i=st;
    int j=mid+1;
    vector<int> c;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            c.push_back(a[i]);
            i++;
        }else{
            c.push_back(a[j]);
            j++;
        }
    }

    while(i<=mid)
    {
        c.push_back(a[i]);
        i++;
    }

    while(j<=end)
    {
        c.push_back(a[j]);
        j++;
    }

    for(int idx=0;idx<c.size();idx++)
    {
        a[st+idx]=c[idx];
    }
}


void merge_sort(vector<int>& a,int st,int end)
{

    if(st==end)
    {
        return;
    }
    int mid=st+(end-st)/2;

    merge_sort(a,st,mid);
    merge_sort(a,mid+1,end);
    merge(a,st,mid,end);
}

//TC=O(n * logn)
//SC=O(n)
int main()
{
    vector<int> a={12,31,35,9,32,17};

    merge_sort(a,0,a.size()-1);

    for(auto ele:a)
    {
        cout<<ele<<" ";
    }
    return 0;
}
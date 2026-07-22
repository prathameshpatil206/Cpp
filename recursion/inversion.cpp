#include<bits/stdc++.h>
using namespace std;

//Brute force: TC: O(n*n)
/*
int main()
{
    vector<int> a={6,3,5,2,7};
    vector<pair<int,int>> count;
    int n=a.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                count.push_back({a[i],a[j]});
            }
        }
    }

    for(auto p:count)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
*/


//Optimal 
void sort(vector<int>& a,int st,int mid,int end, int* count)
{
    vector<int> temp;
    int i=st;
    int j=mid+1;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            temp.push_back(a[i]);
            i++;
        }else{
            *count+=mid-i+1;
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while(j<=end)
    {
        temp.push_back(a[j]);
        j++;
    }

    for(int k=0;k<temp.size();k++)
    {
        a[st+k]=temp[k];
    }
}

void inversion(vector<int>& a,int st,int end, int* count)
{
    if(st==end)
    {
        return;
    }
    int mid=st+(end-st)/2;


    inversion(a,st,mid,count);
    inversion(a,mid+1,end,count);
    sort(a,st,mid,end,count);
    

}

//TC: O(n * logn)
int main()
{
    vector<int> a={1,3,5,10,2,6,8,9};
    int count=0;
    inversion(a,0,a.size()-1,&count);
    cout<<count;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int idid=0;

int partition(vector<int>&a, int st, int end)
{
    int i=st-1;
    int pvt=a[end];
    for(int j=st;j<end;j++)
    {
        if(a[j]<=pvt)
        {
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[end]);

    return i+1;
}

void quick_sort(vector<int>& a,int st, int end)
{
    if(st>=end)
    {
        return;
    }
    
    int pvt=partition(a,st,end);
    quick_sort(a,st,pvt-1);
    quick_sort(a,pvt+1,end);
}


//TC:
//Avg:  O(n * logn)
//Worst: O(n*n)

//SC: 
//O(logn)   --considering recursive stack
//O(1) -- ignoring recursive stack
int main()
{
    vector<int> a={6,3,5,9,1,4,2,7,8};
    quick_sort(a,0,a.size()-1);
    for(auto ele:a)
    {
        cout<<ele<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
//Dutch National Flag(DNF) Algorithm
void sort(vector<int> a)
{
    int n=a.size(),i;
    int low=0,mid=0,high=n-1;

    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);
            low++;
            mid++;
        }else if(a[mid]==1)
        {
         mid++;   
        }else{
            swap(a[high],a[mid]);
            high--;
        }
    }

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    vector<int> a={1,2,1,2,0,1,0,2,1,2,1,0,2,1};
    sort(a);
    return 0;
}
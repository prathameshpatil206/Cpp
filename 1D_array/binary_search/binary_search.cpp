#include<iostream>
#include<vector>
using namespace std;

//TC=O(logn) SC=O(1)
void binary(vector<int> a, int target)
{
    int n=a.size(),mid;
    int start=0, end=n-1,flag=0;

    while(start<=end)
    {
        mid=start +(end-start)/2; //optimization of mid=(start+end)/2; 

        if(target>a[mid])
        {
            start=mid+1;
        }else if(target<a[mid])
        {
            end=mid-1;
        }else{
            flag=1;
            cout<<"elemet "<<target<<" found at position: "<<mid<<endl;
            break;
        }
    }

    if(flag == 0)
    {
        cout<<"Element not found"<<endl;
    }
}

int main()
{
    vector<int> a={1,3,6,8,15};
    int target=15;
    binary(a,target);
}
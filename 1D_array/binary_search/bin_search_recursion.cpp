#include<iostream>
#include<vector>
using namespace std;

//TC=O(logn) SC=O(logn)

void binary(int start,int end,vector<int> a, int target)
{
    int mid;
    if(start<=end)
    {
        mid=start +(end-start)/2; //optimization of mid=(start+end)/2; 

        if(target>a[mid])
        {
            start=mid+1;
        }else if(target<a[mid])
        {
            end=mid-1;
        }else{
            cout<<"elemet "<<target<<" found at position: "<<mid<<endl;
            return;
        }

        binary(start,end,a,target);
    }
    else{
        cout<<"Element not found"<<endl;
    }

}

int main()
{
    vector<int> a={1,3,6,8,15};
    int target=10;
    binary(0,a.size(),a,target);
}
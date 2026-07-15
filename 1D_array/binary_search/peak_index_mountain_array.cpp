#include<iostream>
#include<vector>
using namespace std;

void bin(vector<int> a)
{
    int start=1,end=a.size()-2,mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;

        if(a[mid-1]<a[mid] && a[mid]>a[mid+1])
        {
            cout<<"Peak index: "<<mid<<endl;
            return;
        }

        if(a[mid-1]<a[mid])
        {
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
}

int main()
{
    vector<int> a={0,3,7,8,9,5,2};
    bin(a);
    return 0;
}
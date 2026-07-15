#include<iostream>
#include<vector>
using namespace std;

void bin(vector<int> a)
{
    int start=0,end=a.size()-1,mid;

    if(a[0]!=a[1])
    {
        cout<<"Single element "<<a[0]<<" found at pos "<<"0"<<endl;
        return;
    }

    if(a[end]!=a[end-1])
    {
        cout<<"Single element "<<a[end]<<" found at pos "<<end<<endl;
        return;
    }

    while(start<=end)
    {
        mid=start+(end-start)/2;

        if(a[mid-1]!=a[mid] && a[mid]!=a[mid+1])
        {
            cout<<"Single element "<<a[mid]<<" found at pos "<<mid<<endl;
            return;
        }

        if(mid%2==0)
        {
            if(a[mid]==a[mid+1])
            {
                start=mid+2;
            }else{
                end=mid-2;
            }
        }else{
            if(a[mid]==a[mid+1])
            {
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
    }
}

int main()
{
    vector<int> a={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};
    bin(a);
    return 0;
}
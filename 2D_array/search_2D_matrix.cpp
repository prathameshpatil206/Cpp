#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m=3,n=4;
    int a[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    

    int k;
    cout<<"Enter the element to search: ";
    cin>>k;

    int mid;
    int st=0, end=m-1;
    while(st<=end)
    {
        mid=(st+end)/2;
        if(k<a[mid][0])
        {
            end=mid-1;
        }else if(k>a[mid][n-1])
        {
            st=mid+1;
        }else{
            break;
        }
    }

    int s_row=mid;
    cout<<s_row<<endl;
    st=0, end=n-1;
    while(st<=end)
    {
        mid=(st+end)/2;
        if(a[s_row][mid]>k)
        {
            end=mid-1;
        }else if(a[s_row][mid]<k)
        {
            st=mid+1;
        }else{
            cout<<k<<" found at row "<<s_row<<" column "<<mid<<endl;
            exit(0);
        }
    }

    cout<<k<<" not found.";


    return 0;
}
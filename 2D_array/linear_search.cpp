#include<bits/stdc++.h>
using namespace std;


pair<int,int> linear_search(int a[][4],int r,int c,int k)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==k)
            {
                return {i,j};
            }
        }
    }

    return {-1,-1};
}

int main()
{
    int a[3][4];
    
    cout<<"Enter 12 elements: ";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"elements of array are:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int k;
    cout<<"Enter the element to search: ";
    cin>>k;


    pair<int,int> p=linear_search(a,3,4,k);
    if(p.first==-1 && p.second==-1)
    {
        cout<<k<<" not found. ";
    }else{
        cout<<k<<" found at row "<<p.first<<" and column "<<p.second;
    }

    return 0;
}
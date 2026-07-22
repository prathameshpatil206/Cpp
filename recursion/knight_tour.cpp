#include<bits/stdc++.h>
using namespace std;


bool valid_grid(vector<vector<int>>& a,int i, int j,int num,int n)
{
    if(num>=n*n)
    {
        return true;
    }


    int r,c;
    if((i-2>=0 && j-1>=0) && a[i-2][j-1]==num)
    {
        r=i-2;
        c=j-1;
    }else if((i-2>=0 && j+1<n) && a[i-2][j+1]==num)
    {
        r=i-2;
        c=j+1;
    }else if((i+2<n && j-1>=0) && a[i+2][j-1]==num)
    {
        r=i+2;
        c=j-1;
    }else if((i+2<n && j+1<n) && a[i+2][j+1]==num)
    {
        r=i+2;
        c=j+1;
    }else if((i-1>=0 && j-2>=0) && a[i-1][j-2]==num)
    {
        r=i-1;
        c=j-2;
    }else if((i-1>=0 && j+2<n) && a[i-1][j+2]==num)
    {
        r=i-1;
        c=j+2;
    }else if((i+1<n && j-2>=0) && a[i+1][j-2]==num)
    {
        r=i+1;
        c=j-2;
    }else if((i+1<n && j+2<n) && a[i+1][j+2]==num)
    {
        r=i+1;
        c=j+2;
    }else{
        return false;
    }

    return valid_grid(a,r,c,num+1,n);
}

//TC: O(n^2)
//SC: O(n^2)
int main()
{
    vector<vector<int>> a= 
    {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };

    int n=a.size();
    if(valid_grid(a,0,0,1,n))
    {
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}
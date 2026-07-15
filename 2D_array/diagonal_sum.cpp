#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=3;
    int a[n][n]={{1,2,3},{4,5,6},{7,8,9}};

    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=a[i][i]+a[i][n-1-i];
    }

    if(n%2==1)
    {
        sum=sum-a[n/2][n/2];
    }

    cout<<"Diagonal sum: "<<sum;
}
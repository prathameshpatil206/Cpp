#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    int max=0;

    for(int i=0;i<3;i++)
    {
        int r_sum=0;
        for(int j=0;j<3;j++)
        {
            r_sum +=a[i][j];
        }

        if(r_sum>max)
        {
            max=r_sum;
        }
    }

    cout<<"Max sum: "<<max;
}
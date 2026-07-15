#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m=5,n=5;
    int a[5][5] = {
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
};
    

    int k;
    cout<<"Enter the element to search: ";
    cin>>k;
    int len=n-1,bred=0;
    int mid=a[0][n-1];
    while(len>0 && bred<m)
    {
        mid=a[bred][len];
        if(k<mid)
        {
            len--;
        }else if(k>mid)
        {
            bred++;
        }else{
            cout<<k<<" found at row "<<bred<<" column "<<len;
            exit(0);
        }
    }

    

    cout<<k<<" not found.";


    return 0;
}
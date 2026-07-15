#include<iostream>
#include<vector>
using namespace std;

void sort(int a[], int n,int b[],int m)
{
    int i,pa=n-1,pb=m-1;
    for(i=m+n-1;i>=0;i--)
    {
        if(pb<0)
        {
            break;
        }
        if(a[pa]>b[pb]&& pa>=0)
        {
            a[i]=a[pa];
            pa--;
        }else if(pb>=0){
            a[i]=b[pb];
            pb--;
        }
    }


    for(i=0;i<n+m;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[7]={1,2,3,4,0,0,0};
    int b[3] ={2,5,6};
    sort(a,4,b,3);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> a)
{
    int n=a.size(),i,j,temp;

    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }

    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    vector<int> a={30,20,11,23,40,64,9,13};
    sort(a);
    return 0;
}
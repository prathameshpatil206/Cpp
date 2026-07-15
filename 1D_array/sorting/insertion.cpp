#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> a)
{
    int n=a.size(),i,prev,curr;

    for(i=1;i<n;i++)
    {
        curr=a[i];
        prev=i-1;
        while(prev>=0 && a[prev]>curr)
        {
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }

    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    vector<int> a={30,20,11,100,40,64,9,13};
    vector<int> b={10,20,30,40,50,60};
    sort(a);
    return 0;
}
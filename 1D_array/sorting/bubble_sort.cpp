#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> a)
{
    int n=a.size(),i,j,temp;
    bool isSwap=false;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                isSwap=true;
            }
        }
    }

    if(isSwap)
    {
        cout<<"Aldready sorted"<<endl;
        return;
    }

    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    vector<int> a={30,20,11,23,40,64,9,11};
    vector<int> b={10,20,30,40,50};
    sort(a);
    sort(b);
    return 0;
}
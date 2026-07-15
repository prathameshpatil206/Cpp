#include<iostream>
#include<vector>
using namespace std;

void profit(vector<int> a)
{
    int n=a.size(), minBuy=a[0],mp=0;

    for(int i=1;i<n;i++)
    {
        if(a[i]>minBuy)
        {
            mp=max(mp,a[i]-minBuy);
        }
        minBuy=min(a[i],minBuy);
    }
    cout<<"Max Profit: "<<mp;
}

int main()
{   
    vector<int> a={1,3,6,7,12,13};
    profit(a);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> a={1,2,3,4};
    int product=1,ans[100],i,n=a.size();
    ans[0]=1;
    for(i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*a[i-1];
    }
    for(i=n-2;i>=0;i--)
    {
        product *= a[i+1];
        ans[i]=ans[i]*product;
    }
    
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
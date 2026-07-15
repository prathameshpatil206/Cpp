#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<int> a,int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            return true;
        }
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return false;
}

void np(vector<int> a)
{
    int i,j,k,l,b,c,n=a.size();

    while(check(a,n))
    {
        cout<<endl;
        for(j=0;j<n;j++)
        {
            cout<<a[j]<<" ";
        }

        for(k=n-2;k>=0;k--)
        {
            if(a[k]<a[k+1])
            {
                for(b=n-1;b>=k+1;b--)
                {
                    if(a[b]>a[k])
                    {
                        swap(a[b],a[k]);
                        break;
                    }
                }

                for(l=0;l<(n-k-1)/2;l++)
                {
                    swap(a[k+1+l],a[n-l-1]);
                }
                break;
            }
        }
    }

}

int main()
{
    vector<int> a={1,3,4,2};
    np(a);
    return 0;
}
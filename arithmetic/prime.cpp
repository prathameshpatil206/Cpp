#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }

    return true;
}

int primeCountInRange(int m)
{
    int i,count=0;
    vector<bool> a(m+1,true);
    for(i=2;i<m;i++)
    {
        if(a[i])
        {
            count++;

            for(int j=i*2;j<m;j=j+i)
            {
                a[j]=false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    if(prime(n))
    {
        cout<<"Prime"<<endl;
    }else{
        cout<<"Not Prime"<<endl;
    }

    cout<<primeCountInRange(50);
    return 0;
}
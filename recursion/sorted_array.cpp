#include<bits/stdc++.h>
using namespace std;

void sorted(vector<int> a,int i)
{
    int n=a.size();
    if(i==n-1)
    {
        cout<<"List is sorted";
        return;
    }

    if(a[i]>a[i+1])
    {
        cout<<"Not sorted";
        return;
    }

    sorted(a,i+1);
}

//TC=O(n)
//SC=O(n)
int main()
{
    vector<int> a={1,2,3,4,5};
    
    sorted(a,0);
    return 0;
}

// (a,0)->(a,1)->(a,2)->(a,3)->(a,4)
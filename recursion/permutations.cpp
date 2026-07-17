#include<bits/stdc++.h>
using namespace std;


void permutation(vector<int>& a,int idx,vector<vector<int>>& prmts)
{

    int n=a.size();
    if(idx==n)
    {
        prmts.push_back({a});
        return;
    }

    for(int i=idx;i<n;i++)
    {
        swap(a[idx],a[i]);
        permutation(a,idx+1,prmts);
        swap(a[idx],a[i]);
    }
}


//TC=O(n! * n)
//SC=O(n!)
int main()
{
    vector<int> a={1,2,3,4};
    vector<vector<int>> prmts;
    permutation(a,0,prmts);

    for(auto v:prmts)
    {
        for(auto ele:v)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}
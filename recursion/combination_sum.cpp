#include<bits/stdc++.h>
using namespace std;

void comb_sum(vector<int>& a,int k,vector<int>& comb,vector<vector<int>>& ans, int tar)
{

    if(tar<0)
    {
        return;
    }

    if(tar==0)
    {
        ans.push_back({comb});
        return;
    }

    for(int j=k;j<a.size();j++)
    {
        comb.push_back(a[j]);
        comb_sum(a,j,comb,ans,tar-a[j]);
        comb.pop_back();
    }
}

int main()
{
    vector<int> a={2,3,5};
    int tar=8;
    vector<int> comb;
    vector<vector<int>> ans;
    comb_sum(a,0,comb,ans,tar);
    for(auto v:ans)
    {
        for(auto ele:v)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void subset(vector<int>& a, vector<int>& ans,int i,vector<vector<int>>& allSubsets)
{
    int n=a.size();

    if(i==n)
    {
        allSubsets.push_back({ans});
        return;
    }

    
    ans.push_back(a[i]);
    subset(a,ans,i+1,allSubsets);
    ans.pop_back();
    i++;
    while(i<n && a[i]==a[i-1])
    {
        i++;
    }
    
    subset(a,ans,i,allSubsets);
    
}

//TC=O(nlogn + n * 2^n)  ~~ O(n * 2^n)
//SC=O(n)
int main()
{
    vector<vector<int>> allSubsets;
    vector<int> ans;
    vector<int> a={1,2,2,3,2};
    int n=a.size();

    sort(a.begin(),a.end());
    subset(a,ans,0,allSubsets);
    for(auto v:allSubsets)
    {
        for(auto ele:v)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;

}


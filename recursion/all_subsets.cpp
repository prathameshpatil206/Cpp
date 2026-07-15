#include<bits/stdc++.h>
using namespace std;

void subset(vector<int>& a, vector<int>& ans,int i)
{
    int n=a.size();

    if(i==n)
    {
        for(auto ele:ans)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
        return;
    }

    subset(a,ans,i+1);
    ans.push_back(a[i]);
    subset(a,ans,i+1);
    ans.pop_back();
    
}

//TC=O(n * 2^n)
//SC=O(n)
int main()
{

    vector<int> ans;
    vector<int> a={1,2,3};
    int n=a.size();
    subset(a,ans,0);

    return 0;

}


#include<bits/stdc++.h>
using namespace std;


//TC:O(n)
//SC:O(n)
int main()
{
    vector<int> a={6,8,0,1,3};
    stack<int> s;
    vector<int> ans(a.size());
    for(int i=a.size()-1;i>=0;i--)
    {

        while((!s.empty()) && s.top()<=a[i])
        {
            s.pop();
        }

        if(s.empty())
        {
            ans[i]=-1;
        }else
        {
            ans[i]=s.top();
        }

        s.push(a[i]);
    }

    for(auto ele: ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}
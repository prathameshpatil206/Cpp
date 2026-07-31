#include<bits/stdc++.h>
using namespace std;


//TC:O(n)
//SC:O(n)
int main()
{
    vector<int> a={3,1,0,8,6};
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<a.size();i++)
    {

        while((!s.empty()) && s.top()>=a[i])
        {
            s.pop();
        }

        if(s.empty())
        {
            ans.push_back(-1);
        }else
        {
            ans.push_back(s.top());
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
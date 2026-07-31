#include<bits/stdc++.h>
using namespace std;


//TC:O(n)
//SC:O(n)
int main()
{
    vector<int> stock={100,80,60,70,60,75,85};
    stack<int> s;
    vector<int> span;
    span.push_back(1);
    s.push(0);
    int sp;
    for(int i=1;i<stock.size();i++)
    {
        while(stock[s.top()]<=stock[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            sp=i-s.top();
        }else{
            sp=i+1;
        }
        
        
        span.push_back(sp);
        
        s.push(i);
    }

    for(auto val:span)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
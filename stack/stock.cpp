#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//TC: O(n)
//SC: O(n)

int main()
{
    vector<int> a={100,80,60,70,60,75,85};
    vector<int> span={1};
    stack<int> s;
    s.push(0);
    int i;
    for(i=1;i<a.size();i++)
    {
        while(s.size()>0 && a[s.top()]<a[i])
        {
            s.pop();
        }

        if(s.size()==0)
        {
            span.push_back(i+1);
        }else{
            span.push_back(i-s.top());
        }
        
        s.push(i);
    }

    for(i=0;i<span.size();i++)
    {
        cout<<span[i]<<"\t";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    vector<int> a;

    void push(int val)
    {
        a.push_back(val);
    }

    void pop()
    {
        a.pop_back();
    }

    int top()
    {
        return a[a.size()-1];
    }

    bool empty()
    {
        return a.size()==0;
    }
};

int main()
{
    Stack s;


    s.push(20);
    s.push(10);
    s.push(30);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
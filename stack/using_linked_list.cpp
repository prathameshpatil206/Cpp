#include<iostream>
#include<list>
using namespace std;

class Stack
{
    list<int> l1;
    public:

    void push(int val)//O(1)
    {
        l1.push_front(val);
    }

    void pop()//O(1)
    {
        l1.pop_front();
    }

    int top()//O(1)
    {
        return l1.front();
    }

    bool empty()
    {
        return l1.size()==0;
    }
};


int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty())
    {
        cout<<s.top()<<'\t';//30 20 10
        s.pop();
    }
    return 0;
}
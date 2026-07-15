#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q,q2;//FIFO
    q.push(1);
    q.emplace(2);
    q.push(3);
    cout<<q.size()<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    q.push(1);
    q.push(2);
    q.push(3);
    q2.swap(q);
    cout<<endl<<q2.back()<<endl;
    cout<<q.empty()<<endl;      //1
    return 0;
}
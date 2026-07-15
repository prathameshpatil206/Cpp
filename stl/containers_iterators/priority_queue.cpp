#include<iostream>
#include<queue>
using namespace std;
int main()
{   //visualize like a stack
    priority_queue<int> pq;//largest value=> highest priority
    pq.push(5);
    pq.push(3);//largest element always at top
    cout<<"Top: "<<pq.top()<<" Size: "<<pq.size()<<endl;
    pq.push(10);
    cout<<"Top: "<<pq.top()<<" Size: "<<pq.size()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<" Size: "<<pq.size()<<endl;

    //for smallest element at the top
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(5);
    q.push(3);//largest element always at top
    cout<<"Top: "<<q.top()<<" Size: "<<q.size()<<endl;
    q.push(10);
    cout<<"Top: "<<q.top()<<" Size: "<<q.size()<<endl;
    q.pop();
    cout<<"Top: "<<q.top()<<" Size: "<<q.size()<<endl;

    return 0;
}
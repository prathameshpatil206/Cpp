#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    list<int> ll;


    void enqueue(int val)
    {
        ll.push_back(val);
    }

    void dequeue()
    {
        ll.pop_front();
    }

    int front()
    {
        return ll.front();
    }

    void display()
    {
        while(!ll.empty())
        {
            cout<<front()<<" ";
            dequeue();
        }
        cout<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout<<q.front()<<endl;

    q.dequeue();

    cout<<q.front()<<endl;

    q.display();
    return 0;
}
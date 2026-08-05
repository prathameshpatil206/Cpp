#include<bits/stdc++.h>
using namespace std;


class CircQueue
{
    int currSize;
    int cap;
    int * arr;
    int front;
    int rear;

    public:
    CircQueue(int size)
    {
        cap=size;
        arr=new int[cap];
        front=0;
        rear=-1;
        currSize=0;
    }
    void push(int val)
    {
        if(full())
        {
            cout<<"No space left. "<<endl;
            return;
        }
        currSize++;
        rear=(rear+1)%cap;
        arr[rear]=val;
    }

    void pop()
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        currSize--;
        int temp=arr[front];
        front=(front+1)%cap;
    }

    int front_()
    {
        return arr[front];
    }

    bool empty()
    {
        if (currSize==0)
        {
            return true;
        }

        return false;
    }

    bool full()
    {
        if(currSize==cap)
            return true;

        return false;
    }

    
};

int main()
{
    CircQueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);

    cq.pop();
    cq.pop();
    cq.pop();

    cq.push(60);
    cq.push(70);

    while(!cq.empty())
    {
        cout<<cq.front_()<<" ";
        cq.pop();
    }
    cout<<endl;
    
    return 0;
}
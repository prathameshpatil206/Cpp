#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next=NULL;

    Node(int val)
    {
        this->data=val;
    }
};

class Queue{
    Node* head;
    Node* tail;
    public:
    Queue()
    {
        head=tail=NULL;
    }
    
    void enqueue(int val)
    {
        Node* temp=new Node(val);
        if(head==NULL)
        {
            head=tail=temp;
            return;
        }

        tail->next=temp;
        tail=temp;
    }

    void dequeue()
    {
        if(head==NULL)
        {
            return;
        }
        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            return;
        }

        Node* temp=head->next;
        delete head;
        head=temp;
    }

    int front()
    {
        if(head!=NULL)
            return head->data;
        
        return INT_MIN;
    }

    void display()
    {
        while(head!=NULL)
        {
            cout<<front()<<" ";
            dequeue();
        }
        
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
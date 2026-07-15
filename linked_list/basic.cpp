#include<iostream>

class Node
{
    public:
        int data;
        Node *next;

        Node(int val)
        {
            data = val;
            next=NULL;
        }
};

class List
{
    Node *head;
    Node *tail;

    public:
    List()
    {
        head=tail=NULL;
    }

    void push_front(int val)
    {
        Node *n;
        n=new Node(val);
        if(head ==NULL)
        {
            head=tail=n;
            return;
        }
    }
};

int main()
{
    List ll;
    return 0;
}
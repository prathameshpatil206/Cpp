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


class CircularList
{
    Node* head=NULL;
    Node* tail=NULL;

    public:
    void push_front(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=tail=newNode;
            head->next=head;
            return;
        }

        newNode->next=tail->next;
        tail->next=newNode;
        head=newNode;
    }

    void push_back(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=tail=newNode;
            head->next=head;
            return;
        }

        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"List is empty\n";
            return;
        }
        Node* temp=head;

        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);

        cout<<endl;
    }

    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"List is empty\n";
            return;
        }

        cout<<head->data<<" deleted."<<endl;

        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            return;
        }        

        tail->next=head->next;
        delete head;
        head=tail->next;

    }

    void pop_back()
    {
        if(head==NULL)
        {
            cout<<"List is empty\n";
            return;
        }

        cout<<tail->data<<" deleted."<<endl;

        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            return;
        }        

        Node* temp=head;
        Node* prev;
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }

        prev->next=temp->next;
        delete temp;
        tail=prev;

    }
};

int main()
{
    CircularList cl;

    cl.push_back(30);
    cl.push_back(40);
    cl.push_front(20);
    cl.push_front(10);

    cl.display();

    cl.pop_back();
    cl.pop_front();
    
    cl.display();
    
    return 0;
}
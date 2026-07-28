#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next=NULL;
    Node* prev=NULL;

    Node(int val)
    {
        this->data=val;
    }
};

class DoublyList
{
    Node* head=NULL;
    Node* tail=NULL;

    public:

    void push_back(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void push_front(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }

    void insert_pos(int val,int pos)
    {
        if(pos==0)
        {
            push_front(val);
            return;
        }

        int count=0;
        Node*temp=head;
        while(temp!=NULL && count!=pos)
        {
            temp=temp->next;
            count++;
        }

        if(count==pos)
        {
            if(temp==NULL)
            {
                push_back(val);
                return;
            }

            Node* newNode=new Node(val);
            temp->prev->next=newNode;
            newNode->prev=temp->prev;
            newNode->next=temp;
            temp->prev=newNode;

        }else{
            cout<<"Invalid position"<<endl;
        }
    }

    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        cout<<head->data<<" deleted."<<endl;
        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            return;
        }

        head->next->prev=NULL;
        Node* temp=head;
        head=head->next;
        delete temp;

    }

    void pop_back()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        cout<<tail->data<<" deleted."<<endl;
        if(head==tail)
        {
            delete tail;
            head=tail=NULL;
            return;
        }

        tail->prev->next=NULL;
        Node* temp=tail;
        tail=tail->prev;
        delete temp;

    }

    void delete_pos(int pos)
    {
        if(pos==0)
        {
            pop_front();
            return;
        }

        int count=0;
        Node*temp=head;
        while(temp!=NULL && count!=pos)
        {
            temp=temp->next;
            count++;
        }

        if(count==pos)
        {
            if(temp->next==NULL)
            {
                pop_back();
                return;
            }

            cout<<temp->data<<" deleted."<<endl;
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            delete temp;

        }else{
            cout<<"Invalid position"<<endl;
        }
    }

    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    DoublyList dl;
    dl.push_back(30);
    dl.push_back(40);
    dl.push_back(50);
    dl.push_front(20);
    dl.push_front(10);
    dl.display();
    dl.pop_back();
    dl.pop_front();
    dl.display();

    dl.insert_pos(10,0);
    dl.insert_pos(50,4);
    dl.insert_pos(25,2);

    dl.display();

    dl.delete_pos(0);
    dl.delete_pos(4);
    dl.delete_pos(1);

    dl.display();
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

        int data;
        Node *next;

        Node(int val)
        {
            this->data=val;
            this->next=NULL;
        }
};


class List
{
    Node* head;
    Node* tail;

public:
    List()
    {
        head=tail=NULL;
    }

    void push_front(int val)
    {   
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void push_back(int val)
    {   
        Node* newNode=new Node(val);
        if(head==NULL)
        {
            head=tail=newNode;
            return;
        }
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
    }

    void insert_pos(int val,int pos)
    {
        
        if(pos==0)
        {
            this->push_front(val);
            return;
        }
        int count=0;
        Node *temp=head;
        Node *p;
        while(count!=pos && temp!=NULL)
        {
            p=temp;
            count++;
            temp=temp->next;
        }

        if(pos==count)
        {
            if(temp==NULL)
            {
                this->push_back(val);
                return;
            }
            Node *newNode=new Node(val);
            p->next=newNode;
            newNode->next=temp;

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
        Node *temp=head;
        head=head->next;
        if(head==NULL)
        {
            tail==NULL;
        }
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
            delete head;
            head=tail=NULL;
            return;
        }
    
        Node *t=head;
        while(t->next!=tail)
        {
            t=t->next;
        }
        Node *temp=t->next;
        t->next=NULL;
        tail=t;
        delete temp;
    }

    void delete_pos(int pos)
    {
        
        if(pos==0)
        {
            this->pop_front();
            return;
        }
        int count=0;
        Node *temp=head;
        Node *p;
        while(count!=pos && temp->next!=NULL)
        {
            p=temp;
            count++;
            temp=temp->next;
        }

        if(pos==count)
        {
            if(temp==tail)
            {
                this->pop_back();
                return;
            }
            p->next=temp->next;
            cout<<temp->data<<" deleted."<<endl;
            delete temp;

        }else
        {
            cout<<"Invalid position"<<endl;
        }
    }

    void search(int val)
    {
        Node*temp=head;
        int pos=0;
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                cout<<"Data found at pos: "<<pos<<endl;
                return;
            }
            pos++;
            temp=temp->next;
        }

        cout<<val<<" not found."<<endl;
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        Node *t=head;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    int middle()
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=tail && fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};


int main()
{
    List ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);
    ll.push_back(50);
    ll.push_back(60);
    ll.display();

    cout<<ll.middle();
    return 0;
}
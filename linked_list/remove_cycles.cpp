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

void display(Node *head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node*t=new Node(10);
    Node* head=t;
    t->next=new Node(20);
    t=t->next;
    Node *cycled_to =t;
    t->next=new Node(30);
    t=t->next;
    
    t->next=new Node(40);
    t=t->next;
    t->next=new Node(50);
    t=t->next;
    t->next=new Node(60);
    t=t->next;
    t->next=cycled_to;

    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            break;
        }
    }

    if(fast->next==NULL || fast==NULL)
    {
        cout<<"Not cycled"<<endl;
    }else{
        cout<<"cycled"<<endl;
    }

    if(slow==fast)
    {
        Node* prev;
        slow=head;
        while(slow!=fast)
        {
            prev=fast;
            slow=slow->next;
            fast=fast->next;
        }

        prev->next=NULL;
        cout<<slow->data<<endl;
        display(head);
    }
    return 0;
}


    // Node* temp=head;
    // Node* curr;
    // Node* got;
    // Node* prev;
    // bool hehe=true;
    // while(hehe)
    // {
    //     temp=head;
    //     while(temp->next!=slow)
    //     {
    //         temp=temp->next;
    //     }
    //     curr=temp;
    //     temp=slow->next;
    //     hehe=false;
    //     while(temp!=slow)
    //     {
    //         if(temp==curr)
    //         {
    //             hehe=true;
    //             got=temp;
    //             break;
    //         }
    //         prev=temp;
    //         temp=temp->next;
    //     }
    //     slow=curr;
    // }

    // cout<<got->data<<endl;
    // cout<<prev->data<<endl;
    // prev->next=NULL;
    // display(head);
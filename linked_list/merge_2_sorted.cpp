#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};

class List
{
    public:
    
        Node *head=NULL;
        Node *tail=NULL;
    
        void create_list(list<int> l)
        {
            for(auto val:l)
            {
                Node* newNode=new Node(val);
                if(head==NULL)
                {
                    head=tail=newNode;
                    continue;
                }

                tail->next=newNode;
                tail=newNode;
            }
        }
};

Node* merge(Node* h1, Node*h2)
{
    if(h1==NULL)
    {
        return h2;
    }

    if(h2==NULL)
    {
        return h1;
    }

    if(h1->data <= h2->data)
    {
        h1->next=merge(h1->next,h2);
        return h1;
    }else{
        h2->next=merge(h1,h2->next);
        return h2;
    }
}

//TC: O(n+m)
int main()
{
    List l1;
    l1.create_list({1,4,8,10,20});
    List l2;
    l2.create_list({2,3,5,6,15,17,21,25,30});

    Node*merged_head=merge(l1.head,l2.head);

    Node*temp=merged_head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;

    return 0;
}


    // Node*temp1=l1.head;
    // Node* t;
    // Node* prev=NULL;
    // while(temp1!=NULL && l2.head!=NULL)
    // {
    //     if(temp1->data<=l2.head->data)
    //     {
    //         prev=temp1;
    //         temp1=temp1->next;
    //     }else{
    //         if(prev==NULL)
    //         {
    //             t=l2.head->next;
    //             l2.head->next=l1.head;
    //             prev=l1.head=l2.head;
    //             l2.head=t;
                
    //         }else{
    //             t=l2.head;
    //             prev->next=l2.head;
    //             l2.head=l2.head->next;
    //             prev->next->next=temp1;
    //             prev=t;
    //         }
            
    //     }
    // }

    // if(l2.head!=NULL);
    // {
    //     prev->next=l2.head;
    // }
    

    // temp1=l1.head;
    // while(temp1!=NULL)
    // {
    //     cout<<temp1->data<<" ";
    //     temp1=temp1->next;
    // }
    // cout<<endl;
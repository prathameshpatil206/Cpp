#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next=NULL;
    Node* random=NULL;

    Node(int val)
    {
        this->data=val;
    }

};

//TC:O(n)
//SC:O(n)
void copy_list(Node* head)
{
    Node* chead=new Node(head->data);
    Node* temp=head->next;
    Node* ctemp=chead;
    map<Node*,Node*> crpdn;
    crpdn[head]=chead;
    while(temp!=NULL)
    {
        Node* newNode=new Node(temp->data);
        ctemp->next=newNode;
        ctemp=newNode;
        crpdn[temp]=newNode;
        temp=temp->next;
    }

    temp=head;
    ctemp=chead;
    
    while(temp!=NULL)
    {
        if(temp->random!=NULL)
        {
           ctemp->random=crpdn[temp->random];
        }
        temp=temp->next;
        ctemp=ctemp->next;
    }

    temp=chead;

    cout<<"Node\tNext\tRandom"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        if(temp->next!=NULL)
        {
            cout<<temp->next->data;
        }else{
            cout<<"NULL";
        }
        cout<<"\t";
        if(temp->random!=NULL)
        {
            cout<<temp->random->data;
        }else{
            cout<<"NULL";
        }

        cout<<endl;
        temp=temp->next;
    }
}

int main()
{
    Node* head= new Node(7);   
    head->next=new Node(13);
    head->next->next=new Node(11);
    head->next->next->next=new Node(10);
    head->next->next->next->next=new Node(1);
    head->next->next->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->random=head->next->next->next->next;
    head->next->random=head;

    copy_list(head);
    return 0;
}
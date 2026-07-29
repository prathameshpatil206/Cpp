#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode*next=NULL;

    ListNode(int val)
    {
        this->data=val;
    }
};


//TC:O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        ListNode* tail=NULL;
        head=temp->next;
        ListNode* swaptemp;
        while(temp!=NULL)
        {
            if(temp->next==NULL)
            {
                if(tail!=NULL)
                {
                    tail->next=temp;
                }
                
                break;
            }
            swaptemp=temp->next->next;
            temp->next->next=temp;
            if(tail!=NULL)
            {
                tail->next=temp->next;
            }
            
            temp->next=swaptemp;
            tail=temp;
            temp=swaptemp;
            

        }

        return head;

    }
};

void display(ListNode* head)
{
    ListNode* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    ListNode* head=new ListNode(10);
    head->next=new ListNode(20);
    head->next->next=new ListNode(30);
    head->next->next->next=new ListNode(40);
    head->next->next->next->next=new ListNode(50);

    display(head);

    Solution s;
    head=s.swapPairs(head);

    display(head);
    return 0;
}
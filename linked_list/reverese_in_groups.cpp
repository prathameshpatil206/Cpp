#include<bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int data;
    ListNode *next;
};


//TC:O(n)
class Solution {
public:

    ListNode* reverse(ListNode*head,int k)
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode*temp=head;
        ListNode* swaptemp;
        ListNode* newhead;
        int count =0;

        while(temp!=NULL && count!=k)
        {
            
            swaptemp=temp->next;
            temp->next=prev;
            prev=temp;
            newhead=temp;
            temp=swaptemp;
            count++;
        }

        if(count==k)
        {
            head->next=reverse(temp,k);
        }else
        {
            if(temp==NULL)
            {
                temp=prev;
                prev=NULL;
                while(temp!=NULL)
                {
                    swaptemp=temp->next;
                    temp->next=prev;
                    prev=temp;
                    newhead=temp;
                    temp=swaptemp;

                }
            }
        }
        return newhead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        head=reverse(head,k);
        return head;

    }
};
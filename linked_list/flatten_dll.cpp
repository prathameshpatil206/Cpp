#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

//TC=O(n^2)
class Solution {
public:

    Node* recurse(Node* head)
    {
        Node* temp = head;

        while (temp!=NULL)
        {
            if (temp->child != NULL)
            {
                Node* ttemp = temp->next;

                temp->next = recurse(temp->child);
                temp->next->prev = temp;
                temp->child = NULL;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = ttemp;

                if (ttemp)
                    ttemp->prev = temp;
            }

            temp = temp->next;
        }

        return head;
    }

    Node* flatten(Node* head) {
        
        head=recurse(head);
        return head;
    }
};
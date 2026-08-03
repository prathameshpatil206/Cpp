#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int val;
    Node* prev=NULL;
    Node* next=NULL;

    Node(int kkey, int vaal)
    {
        this->key=kkey;
        this->val=vaal;
    }
};

class DLL{
    Node* head=NULL;
    Node* tail=NULL;
    unordered_map<int,Node*> mappi;
    public:
    int count=0;
    void insert_rear(int kkey, int vaal)
    {
        count++;
        Node* temp=new Node(kkey,vaal);
        mappi[kkey]=temp;
        if(head==NULL)
        {
            head=tail=temp;
            return;
        }

        tail->next=temp;
        temp->prev=tail;
        tail=temp;

    }

    void delete_front()
    {
        count--;
        mappi.erase(head->key);
        if(head==tail)
        {
            delete head;
            head=tail=NULL;
            return;
        }

        Node* temp=head->next;
        delete head;
        head=temp;
        head->prev=NULL;
    }

    Node* search(int keey)
    {
        if(mappi.count(keey)==1)
        {
            return mappi[keey];
        }

        return NULL;
    }

    void modify(Node *ad)
    {
        if(ad==tail)
        {
            return;
        }

        if(ad!=head)
        {
            ad->prev->next=ad->next;
        }
        if(ad==head)
        {
            head=ad->next;
        }
        ad->next->prev=ad->prev;
        ad->prev=tail;
        ad->next=NULL;
        tail->next=ad;
        tail=ad;
    }
};

class LRUCache {
public:

    int cap;
    DLL doll;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        Node* temp=doll.search(key);
        if(temp==NULL)
        {
            return -1;
        }else
        {
            doll.modify(temp);
            return temp->val;
        }
    }
    
    void put(int key, int value) {
        Node* temp=doll.search(key);
        if(temp==NULL)
        {
            if(doll.count<cap)
            {
                doll.insert_rear(key,value);
            }else
            {
                doll.delete_front();
                doll.insert_rear(key,value);
            }
        }else{
            temp->val=value;
            doll.modify(temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
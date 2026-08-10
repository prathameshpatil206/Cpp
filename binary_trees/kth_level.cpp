#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* create(vector<int>& preorder,int* i)
{
    (*i)++;
    if(preorder[*i]==-1)
    {
        return NULL;
    }

    Node* curr=new Node(preorder[*i]);

    curr->left=create(preorder,i);
    curr->right=create(preorder,i);

    return curr;
}

//TC: O(n);
void print_kth_level(Node* root,int k)
{
    queue<Node*> q;
    int count=1;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty() && count!=k)
    {
        Node* curr=q.front();
        if(curr==NULL)
        {
            q.push(NULL);
            count++;
        }else
        {
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }

            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }

        q.pop();
    }

    while(q.front()!=NULL)
    {
        cout<<q.front()->data<<" ";
        q.pop();
    }
    cout<<endl;
}

//TC:O(n);
void kth_level(Node* root,int k)
{
    if(root==NULL)
    {
        return;
    }

    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }

    kth_level(root->left,k-1);
    kth_level(root->right,k-1);
}

int main()
{
    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    int i=-1;
    Node* root=create(preorder,&i);
    cout<<endl;
    int k=3;

    //iterative approach
    print_kth_level(root,k);

    //recursive approach
    kth_level(root,k);
    cout<<endl;
    return 0;
}


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


//TC:O(n)
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

//TC:O(n)
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return max(height(root->left),height(root->right))+1;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int i=-1;
    Node* root=create(preorder,&i);
    cout<<endl;

    cout<<height(root)<<endl;
    return 0;
}
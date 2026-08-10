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
void preOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}


//TC:O(n)
void inOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inOrderTraversal(root->left);

    cout<<root->data<<" ";

    inOrderTraversal(root->right);

}

//TC:O(n)
void postOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}

static int levelCount=0;
//TC:O(n)
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* front=q.front();
        if(q.front()==NULL)
        {
            levelCount=levelCount+1;
            q.pop();
            cout<<endl;
            if(q.empty())
            {
                break;
            }
            q.push(NULL);
            continue;
        }
        cout<<front->data<<" ";
        if(front->left!=NULL)
        {
            q.push(front->left);
        }
        if(front->right!=NULL)
        {
            q.push(front->right);
        }

        q.pop();
    }

}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int i=-1;
    Node* root=create(preorder,&i);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<levelCount<<endl;
    return 0;
}
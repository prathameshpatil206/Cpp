#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right=NULL;
    Node* left=NULL;

    Node(int val)
    {
        this->data=val;
    }

};

Node* buildBST(Node* root,int val)
{
    if(root==NULL)
    {
        Node* newNode=new Node(val);
        return newNode;
    }

    if(val<root->data)
    {
        root->left=buildBST(root->left,val);
    }else{
        root->right=buildBST(root->right,val);
    }

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

bool search(Node* root,int val)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data==val)
    {
        return true;
    }

    if(val<root->data)
    {
        return search(root->left,val);
    }else{
        return search(root->right,val);
    }
}


Node* delNode(Node* root, int val)
{
    if(root==NULL)
    {
        cout<<"No such node found to delete."<<endl;
        return root;
    }

    if(root->data==val)
    {
        Node* lefty=root->left;
        Node* righty=root->right;

        delete root;

        if(lefty==NULL && righty==NULL)
        {
            return NULL;
        }else if(lefty==NULL)
        {
            return righty;
        }else if(righty==NULL)
        {
            return lefty;
        }else{
            root=righty;
            while(righty->left!=NULL)
            {
                righty=righty->left;
            }
            righty->left=lefty;
            return root;
        }
        
    }

    if(val<root->data)
    {
        root->left= delNode(root->left,val);
    }else
    {
        root->right= delNode(root->right,val);
    }

    return root;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root=NULL;
    for(int val:arr)
    {
        root=buildBST(root,val);
    }

    inorder(root);

    cout<<endl<<search(root,6);//TC:O(height) ~~ O(logn)

    root=delNode(root,5);

    cout<<endl;
    inorder(root);
    return 0;
}



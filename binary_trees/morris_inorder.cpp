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
//SC:O(1)
void morris_inorder(Node* root)
{
    Node* curr=root;

    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }else{

            Node* ip=curr->left;
            while(ip->right!=NULL && ip->right!=curr)
            {
                ip=ip->right;
            }


            if(ip->right==NULL)
            {
                ip->right=curr;
                curr=curr->left;
            }else{
                ip->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int i=-1;
    Node* root=create(preorder,&i);
    cout<<endl;

    morris_inorder(root);

    return 0;
}
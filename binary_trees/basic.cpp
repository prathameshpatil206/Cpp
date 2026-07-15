#include<bits/stdc++.h>
using namespace std;


class Node{
    public :
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

static int idx=-1;

Node* buildTree(vector<int> a)
{   
    idx++;

    if(a[idx]==-1)
        return NULL;
    
    Node* root=new Node(a[idx]);

    root->left=buildTree(a);
    root->right=buildTree(a);

    return root;
}

// pre order Traversal(root,left,right)  
void pretravel(Node* root)
{

    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<endl;
    pretravel(root->left);
    pretravel(root->right);

}

//Inorder Traversal(left,root,right)
void Intravel(Node* root)
{

    if(root==NULL)
    {
        return;
    }

    Intravel(root->left);
    cout<<root->data<<endl;
    Intravel(root->right);

}

//Postorder Traversal(left,right,root)
void Posttravel(Node* root)
{

    if(root==NULL)
    {
        return;
    }

    Posttravel(root->left);
    Posttravel(root->right);
    cout<<root->data<<endl;

}

//Level Order Traversal
void Leveltravel(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0)
    {
        Node* t=q.front();
        q.pop();
        if(t==NULL)
        {
            if(!q.empty())
            {
                cout<<"\n";
                q.push(NULL);
                continue;
            }else{
                break;
            }  
        }

         cout<<t->data<<" ";
        if(t->left!=NULL)
        {
            q.push((t->left));
        }
        if(t->right!=NULL)
        {
            q.push((t->right));
        }
        
    }
}


int main()
{
    vector<int> a={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=buildTree(a);//TC=O(n)

    pretravel(root);//TC=O(n)
    cout<<endl;
    Intravel(root);//TC=O(n)
    cout<<endl;
    Posttravel(root);//TC=O(n)
    cout<<endl;
    Leveltravel(root);
    return 0;
    
}
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

//TC:O(n * logn)
//SC:O(n)
void topView(Node* root)
{
    map<int,Node*> mappi;
    vector<int> ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp=q.front();
        if(temp.first->left!=NULL)
        {
            q.push({temp.first->left,temp.second-1});
        }

        if(temp.first->right!=NULL)
        {
            q.push({temp.first->right,temp.second+1});
        }
        
        if(mappi.find(temp.second)==mappi.end())
        {
            mappi[temp.second]=temp.first;
        }

        q.pop();
    }

    for(auto ele:mappi)
    {
        ans.push_back(ele.second->data);
    }

    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}


//TC:O(n * logn)
//SC:O(n)
void bottomView(Node* root)
{
    map<int,Node*> mappi;
    vector<int> ans;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int> temp=q.front();
        if(temp.first->left!=NULL)
        {
            q.push({temp.first->left,temp.second-1});
        }

        if(temp.first->right!=NULL)
        {
            q.push({temp.first->right,temp.second+1});
        }
        
        mappi[temp.second]=temp.first;


        q.pop();
    }

    for(auto ele:mappi)
    {
        ans.push_back(ele.second->data);
    }

    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}


int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int i=-1;
    Node* root=create(preorder,&i);
    cout<<endl;

    topView(root);
    bottomView(root);
    return 0;
}
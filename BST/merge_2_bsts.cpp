#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//TC:O(m+n)
class Solution {
  public:
  
    void inorder(Node * root,vector<int>& ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
    }

    Node* balancedBST(vector<int>& ans,int st, int end)
    {
        if(st>end)
        {
            return NULL;
        }

        int mid=st+(end-st)/2;

        Node* root=new Node(ans[mid]);

        root->left=balancedBST(ans,st,mid-1);

        root->right=balancedBST(ans,mid+1,end);

        return root;
    }

    Node* merge(Node *r1, Node *r2) {
        // code here
        vector<int> ans;
        
        inorder(r1,ans);
        inorder(r2,ans);
        sort(ans.begin(),ans.end());
        
        
        return balancedBST(ans,0,ans.size()-1);
        
    }
};
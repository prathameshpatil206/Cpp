#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


//TC:O(Height)
class Solution {
  public:
  
    Node* pre=NULL;
    Node* suc=NULL;
    void helper(Node* root, int key)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(key<root->data)
        {
            suc=root;
            helper(root->left,key);
        }
        
        if(key>root->data)
        {
            pre=root;
            helper(root->right,key);
        }
        
        if(key==root->data)
        {
            if(root->left!=NULL)
            {
                pre=root->left;
                while(pre->right!=NULL)
                {
                    pre=pre->right;
                }
            }
            
            if(root->right!=NULL)
            {
                suc=root->right;
                while(suc->left!=NULL)
                {
                    suc=suc->left;
                }
            }
        }
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        helper(root,key);
        return {pre,suc};
    }
};
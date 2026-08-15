#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//TC:O(n)
//SC:O(n)
//Use morris inorder traversal to make the SC constant.
class Solution {
public:
    TreeNode* a=NULL;
    TreeNode* b=NULL;
    bool second=false;
    TreeNode* prev=NULL;
    void helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }

        helper(root->left);
        if(prev!=NULL )
        {
            if(root->val<prev->val)
            {
                if(second)
                {
                    a=root;
                }else
                {
                    a=root;
                    b=prev;
                    second=true;
                }
            }
        }
        prev=root;
        helper(root->right);
    }

    void recoverTree(TreeNode* root) {

        helper(root);
        int temp=b->val;
        b->val=a->val;
        a->val=temp;
    }
};
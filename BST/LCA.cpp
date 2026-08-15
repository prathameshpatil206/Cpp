#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//TC:O(Height) ~~ O(logn)
class Solution {
public:
    TreeNode* LCA(TreeNode* root,int pval, int qval)
    {
        if(pval<=root->val && qval>=root->val)
        {
            return root;
        }

        if(pval<root->val)
        {
            return LCA(root->left,pval,qval);
        }else
        {
            return LCA(root->right,pval,qval);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(p->val<q->val)
        {
            return LCA(root,p->val,q->val);
        }else
        {
            return LCA(root,q->val,p->val);
        }
    }
};
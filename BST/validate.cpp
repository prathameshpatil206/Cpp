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
class Solution {
public:
    bool valid(TreeNode* root,TreeNode* min,TreeNode* max)
    {
        if(root==NULL)
        {
            return true;
        }

        if((min && root->val<=min->val) ||(max && root->val>=max->val))
        {
            return false;
        }

        bool lefty=valid(root->left,min,root);
        bool righty=valid(root->right,root,max);

        return lefty && righty;
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root,NULL, NULL);
    }
};
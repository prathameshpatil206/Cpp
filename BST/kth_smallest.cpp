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
    int kk;
    int val;
    void kthSmall(TreeNode* root){
        if(root==NULL|| kk<=0)
        {
            return;
        }


        kthSmall(root->left);
        if(kk==1)
        {
            val=root->val;
        }
        kk--;
        kthSmall(root->right);

    }

    int kthSmallest(TreeNode* root, int k) {
        kk=k;

        kthSmall(root);
        return val;
    }
};
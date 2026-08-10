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
    TreeNode* nextR=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
        {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=nextR;

        nextR=root;
    }
};
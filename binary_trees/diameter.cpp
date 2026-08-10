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
    int max_dia=0;
    int dia(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int lefty=dia(root->left);
        int righty=dia(root->right);

        max_dia=max(max_dia,lefty+righty);
        return max(lefty,righty)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return max_dia;
    }
};
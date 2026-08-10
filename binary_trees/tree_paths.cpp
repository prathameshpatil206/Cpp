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

    void binaryPaths(TreeNode* root,vector<string>& ans, string& s) {
        if(root==NULL)
        {
            return;
        }
        int old_size=s.size();
        s=s+to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(s);
            s.resize(old_size);
            return;
        }
        
        
        if(root->left!=NULL)
        {
            s=s+"->";
            binaryPaths(root->left,ans,s);
            s.pop_back();
            s.pop_back();
        }
        
        if(root->right!=NULL)
        {
            s=s+"->";
            binaryPaths(root->right,ans,s);
            s.pop_back();
            s.pop_back();
        }
        
        s.resize(old_size);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        binaryPaths(root,ans,s);
        return ans;
    }
};
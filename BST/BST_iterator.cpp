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
 

//SC:(height)
class BSTIterator {
public:
    stack<TreeNode*> s;

    void leftmost(TreeNode* root)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
    }


    BSTIterator(TreeNode* root) {
        leftmost(root);
    }
    
    //TC:O(1)
    int next() {
        TreeNode* curr=s.top();
        s.pop();
        leftmost(curr->right);
        return curr->val;
    }
    
    //TC:O(1)
    bool hasNext() {
        return !s.empty();
    }
};


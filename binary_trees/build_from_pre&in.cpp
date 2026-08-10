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


    int search(vector<int>& inorder,int val,int left, int right)
    {
        for(int k=left;k<=right;k++)
        {
            if(inorder[k]==val)
            {
                return k;
            }
        }

        return -1;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int& preIdx, int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }


        preIdx++;
        TreeNode* newNode=new TreeNode(preorder[preIdx]);

        int k=search(inorder,preorder[preIdx],left,right);

        newNode->left=build(preorder,inorder,preIdx,left,k-1);
        newNode->right=build(preorder,inorder,preIdx,k+1,right);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=-1;
        return build(preorder,inorder,preIdx,0,inorder.size()-1);
    }
};
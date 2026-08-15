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

class Solution {
public:
    int i=0;
    TreeNode* helper(vector<int>& preorder, TreeNode* min, TreeNode* max)
    {
        if(i==preorder.size()-1)
        {
            return NULL;
        }
        TreeNode* newNode=NULL;
        if(min==NULL && max==NULL)
        {
            newNode=new TreeNode(preorder[i]);
        }else
        {
            if((min==NULL || preorder[i+1]>min->val) && (max==NULL || preorder[i+1]<max->val))
            {
                i++;
                newNode=new TreeNode(preorder[i]);
            }else
            {
                return NULL;
            }
        }
        


        newNode->left=helper(preorder,min,newNode);

        newNode->right=helper(preorder,newNode,max);

        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==1)
        {
            return new TreeNode(preorder[0]);
        }
        return helper(preorder,NULL,NULL);
    }
};
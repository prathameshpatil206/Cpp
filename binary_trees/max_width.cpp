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
    int widthOfBinaryTree(TreeNode* root){
        int max_=0;
        queue<pair<TreeNode*,int>> q;
        long long i = 0;
        long long l, r;
        q.push({root,0});
        q.push({NULL,-1});
        
        l=0;
        while(!q.empty())
        {
            pair<TreeNode*,int> curr=q.front();

            if(curr.first==NULL)
            {
                int dia=r-l+1;
                max_=max(max_,dia);   
                q.pop();
                if(!q.empty())
                {
                    q.push({NULL,-1});
                    l=q.front().second;
                }
                
                continue;

            }else{
                i=curr.second;
                if(curr.first->left!=NULL)
                {
                    q.push({curr.first->left,2*i+1});
                }

                if(curr.first->right!=NULL)
                {
                    q.push({curr.first->right,2*i+2});
                }
            }
            
            r=curr.second;
            q.pop();

        }

        return max_;

    }
};
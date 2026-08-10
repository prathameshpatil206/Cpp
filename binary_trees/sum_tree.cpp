#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//TC:O(n)
class Solution {
  public:
    int toSumTree(Node *root) {
        // code here
        if(root==NULL)
        {
            return 0;
        }

        int left_sum=toSumTree(root->left);
        int right_sum=toSumTree(root->right);
        
        root->data+=left_sum+right_sum;
        return root->data;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

struct Info {
    Node* bst;
    int size;
    Node* min;
    Node* max;
};


//TC:O(n)
class Solution {
public:

    Info largeBST(Node* root) {

        // leaf node
        if(root->left == NULL && root->right == NULL)
        {
            return {root, 1, root, root};
        }

        Info lefty = {NULL, 0, NULL, NULL};
        Info righty = {NULL, 0, NULL, NULL};

        if(root->left)
        {
            lefty = largeBST(root->left);
        }

        if(root->right)
        {
            righty = largeBST(root->right);
        }

        // Check whether current subtree is a BST
        if(
            (lefty.bst == NULL ||
             (lefty.bst == root->left &&
              lefty.max->data < root->data))
            &&
            (righty.bst == NULL ||
             (righty.bst == root->right &&
              righty.min->data > root->data))
        )
        {
            Node* minimum;
            Node* maximum;

            if(lefty.min != NULL)
                minimum = lefty.min;
            else
                minimum = root;

            if(righty.max != NULL)
                maximum = righty.max;
            else
                maximum = root;

            return {
                root,
                lefty.size + righty.size + 1,
                minimum,
                maximum
            };
        }
        else
        {
            // Current subtree isn't a BST.
            // Return the larger BST found below it.
            if(lefty.size > righty.size)
            {
                return lefty;
            }
            else
            {
                return righty;
            }
        }
    }

    int largestBst(Node* root) {

        if(root == NULL)
            return 0;

        Info p = largeBST(root);

        return p.size;
    }
};
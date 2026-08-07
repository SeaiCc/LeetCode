#include <stdio.h>
#include <iostream>

using namespace std;


// Definition for a binary tree node.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isInverse(root->left, root->right);
    }

    bool isInverse(TreeNode* left, TreeNode * right){
        if(!left && !right) return true;
        if(!left || !right) return false;

        if(left->val != right->val) return false;
        return isInverse(left->left, right->right) && isInverse(left->right, right->left);
    }
};

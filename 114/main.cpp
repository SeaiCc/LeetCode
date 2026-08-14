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
    void flatten(TreeNode* root) {
        // helper(root);
        // 2. 前驱节点 空间O(n)
        if(!root) return;

        while(root) {
            // cout << root->val << endl;
            // 找有左子树的节点
            while(!root->left && root->right) {
                root = root->right;
            }
            TreeNode* lNode = root->left;
            TreeNode* preNode = root->left;
            
            if(!preNode) return;
            while(preNode->right) {
                preNode = preNode->right;
            }

            preNode->right = root->right;
            root->left = nullptr;
            root->right = lNode;
            root = lNode;
        }
    }

    // 1. 递归
    TreeNode* helper(TreeNode* root) {
        if(!root) return nullptr;

        // 展平 后多个节点
        TreeNode* oldRight = root->right;
        root->right = helper(root->left);
        while(root->right) {
            root = root->right;
        }
        root->right = helper(oldRight);

    }
};
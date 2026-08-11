#include <stdio.h>
#include <iostream>
#include <climits>

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
private:
    long long curVal = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        // 1. 中序遍历 检查数组是否顺序
        // 2. 检查左子节点时，传入当前节点值，flag标志为左节点，
        // 左节点 检查右节点值是否介于 父节点与爷爷节点之间
        if (!root) return true;
        if(!isValidBST(root->left)) return false;
        if(root->val <= curVal) return false;
        curVal = root->val;
        return isValidBST(root->right);
    }
};
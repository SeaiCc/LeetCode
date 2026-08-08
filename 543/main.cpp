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
private:
    int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //可能不经过根节点 root
        // 左右 最大深度 - 1 之和
        // 左右子树中 最大直径
        if(!root) return 0;
        calcDiameter(root);
        return this->maxDiameter;
    }

    int calcDiameter(TreeNode* root) {
        if (!root) return 0;

        int leftDepth  = calcDiameter(root->left);
        int rightDepth = calcDiameter(root->right);
        // 更新maxDiameter
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        return max(rightDepth, leftDepth) + 1;
    }
};
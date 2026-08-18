#include <stdio.h>
#include <iostream>
#include <unordered_map>

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
    int maxPath;
public:
    int maxPathSum(TreeNode* root) {
        // 最大路径和 
        // 1. 每个节点计算经过该节点的最大路径，取最大值 节点数目范围 [1, 3 * 104]
        // 2. 递归 leftMax rightMax root ，left+ root， right+root， left+right+root
        // 获取到的left可能不经过 root->left 无法直接相加
        // 还要考虑同时经过两个左右孩子的情况
        // 对于一个节点 有三条路径 父 左 右，
        // 引入最大贡献值， 以及0 截断
        maxPath = root->val;
        helper(root); 
        return maxPath;
    }

    int helper(TreeNode* root) {
        if(!root) return 0;
        int l = max(helper(root->left), 0);
        int r = max(helper(root->right), 0);
        int res = root->val;
        // 更新maxPath，root节点 及其左右子树的最大path
        maxPath = max(maxPath, res + l + r);
        // 传给上一层的最多只能包含一条子树
        // 使用最大子贡献概念，无需进行复杂的值判断
        return res + max(l, r);
    }
};
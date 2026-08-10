#include <stdio.h>
#include <iostream>
#include <vector>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 定位中间节点
        return getMidNode(0, nums.size() - 1, nums);
    }

    TreeNode* getMidNode(int left, int right, vector<int>& nums) {
        if(left > right) return nullptr;
        // 获取中间节点 
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = getMidNode(left, mid - 1, nums);
        node->right = getMidNode(mid+1, right, nums);

        return node;
    }
};
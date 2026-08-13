#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
        // 1. 按层遍历，找每层最右侧节点
        if(!root) return vector<int>();

        vector<int> ans;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()) {
            int sz = q.size();
            TreeNode* node;
            for(int i = 0; i < sz; i++) {
                node = q.front();
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
                q.pop();
            }
            ans.push_back(node->val);
        }

        return ans;
    }
};
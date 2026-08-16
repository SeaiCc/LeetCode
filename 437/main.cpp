#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
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
    // int num = 0;
    unordered_map<long long, int> prefix;
public:
    int pathSum(TreeNode* root, int targetSum) {
        // 路径方向必须是向下的（只能从父节点到子节点）
        // 统计高度，到叶子节点计算这条路径上多少满足的路径
        // 不需要从根节点开始，也不需要在叶子节点结束
        // 最坏情况要从每个节点开始向下找
        // 没有起终点信息如何复用累加和
        // 1. 传递一个列表，维护了从根节点到该节点 的 target - sum， 判断该节点是否为
        // 2. 使用前缀和，不需要遍历更新值

        // vector<int> paths;
        // paths.push_back(targetSum - root->val);
        // return num;
        prefix[0] = 1; // curr == targetSum时 应+1
        return getPath(root, 0 , targetSum);

    }

    int getPath(TreeNode* root, long long curr, int targetSum) {
        if(!root) return;

        int ret = 0;
        curr += root->val;
        // 在前缀和中检索满足条件的
        if(prefix.count(curr - targetSum)){
            ret = prefix[curr-targetSum];
        }

        prefix[curr]++;
        ret += getPath(root->left, curr, targetSum);
        ret += getPath(root->right, curr, targetSum);
        prefix[curr]--; // 恢复，父节点不应考虑子节点

        return ret;
    }

    // void getPath(TreeNode* root, vector<int>& paths, int targetSum) {
    //     if(!root) return;
    //     for(int i = 0; i < paths.size(); i++) {
    //         if(paths[i] == root->val) num++;
    //         paths[i] -= root->val;
    //     }
    //     paths.push_back(targetSum - root->val);
    //     getPath(root->left, paths, targetSum);
    //     getPath(root->right, paths, targetSum);
    //     paths.pop_back();
    //     for(int i = 0; i < paths.size(); i++) {
    //         paths[i] += root->val;
    //     }
    // }
};
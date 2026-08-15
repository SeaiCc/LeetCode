#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

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
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 1. preorder 和 inorder 均 无重复 元素
        // 从 preorder 取节点， 在 inroder 中查找位置i, 分割出左右子树
        // 2. 哈希表维护 节点值与坐标

        int sz = preorder.size();
        // for(int i = 0 ; i < sz; i++) {
        //     index[inorder[i]] = i;
        // }
        // return helper(preorder, 0, inorder, 0, sz - 1);

        // 3. 迭代 以 inorder为基准，操作 preorder
        if (sz == 0) return nullptr;

        stack<TreeNode* > stack;
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push(root);
        int inorderIdx = 0;
        for(int i = 1; i < sz; i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            // 判断inorder[inorderIdx]
            if(stack.top()->val != inorder[inorderIdx]) {
                stack.top()->left = node;
                stack.push(node);
            }else {
                // 遍历 preorder 到最左节点， 下一个节点是stack中某个节点的右节点
                // 循环 pop 出stack， 并增加 inroderIdx 直到不一致 则 找到下一个节点的右节点
                TreeNode* temp;
                // 会把 下一个节点的父节点也排除stack
                while(!stack.empty() && stack.top()->val == inorder[inorderIdx]) {
                    temp = stack.top();
                    stack.pop();
                    ++inorderIdx;
                }
                // 找到之后
                temp->right = node;
                stack.push(node);
            }
        }

        return root;
    }


    TreeNode* helper(vector<int>& preorder, int i, vector<int>& inorder, int l, int r ) {
        TreeNode* node = new TreeNode(preorder[i]);
        if(l == r) return node;
        // 找val 在 inorder 位置
        // auto it = find(inorder.begin(), inorder.end(), preorder[i]);
        // int idx = distance(inorder.begin(), it);
        int idx = index[preorder[i]];
        if(idx > l) {
            // 根据 左子树的根 preorder[i] 在 （l,idx-1） 范围构建左子树
            node->left = helper(preorder, i + 1, inorder, l , idx - 1);
        }
        if(idx < r) {
            // 该节点右侧 能构建出一颗右子树
            node->right = helper(preorder, i + (idx - l) + 1, inorder, idx + 1, r);
        }
        return node;
    }
};

int main(int argc, char* argv[]) {
    Solution solu;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    solu.buildTree(preorder, inorder);
}
#include <stdio.h>
#include <iostream>
#include <stack>
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

class MyBst{
public:
    MyBst(TreeNode* root){
        this->root = root;
        this->countNum(root);
    }

    int kthSmallest(int k) {
        // 判断root节点
        root = this->root;
        while(root){
            int lNum = getNum(root->left);
            // cout << root->val << "\t" << lNum <<endl;
            if(lNum >= k){
                // k在左子树
                root = root->left;
            }else if(lNum == k - 1) {
                return root->val;
            }else{
                // 右子树查找
                // 更新k
                k -= (lNum + 1);
                root = root->right;
            }
        }
        return -1;
    }

private:
    TreeNode* root;
    unordered_map<TreeNode*, int> map;

    int countNum(TreeNode* root) {
        if(!root) return 0;
        map[root] = 1 + countNum(root->left) + countNum(root->right);
        // cout << root->val << "\t" << map[root] << endl;
        return map[root];
    }

    int getNum(TreeNode* root) {
        if(root && map[root] > 0) {
            return map[root];
        }else{
            return 0;
        }
    }
};
class Solution {
private:
    int k_num;
public:
    int kthSmallest(TreeNode* root, int k) {
        // 1. 二叉搜索树 k 作为参数，k--，为零时返回
        // 叶子节点边界条件 返回？

        // findKSmallest(root, k);
        // return this->k_num;

        // 2. 迭代
        // stack<TreeNode*> stack;

        // while(root || stack.size() > 0) {
        //     // 左子树最底层节点
        //     while(root->left) {
        //         stack.push(root);
        //         root = root->left;
        //     }
        //     k--;
        //     if(k == 0) return root->val;
        //     stack.pop();

        //     // root 及其左子树全部遍历完成，开始右子树节点
        //     root = root->right;
        // }
        // return -1;

        // 3. 维护子树节点数目
        MyBst myBst(root);
        return myBst.kthSmallest(k);
    }

    void findKSmallest(TreeNode* root, int& k) {
        if (!root) return;
        findKSmallest(root->left, k);
        // cout << root->val << "\t" << k <<endl;
        if(k < 1) return;
        k--;
        if(k == 0) {
            this->k_num = root->val;
            return;
        }
        
        findKSmallest(root->right, k);
    }
};
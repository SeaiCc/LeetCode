#include <stdio.h>
#include <iostream>
#include <vector>

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
// private:
//     vector<int> res;
//     // 1. 成员 2. 传参数
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 1.
        // if (!root) return {};
        // inorderTraversal(root->left);
        // res.push_back(root->val);
        // inorderTraversal(root->right);

        // return this->res;


        // 2. res参数传递
        // vector<int> res;
        // inorder(root, res);
        // return res;

        // 3. Morris
        vector<int> res;
        TreeNode* predecessor;
        while(root) {
            // x 无左孩子
            if(root->left == nullptr) {
                res.push_back(root->val);
                root = root->right;
            }else{
                // 如果之前遍历过 则会指向 中序的下个节点
                predecessor = root->left;
                while(predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                if(predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                }else{
                    res.push_back(root->val);
                    // 事件顺序： 
                    // prodecessor第一次被访问 右节点指向root
                    // prodecessor入队列 -》 访问right -〉 root
                    // 再次访问root 发现prodecessor 有右节点 左侧已经访问完毕
                    // root左子树遍历完成 ，恢复prodecessor
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
        }
        return res;

    }

    // void inorder(TreeNode* root, vector<int>& res){
    //     if (!root) return;
    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }
};
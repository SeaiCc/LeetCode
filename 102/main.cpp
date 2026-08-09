#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // 1. 队列 队头出 本层 队尾进下一层 维护 层之间的分隔点
        // 2. 维护两个vector 区分层 需要维护 当前层状态 
        if (!root) return ans;

        // 方法一；
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            
            for(int i = 0; i < sz; i++) {
                temp.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            ans.push_back(temp);
        }
        return ans;

        // 方法二
        // vector<TreeNode*> layer1, layer2;
        // layer1.push_back(root);
        // bool curLayer1 = true;
        // ans.push_back(vector<int>{root->val});
        // while(!layer1.empty() || !layer2.empty()){
        //     // 当前层为layer1，layer1 内容加入tmp 子节点加入 layer2
        //     vector<int> tmp;
        //     if(curLayer1){
        //         for(auto node: layer1) {
        //             if(node->left != nullptr)
        //             layer2.push_back(node->left);
        //             if(node->right != nullptr) 
        //             layer2.push_back(node->right);
        //             tmp.push_back(node->val);
        //         }
        //         layer1.clear();
        //     }else {
        //         for(auto node: layer2) {
        //             if(node->left != nullptr)
        //             layer1.push_back(node->left);
        //             if(node->right != nullptr) 
        //             layer1.push_back(node->right);
        //             tmp.push_back(node->val);
        //         }
        //         layer2.clear();
        //     }
        //     curLayer1 != curLayer1;
        // }
        // return ans;


    }
};

int main(int argc, char* argv[]) {
    Solution* solu = new Solution();

}

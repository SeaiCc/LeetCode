#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, string> prefix;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果找到某个节点 不需要继续向下遍历， 就算另外一个节点在此节点下
        // 全程(left && right)都不成立，此节点就是要找的节点一路向上返回
        if(!root || root == p || root == q ) return root;
        
        // 分别从左子节点找 p q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 都找到
        if(left && right) return root;

        // 返回找到的那个节点 或者 null
        return left ? left : right;
    }

};

int main(int argc, char* argv[]){
    Solution solu;
    vector<int> treeList = {37,-34,-48,-1,-100,-101,48,-1,-1,-1,-1,-54,-1,-71,-22,-1,-1,-1,8};
    // build tree
    TreeNode* root = new TreeNode(37);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(i < treeList.size()) {
        TreeNode* cur = que.front();
        if(treeList[i] != -1) {
            cur->left = new TreeNode(treeList[i]);
            que.push(cur->left);
        }
        if(treeList[i+1] != -1) {
            cur->right = new TreeNode(treeList[i+1]);
            que.push(cur->right);
        }
        que.pop();
        i+=2;
    }
    TreeNode* p = root->right->right->left->left;
    TreeNode* q = root->right->right;
    solu.lowestCommonAncestor(root, p, q);
}
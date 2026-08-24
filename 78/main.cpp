#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      // 1. 回溯法 解集 不能 包含重复的子集 不能采用 全排列中的 优化方法 
      vector<vector<int>> res;
      vector<int> cur;
      helper(res, cur, nums, 0);
      return res;
      // 2. 全局 res cur 能缩减运行时间
    }

    void helper(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int pos) {
      res.emplace_back(cur);

      // 从pos向后逐个元素加入 回溯 
      for(int i = pos; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        helper(res, cur, nums, i+1);
        cur.pop_back();
      }
    }
};


int main() {
  Solution solu;
  vector<int> nums = {1, 2, 3};
  solu.subsets(nums);
}


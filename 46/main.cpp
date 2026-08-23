#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<int, int> isUsed;
  vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
      // 不含重复数字, 直接枚举嵌套循环次数太多
      // 1.分治 先顺序加入一个结果，然后考虑交换 整段交换，单个元素交换
      // 2. 1 - n 的全排列
      // 3. whlie + stack 一个个取低效
      // 4. 交换
      // 5. 回溯
      // 所有整数 互不相同 1 <= nums.length <= 6
      // 排列数总共A_n_n 所有数都出现了 这些次数，且之前已经加进去的不能出现，且不能和结果中的顺序一样
      // n 在一个位置 只能出现An-1次
      // 1: 1 2: 2 3:6 4: 24 5: 70 6:420
      // int n = nums.size();
      // for(int i = 0; i < n; i++) isUsed[nums[i]] = 0;
      // vector<int> cur;
      // helper(0, cur, nums);
      // return res;
      // 6. 通过数组交换实现回溯
      vector<vector<int>> res;
      helper(0, res, nums);
      return res;
    }

    void helper(int pos, vector<vector<int>>& res, vector<int>& nums) {
      if(pos == nums.size()) {
        res.emplace_back(nums);
        return;
      }

      for(int i = pos; i < nums.size(); i++) {
        // current loop alaway push to lenght pos
        swap(nums[pos], nums[i]);
        helper(pos+1, res, nums);
        swap(nums[pos], nums[i]);
      }
    }

    // void helper(int length, vector<int> cur,  vector<int>& nums) {
    //   if(length == nums.size()) {
    //     res.push_back(cur);
    //     return;
    //   }
    //
    //   // 向下一个位置加入元素，元素从 isUsed 中找
    //   for(int i = 0; i < nums.size(); i++) {
    //     if(isUsed[nums[i]] == 1) continue;
    //     isUsed[nums[i]] = 1;
    //     cur.push_back(nums[i]);
    //     helper(length+1, cur, nums);
    //     cur.pop_back();
    //     isUsed[nums[i]] = 0;
    //   }
    // }
};


int main() {
  Solution solu;
  vector<int> nums = {1, 2, 3};
  solu.permute(nums);
}

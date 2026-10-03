#include <cstdio>
#include <iostream>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      return nums[nums.size()/2];
      // 1. hash
      // 2. 排序 取下标为n/2的数
      // 3. 随机 rand() % nums.size() 验证
      // 4. 分治 递归
      // 5. Boyer-Moore 投票算法
    }
};

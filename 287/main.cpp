#include <cstdio>
#include <iostream>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      // 1. 利用下标
      // 不修改数组
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        if (nums[nums[i]] == nums[i]) return nums[i];
      }
    }
};

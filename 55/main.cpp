#include <cstdio>
#include <iostream>

class Solution {
public:
    bool canJump(vector<int>& nums) {
      // 1. 从前往后，能到达标注
      // 跳跃的 最大 长度
      int n = nums.size();
      int maxIdx = 0;
      for (int i = 0;i < n; i++) {
        if (maxIdx >= i) 
          maxIdx = max(maxIdx, nums[0] + i);
      }
      return maxIdx >= n - 1;
    }
};

#include <cstdio>
#include <iostream>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      // 线性时间复杂度, 不能排序
      // 常量额外空间
      // 找出元素 非下标
      // 1. 异或
      int res = 0;
      for (int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
      }
      return res;
    }
};

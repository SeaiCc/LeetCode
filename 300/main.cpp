#include <cstdio>
#include <iostream>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      // 1. dp
      // f[n] = f[i] + 1 // i小于n的最大值
      // 需要维护 当前最大长度的递增序列
      int n = nums.size();
      vector<int> dp(n, 1);
      int maxL = 1;
      for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
          if (nums[j] < nums[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
            maxL = max(dp[i], maxL);
          }
        }
      }
      return maxL;
      // 2. 每次都执行插入，最后可能不按原先顺序，但是长度正确
    }
};

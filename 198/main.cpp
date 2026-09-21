#include <cstdio>
#include <iostream>

class Solution {
public:
    int rob(vector<int>& nums) {
      // 1. dp 
      // money(n + 1) = 
      // = max(偷n ， 不偷n 偷 n - 1)
      int n = nums.size();
      vector<int> money(n+1);
      money[0] = 0; 
      money[1] = nums[0];
      for (int i = 2; i < n+1; i++) {
        money[i] = max(money[i - 1], money[i - 2] + nums[i-1]);
      }
      return money[n];
    }
};

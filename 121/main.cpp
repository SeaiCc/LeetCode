#include <cstdio>
#include <iostream>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // 1. 动态规划， 维护最小值
      int n =  prices.size();
      int minVal = prices[0];
      int res = INT_MIN;
      for (int i = 0; i < n; i++) {
        minVal = min(minVal, prices[i]);
        res = max(res, prices[i] - minVal);
      }
      return res;
    }
};

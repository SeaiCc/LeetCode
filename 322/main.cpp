#include <cstdio>
#include <iostream>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      // 类似完全平方数
      // 1. f[i] =  1 + f[i - coins[j]]
      // vector<int> dp(amount+1);
      // dp[0] = 0;
      // for (int i = 1; i <= amount; i++) {
      //   int minNum = INT_MAX;
      //   for (int j = 0; j < coins.size(); j++) {
      //     if (coins[j] > i || dp[i - coins[j]] == -1) continue;
      //     minNum = min(minNum, dp[i - coins[j]]);
      //   }
      //   if (minNum == INT_MAX) 
      //     dp[i] = - 1;
      //   else
      //     dp[i] = minNum + 1;
      // }
      // return dp[amount];
      // 使用初始化 amount+1 ， 循环直接更新 
      
      vector<int> dp(amount+1, amount+1);
      dp[0] = 0;
      for (int i = 0; i <= amount; i++) {
        for (int j = 0; j < coins.size();j++) {
          if (coins[j] <= i) {
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
          }
        }
      }
      return dp[amount] > amount ? -1 : dp[amount];
      // 2. 记忆化搜索
    }
};

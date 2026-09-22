#include <cstdio>
#include <iostream>

class Solution {
public:
    int numSquares(int n) {
      // 1. 找小于 sqrt(n) 最大整数，更新n  x 结果错误
      int res = 0;
      // while (n != 0) {
      //   // 向下取整
      //   int tmp = (int) sqrt(n);
      //   res++;
      //   n -= tmp * tmp;
      // }
      // return res;
      // 2. 从 (1 - sqrt(n)) 每次可以选择也可以不选择, 也可以重复选择
      // 从后往前
      // int end = (int) sqrt(n);
      // for (int i = end; i > 0; i--) {
      //
      // }
      // 3. dp 从1 开始 到n
      // n <= 10^4
      // dp[i] 为 和为n的最小完全平方数
      // dp[i] =max( dp[i-1] + 1 , dp[i-2]
      // n = 12 dp[1] = 1 dp[2] = 2 dp[3] = 3 
      // dp[4] = 1, dp[5] = dp[4] + dp[1] or dp[2] + dp[3]
      // 需要考虑 1 ～ n/2 所有情况？
      // 12 = 1 + 11 = 2 + 10 = 3 + 9 = 4 + 8 = 5+7 = 6+6
      // 只需考虑 1 +  4 +   3+9 需要考虑吗？ 
      // 11 = 1 + 10 = 4+7 
      // 完全平方数的dp均为 1 
      // dp[12] = dp[4] + dp[8] = dp[4] + (dp[4] + dp[4])
      // dp[12] = dp[9] + dp[3] = 1 + 3
      // dp[13] = dp[9] + dp[4] = 1+1 
      vector<int> dp(n+1, n);
      dp[0] = 0;
      for (int i = 0; i <= sqrt(n); i++) {
        dp[i*i] = 1;
      }
      dp[1] = 1;
      for (int i = 2; i <= n; i++) {
        // i 划分为两部分
        // for (int j = 1; j <= i/2; j++) {
        //   if (dp[j] != 1) continue;
        //   dp[i] = min(dp[i], dp[j] + dp[i-j]);
        // }
        // 枚举j^2 不用全部判断 dp[j] !=1 
        for (int j = 1; j *j <= i; j++) {
          dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
      }
      return dp[n];
      // 4.数学 答案限定在 1-4
      // 判断是否平方数  1 
      // 判断是否满足 4^k*(8m+7) 取余判断
      // 答案为2 时 枚举 1 - sqrt(n) 中所有的j  判断 n - j*j 判断是否平方数
      // 剩余情况为3
    }

};

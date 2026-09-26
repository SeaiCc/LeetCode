#include <cstdio>
#include <iostream>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      // 非空： 至少有一个元素
      // 连续：n 需要考虑 n-1位置状态
      // 需要返回乘积
      // -10 <= nums[i] <= 10, 有负数情况，考虑 维护绝对值？
      // -1 -2 111111  -3 -4
      // -3 需要 考虑从-2 开始 -4 需要考虑从-1 开始 ，如果前面还有 -号 
      // 先不考虑0 最终结果是从 nums0 或者 第一个负数之后的值开始计算 
      // 遇到零之后从后面重新找 第一负数
      // 当前位置的最优解未必是由前一个位置的最优解转移得到的
      // 1.dp
      int n =  nums.size();
      // vector<int> dp(n, 1);
      // int res = nums[0];
      // dp[0] = nums[0];
      // int pre = 1;
      // int curMul = 1;
      // for (int i = 0; i < n; i++) {
      //   if (nums[i] == 0) {
      //     // 重置
      //     pre = 1;
      //     curMul = 1;
      //     continue;
      //   }
      //   if (pre > 0) {
      //     pre *= nums[i];
      //     if (nums[i] <= 0)
      //       dp[i] = nums[i];
      //     else
      //       dp[i] = pre;
      //   }else if (pre < 0) {
      //       dp[i] = curMul * nums[i];
      //       if (dp[i] < 0) 
      //         dp[i] *= pre;
      //   } else {
      //     cout << "error" <<endl;
      //   }
      //   res = max(res, dp[i]);
      // }
      // return res;
      // 2. 维护一个最大值维护一个最小值
      int maxF = nums[0], minF = nums[0], res =nums[0];
      for (int i = 1; i < n; i++) {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max( nums[i], mn * nums[i]));
        minF = min(mx * nums[i], min( nums[i], mn * nums[i]));

        res = max(res, maxF);
      }
      return res;
    }
};

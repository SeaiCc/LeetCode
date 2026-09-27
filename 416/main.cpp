#include <cstdio>
#include <iostream>

class Solution {
public:
    // bool canPartition(vector<int>& nums) {
    //   // 可以有重复元素
    //   // 1. 求和， 如果能分，有一个合为 1/ 2的子集 
    //   // 2. 最小差值
    //   // 1 2 4
    //   // i 位置值 = i-1 和 < num[i]   nums[i] - sum[i-1]
    //   // sum[i-1] > nums[i] 
    //   // sort(vector.begin(), vector.end());
    //   int n = nums.size();
    //   int sum = 0;
    //   for (int i = 0; i < n; i++) {
    //     sum += nums[i];
    //   }
    //   if (sum % 2 != 0) return false;
    //   return helper(nums, 0, sum / 2);
    // }
    //
    // bool helper(vector<int>& nums, int begin, int sum) {
    //   if (begin >= nums.size()) return false;
    //   if (nums[begin] == sum) return true;
    //   return helper(nums, begin + 1, sum - nums[begin])
    //       || helper(nums, begin + 1, sum);
    // }
    // 2. dp
    // 求和 判断奇偶
    // dp[i][j] 前 i 个元素 是否有和为 j 的组合
    // dp[i][0] 不选就可以 使得 j == 0 全为true
    // dp[0][nums[0]] = true 其余 d[0][j] = false
    // dp[i][j] 先判断 nums[i] 和 j 关系 
    // nums[i] > j 不能选,结果为 dp[i-1][j]
    // nums[i] <= j, 选或者不选 dp[i-1][j -nums[i]] || dp[i-1][j]
    bool canPartition(vector<int>& nums) {
      int n = nums.size();

      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += nums[i];
      }
      if (sum % 2 != 0) return false;
      int target = sum / 2;
      vector<bool> dp(target+1, false);
      dp[0] = true;
      for (int i = 0; i < n; i++) {
        for (int j = target; j >= nums[i]; j--) {
          dp[j] = dp[j] || dp[j - nums[i]];
        }
      }
      return dp[target];
    }
};

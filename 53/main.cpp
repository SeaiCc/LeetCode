#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int len = nums.size();
      if (len <= 0) {
        return -1;
      }

      int res = nums[0];

      // 固定右边界，左侧边界会变化？？
      // 必须连续，所以要考虑前一个位置的值
      // dp[i]: 以i 为结尾的最大值
      // dp[i - 1] <= 0  dp[i]
      // dp[i - 1] > 0 dp[i  - 1] +nums[i ]
      vector<int> dp(len + 1);
      dp[0] =  0;
      for (int i = 1; i < len + 1; i++) {
        if (dp[i-1] <= 0) {
          dp[i] = nums[i - 1];
        }else{
          dp[i] = dp[i-1] + nums[i-1];
        }
        res = max(dp[i], res);
      }

      return res;

    }
    // 线段树
    // lSum 表示 [l,r] 内以 l 为左端点的最大子段和
    // rSum 表示 [l,r] 内以 r 为右端点的最大子段和
    // mSum 表示 [l,r] 内的最大子段和
    // iSum 表示 [l,r] 的区间和
    //
};


int main(int argc, char *argv[]) {
  vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  Solution solu;
  int res = solu.maxSubArray(nums);
  cout << res << endl;
}

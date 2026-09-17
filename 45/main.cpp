#include <cstdio>
#include <iostream>

class Solution {
public:
    int jump(vector<int>& nums) {
      // 维护 到末尾最小步数的数组
      int n = nums.size();
      // vector<int> step(n, n+1);
      // step[n-1] = 0;
      // for (int i = n - 2; i >= 0; i--) {
      //   //  从 i 能达到的范围内找出最小值
      //   int minStep = n;
      //   for (int j = i; j <= i + nums[i] && j < n; j++) {
      //     minStep = min(minStep, 1 + nums[j]);
      //   }
      //   step[i] = minStep;
      // }
      // return step[0];
      // 2.择距离最后一个位置最远的那个位置，也就是对应下标最小的那个位置
      // 从前向后找能到 position的位置，即为最小，然后更新position
      // 3.从前向后找能跳跃到的最大位置
      // 只有当 i == end 时才更新step
      int maxPos = 0, step = 0, pos = 0;
      for (int i = 0; i < n-1; i++) {
          // if (maxPos < i) continue; // 这句有意义吗？
          maxPos = max(maxPos, i + nums[i]);
          if (i == end) {
            end = maxPos;
            ++step;
          }
      }
      return step;
      
    }
};

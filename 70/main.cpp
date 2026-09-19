#include <cstdio>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
      // 1. 从后向前 
      if (n == 1) return 1;
      vector<int>step(n+1, 0);
      step[n] = 1;
      step[n-1] = 1;
      for (int i = n - 2; i > 0; i--) {
        step[i] = step[i+1] + step[i+2];
      }
      return step[1];
      // 2. 关系变为 f(x)=f(x−1)+f(x−2)
      // 快速幂 a^13，13 的二进制是 1101，即 13 = 8 + 4 + 0 + 1
    }
};

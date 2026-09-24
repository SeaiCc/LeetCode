#include <cstdio>
#include <iostream>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      // 1. dp 是否可以复用, 之前的结果
      int m = wordDict.size();
      int n = s.length();

      vector<bool> dp(n+1, false);
      dp[0] = true;
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
          // word 4  i = 4
          int wordL = wordDict[j].length();
          if (wordL > i) continue;
          if (dp[i - wordL] == false) continue;
          cout  << i - wordL << " " << wordL <<endl;
          if (s.compare(i - wordL, wordL, wordDict[j]) == 0)
          {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[n];
    }
};

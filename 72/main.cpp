#include <cstdio>
#include <iostream>

class Solution {
public:
    int minDistance(string word1, string word2) {
      // 1.dp[i][j] word[0:i] 变成word2[0:j] 所需步骤
      // int letter[26] = {};
      // for (char ch : word2) {
      //   letter[ch - 'a']++;
      // }
      int m = word1.length();
      int n = word2.length();
      vector<vector<int>> dp(m+1, vector<int>(n+1));

      for (int j = 0; j <= n; j++) {
        // 从 “” 变成 word2 所需步骤
        dp[0][j] = j;
      }
      for (int i = 0; i <= m; i++) {
        // 从s[0:i)变成 “”需要的操作
        dp[i][0] = i;
      }

      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (word1[i-1] ==  word2[j-1]) {
            dp[i][j] = dp[i-1][j-1];
          }else {
            // 从 dp[i-1][j] -> dp[i][j] 多了一个字符 ，增加一次移除操作
            // 从 dp[i][j-1] -> dp[i][j] 少了一个word2的字符，增加一次新增操作 
            // 从 dp[i-1][j-1] -> dp[i][j] 增加啊一次变换操作 
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
          }
        }
      }
      return dp[m][n];
    }
};

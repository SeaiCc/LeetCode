#include <cstdio>
#include <iostream>
#include <vector>

class Solution {
public:
    string longestPalindrome(string s) {
      // 1. dp[i][j] 从i开始到j结束的字字符串为回文
      int n = s.length();
      if (n == 0) return "";
      // int left = 0; 
      // int maxL = 1;
      // vector<vector<bool>> dp(n, vector<bool>(n, false));
      // for (int i = 0; i < n - 1; i++) {
      //   dp[i][i] = true;
      //   if (s[i] == s[i+1]) {
      //     dp[i][i+1] = true;
      //     left = i;
      //     maxL = 2;
      //   }
      // }
      // dp[n-1][n-1] = true;
      //
      // for (int i = n-1; i>=0; i--) {
      //   for(int j = i+2; j<n; j++) {
      //     // 对于 dp[i][j] 需要考虑 ：
      //     // 1. dp[i-1][j-1] 是回文 且 s[i] == s[j] 
      //     if (s[i] == s[j] && dp[i+1][j-1]) {
      //       dp[i][j] = true;
      //       if (j - i + 1 > maxL) {
      //         left = i;
      //         maxL = j-i+1;
      //       }
      //     }
      //   }
      // }
      // return s.substr(left, maxL);
      // 2.中心扩展算法
      int start = 0, end = 0;
      for (int i = 0; i < n; i++) {
        auto [left1, right1] = compare(s, i, i);
        auto [left2, right2] = compare(s, i, i+1); // 超出结果为-1
        if (right1 - left1 > end - start) {
          end = right1;
          start = left1;
        }
        if (right2 - left2 > end - start) {
          end = right2;
          start = left2;
        }
      }
      return s.substr(start, end - start +1);
    }

    pair<int, int> compare(const string& s, int l, int r) {
      while(l >= 0 && r< s.length() && s[l] == s[r]) {
        --l;
        ++r;
      }
      return {l+1, r-1};
    } 
};


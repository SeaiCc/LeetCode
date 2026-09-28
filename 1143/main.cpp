#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      using std::cout;
      // 1.dp[i][j] 以text1中 i 位置结尾的子串在 text2 中的最长子串
      // dp[0][j] 
      int m = text1.length(), n = text2.length();
      vector<vector<int>> dp(m, vector<int>(n, 0));
      if (text2[0] == text1[0]) dp[0][0] = 1;
      for (int j = 1; j < n; j++){
        dp[0][j] = (text2[j] == text1[0]) || dp[0][j-1];
      }
      for (int i = 1; i < m; i++) {
        dp[i][0] = (text1[i] == text2[0]) || dp[i-1][0];
      }

      for (int i = 1; i < m; i++) {
        // 每一行text1 固定，增加text2 找最大长度， 最大不超过 i 
        for (int j = 1; j < n; j++) {
          // dp[i-1][j]
          // dp[i][j-1]
          // dp[i-1][j-1]
          // dp[i][j] 相较于上面三个只可能 +0 / +1 
          // +1 情况 tex1[i] = text2[j] | dp[i-1][j] - dp[i-1][j-1] == 1 | dp[i][j-1] - dp[i-1][j-1] == 1
          int maxL = min(i, j) + 1;
          if (dp[i-1][j] == maxL || dp[i][j-1] == maxL) {
            dp[i][j] = maxL;
            continue;
          }
          bool text2Add = dp[i-1][j] - dp[i-1][j-1] == 1;
          bool text1Add = dp[i][j-1] - dp[i-1][j-1] == 1;

          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

          if (text1Add && text2Add) continue;
          if (text2Add) {
            dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
          }else if (text1Add) { 
            // 前一列竖向+1 
            // i-1  位置的 text1， text2 增加了 
            dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
          }else if(text1[i] == text2[j]) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
          }
        }
      }

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << dp[i][j] << " ";
        }
        cout << endl;
      }

      return dp[m-1][n-1];
      // 2. 直接判断text1[i-1] text2[j-1] 关系 同时加一个 相等的 dp[i-1][j-1] + 1
      // 否则取最大
      // 不用考虑超过maxL 
      // i-1 -> i 过程增加
      // 如果当前字符相等（text1[i-1] == text2[j-1]）：
      // 那么这个字符必然可以作为 LCS 的最后一个字符。此时 LCS 长度 = 去掉这两个字符的前缀的 LCS 长度 + 1，即 dp[i-1][j-1] + 1。
      // 为什么不用考虑 dp[i-1][j] 或 dp[i][j-1]？​ 因为既然这两个字符相等，把它们加入一定不会比不加更差。你可以反证：如果最优解不使用这对相等字符，那么它一定来自 dp[i-1][j] 或 dp[i][j-1]，但这两个值最多等于 dp[i-1][j-1] + 1（因为 dp[i-1][j] 最多比 dp[i-1][j-1] 多 1），所以 dp[i-1][j-1] + 1 已经是最大值了。
      // 如果当前字符不相等：
      // 那么这两个字符不可能同时出现在 LCS 的末尾。因此 LCS 要么来自 text1 去掉最后一个字符（dp[i-1][j]），要么来自 text2 去掉最后一个字符（dp[i][j-1]），取较大者即可。
      // 为什么不需要考虑 dp[i-1][j-1]？​ 因为 dp[i-1][j-1] 已经包含在 dp[i-1][j] 和 dp[i][j-1] 中了（后者至少不小于前者），所以取 max 就够了。
    }
};


int main() {
  Solution solu;
  string text1 = "bsbininm", text2 = "jmjkbkjkv";
  solu.longestCommonSubsequence(text1, text2);
}

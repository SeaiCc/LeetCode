#include <cstdio>
#include <iostream>

class Solution {
public:
    int longestValidParentheses(string s) {
      // 1. 栈 + dp
      // s 中有两段有效括号 
      // dp i 位置结尾的最长有效括号
      // 左右数量不匹配 | , 则 dp[i] = dp[i-1]
      // stk为 空且ch = ) , cur 置为0 dp[i] = max(cur, dp[i-1])
      // top=（ ch= ( 压栈 dp[i] = dp[i-1]
      // top=( , ch = ) ,pop, cur += 2, dp[i] = max(cur, dp[i-1])
      stack<int> stk; 
      int cur = 0;
      int res = 0;
      int n = s.length();
      if (n==0) return 0;
      vector<int> dp(n);
      if (s[0] == '(') {
        stk.push(0);
        cur = 0;
      }
      for (int i = 1; i < n; i++) {
        if (stk.empty() && s[i] == ')') {
          cur = 0;
          dp[i] = 0; // i 位置是断开的
        }else if(stk.empty()) {
          // 左括号压栈
          stk.push(i);
          dp[i] = dp[i-1]; // 只有前面是完整括号时才将 dp 传递 ，如果 该( 闭合就可以使用此dp值拼接
        }else if (s[stk.top()] == '(' && s[i] == ')') {
          // (())
          cur += 2;
          int topIdx = stk.top();
          stk.pop();
          if (stk.empty()) {
            // 可以跟前面的合并
            dp[i] = dp[topIdx] + cur;
          }else{
            dp[i] = cur;
          }
          res = max(res, dp[i]);
        }else{ // 栈顶为( 压入左括号
               // 不知道是不是断开的 ()(()
          stk.push(i);
          dp[i] = 0;
        }
      }
      return res;
      //2 . ()dp[i]=dp[i−2]+2
      //)) dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2
      //答案即为 dp 数组中的最大值
      //3.zhan
      //保持栈底元素为 最后一个没有被匹配的右括号的下标
      //4.计数 从左到右 从右到左
    }
};

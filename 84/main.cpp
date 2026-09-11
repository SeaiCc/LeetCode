#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      // 单调栈，存储下标，先只看左侧
      int n = heights.size();
      if (n == 0) return 0;
      stack<int> stk;
      int res = 0;
      // vector<int> val;
      // for (int i = 0; i < n; i++) {
      //   // 递增栈，如果出现了降序情况 左侧的就无需考虑
      //   while (!stk.empty() && heights[stk.top()] >= heights[i]) {
      //     stk.pop();
      //   }
      //   int left = -1;
      //   if (!stk.empty()) left = stk.top();
      //   left[i] = heights[i] * (i - left);
      //   stk.push(i);
      // }
      // vector<int> right;
      // stk.clear();
      // for (int i = n-1; i >= 0; i--) {
      //   while(!stk.empty() && heights[stk.top()] >= heights[i]) {
      //     stk.pop();
      //   }
      //   int right = n;
      //   if (!stk.empty()) right = stk.top();
      //   res = max(res, val[i] + heights[i] * (right - i - 1));
      //   stk.push(i);
      // }
      // return res;
      // 2. 只循环一次
      vector<int> left;
      stk.push(-1);
      for (int i = 0; i < n; i++) {
        while (stk.top() != -1 && heights[stk.top()] > heights[i]) {
          // stk.top() 出栈，右边界 为 i ，左边界为出栈之后的位置
          int topH = heights[stk.top()];
          stk.pop();
          res = max(res, topH * (i - stk.top() - 1));
        }
        stk.push(i);
      }
      while(stk.top() != -1) {
        int topH = heights[stk.top()];
        stk.pop();
        res = max(res, topH * (n - stk.top() - 1));
      }
      return res;
    }
};

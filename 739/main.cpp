#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      // 1. 遍历往后找比自己大的值 
      // 每个值之需考虑后面的，从后向前
      // 2.栈 先全压栈， 不能维护一个最大值 [2, 3, 4]  2->3
      // [2, 1, 3, 4]  1->3  2 1压栈 3 pop 1 pop2 push 3 递减栈 
      // 下一个 更 高气温
      int n = temperatures.size();
      if (n == 0) return vector<int>();
      vector<int> res = vector<int>(n, 0); // 初始化默认数组递减
      // stack<pair<int, int>> stk;
      // // 保证栈以递减push
      // stk.push(pair<int, int>(i, temperatures[i]);
      // for (int i = 1; i < n; i++) {
      //   // 比较
      //   while (!stk.empty() && stk.top().second < temperatures[i]) {
      //     // 应当更新 res[top.first]
      //     res[stk.top().first] = i - stk.top().first;
      //     stk.pop();
      //   }
      //   stk.push(pair<int, int>(i, temperatures[i]));
      // }
      // reTurn res;
      // 3. 只维护下标， 即用及取
      stack<int> stk;
      for (int i = 0; i < n; i++) {
        while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
          // 跟新res
          int topIdx = stk.top();
          res[topIdx] = i - topIdx;
          stk.pop();
        }
        stk.push(i);
      }
      return res;
    }
};

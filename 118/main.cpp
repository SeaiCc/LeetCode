#include <cstdio>
#include <iostream>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      // 1. 每一行为回文
      //      1
      //    1  1
      //  1   2   1
      //1   3   3   1
      //1  4  6   4   1
      //    10  10  5   1
      //      20  15  6   1
      //        35  21  7   1
      //4 = 1 + 3 = 1 + 1+2 = 1 + 1 + 1+1

      // vector<vector<int>> res;
      // res.push_back({1});
      // if (numRows == 1) return res;
      // res.push_back({1,1});
      // if (numRows == 2) return res;
      // for (int i = 2; i < numRows; i++) {
      //   vector<int> cur;
      //   // i 偶数 i / 2 + 1
      //   // i 奇数 i / 2 
      //   cur.push_back(1);
      //   for (int j = 1; j < i / 2 + 1; j++) {
      //     cur.push_back(res[i-1][j-1] + res[i-1][j]);
      //   }
      //
      //   int m = cur.size();
      //   if (i % 2 == 0) {
      //     for (int j = m - 2; j>=0; j--) {
      //       cur.push_back(cur[j]);
      //     }
      //   }else{
      //     for (int j = m - 1; j>=0; j--) {
      //       cur.push_back(cur[j]);
      //     }
      //   }
      //
      //   res.push_back(cur);
      // }
      // return res;
      // 2. 不复用,更简洁, 实测空间复杂度减小， 时间复杂度100%
      vector<vector<int>> ret(numRows);
      for (int i = 0; i < numRows;i++) {
        ret[i].resize(i+1);
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; j++) {
          ret[i][j] = ret[i - 1][j-1] + ret[i-1][j];
        }
      }
      return ret;
    }
};

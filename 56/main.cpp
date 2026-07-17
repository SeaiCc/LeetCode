#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int len = intervals.size();

      sort(intervals.begin(), intervals.end());

      vector<vector<int>> res;
      // int i = 0;
      // while ( i < len) {
      //   int start = intervals[i][0];
      //   int end = intervals[i][1];
      //   while (i < len -1 && end >= intervals[i+1][0]) {
      //     // 考虑合并
      //     if (intervals[i+1][1] > end) {
      //       // 更新end
      //       end = intervals[i+1][1];
      //     }
      //     i++;
      //
      //   }
      //   res.emplace_back(vector<int>{start, end});
      //   i++;
      // }

      

      // 方法2: 先加入res 后更新，每次遍历一个元素只有两种情况
      // 1: res中一个新的区间，直接加入
      // 2: res尾部元素的右边界 更新或保持不变
      // 与方法一的逻辑基本相同，只不过for-> while emplace_back.的位置
      for(int i = 0; i < len; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (res.empty() || start > res.back()[1]) {
          res.push_back({start, end});
        }else{
          res.back()[1] =  max(end, res.back()[1]);
        }
      }

      return res;
    }
};

#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      // 区分 本轮腐烂的橘子以及被腐烂橘子
      // 判断永远不被腐烂情况
      // 1. 主循环 + 统计轮数
      // 2. 从没腐烂的橘子出发找附近的腐烂橘子
      // 3. 联通的最小距离
      int m = grid.size();
      if(m == 0) return 0;
      int n = grid[0].size();
      if(n == 0) return 0;

      int rot = 2;
      bool findFlag = true;
      while(findFlag) {
        findFlag=false;
        for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
            // 本轮检测rot的橘子进行感染
            if(grid[i][j] == rot) {
              findFlag=true;
              // 上下左右为1都变成rot+1 
              if(i > 0 && grid[i-1][j]==1) grid[i-1][j] = rot + 1;
              if(i < m - 1 && grid[i+1][j] == 1) grid[i+1][j] = rot + 1;
              if(j>0 && grid[i][j-1]==1) grid[i][j-1] = rot + 1;
              if(j<n-1 && grid[i][j+1]==1) grid[i][j+1] = rot+1;
            }
          }
        }
        rot++;
      }
      // 找有没有没感染的橘子
      for(int i = 0; i < m; i++) {
        for(int j =0; j<n; j++) {
          if(grid[i][j]==1) return -1;
        }
      }
      // 没走感染流程，全是感染橘子
      if(rot==3) return 0;

      return rot-4;
    }
};

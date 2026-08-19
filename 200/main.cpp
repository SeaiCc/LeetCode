#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // vis 数组 + bfs
        // 每当访问到一个1 陆地时 把其 相连陆地全部访问一边 然后+1

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int nums = 0;
        for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
            if(vis[i][j] == 0 && grid[i][j] == '1'){
              nums++;
              bfs(grid, vis, i, j);
            }
          }
        }
        return nums;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
      if(vis[i][j] == 1) return;
      vis[i][j] = 1;
      // 遍历上下左右找相邻陆地
      if(i > 0 && grid[i-1][j] == '1') bfs(grid, vis, i - 1, j);
      if(i < grid.size() - 1 && grid[i+1][j] == '1') bfs(grid, vis, i+1, j);
      if(j > 0 && grid[i][j-1] == '1') bfs(grid, vis, i, j-1);
      if(j < grid[0].size() - 1 && grid[i][j+1] == '1') bfs(grid, vis, i, j+1);
    }
};

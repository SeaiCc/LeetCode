#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      if (m == 0) return false;
      int n = matrix[0].size();

      int down = m - 1, left = 0;
      while (down >=0  && left < n){
        if(matrix[down][left] == target) return true;
        // 最左一列 从下向上切
        while(down >= 0 && matrix[down][left] > target)
          down--;
        // 切完看右下角是否小于target
        if (down < 0) return false;
        if(matrix[down][n -1] < target)
          return false;

        // 最底一行 从左向右切
        while(left < n && matrix[down][left] < target)
          left++;
      }
      return false;

      // int i = 0, j = n -1 ;
      // while(i < m && j >= 0) {
      //   if(matrix[i][j] == target) return true;
      //
      //   if(matrix[i][j] < target) {
      //     j--;
      //   }else{
      //     i++;
      //   }
      // }
      // return false;

    }

    
};

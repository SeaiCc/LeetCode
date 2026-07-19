#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      if (n <= 1) return;
      
      // 先对折
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++){
          swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
      }

      // 沿反对角对折, 遍历左上三角
      for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - 1 - i; j++) {
          swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        }
      }

    }
};

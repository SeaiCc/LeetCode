#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
  void setZeros(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) 
      return;
    int n = matrix[0].size();
  
    // 1. 遍历，每次遇到0 更新行列
    // 2. 0 * n = 0

    // vector<int> row(m);
    // vector<int> column(n);
    //
    // for(int i = 0; i < m; i++) {
    //   for(int j = 0; j < n; j++) {
    //     if (matrix[i][j] == 0) {
    //       row[i] = 1;
    //       column[j] = 1;
    //     } 
    //   }
    // }
    //
    // for(int i = 0; i < m; i ++ ){
    //   if (row[i] == 1) {
    //     for(int j = 0; j < n; j ++) {
    //       matrix[i][j] = 0;
    //     }
    //   }
    // }
    //
    // for(int j = 0; j < n; j++) {
    //   if(column[j] == 1) {
    //     for(int i = 0; i < m; i++) {
    //       matrix[i][j] = 0;
    //     }
    //   }
    // }

    int flag = false; // 第0列是否有0

    for(int i = 0; i < m; i++){
      if (!matrix[i][0]) {
        flag= true;
      }

      for(int j = 1; j < n; j++) {
        if (matrix[i][j]){
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }

    // 第一行用来维护0 和非0, 从上往下会变全0
    for(int i = m -1; i >= 0; i--) {
      for(int j = 1; j<n; j++) {
        if (!matrix[i][0] || !matrix[0][j]){
          matrix[i][j] = 0;
        }

       
      }
      if (flag) {
        matrix[i][0] = 0;
      }
    }


  }
}


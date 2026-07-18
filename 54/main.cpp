#include <stdio.h>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      // int l = 0, t = 0;
      // int d = matrix.size() - 1;
      // if (d == 0)
      //   return matrix[0];
      // int r = matrix[0].size() - 1;
      // vector<int> res;
      // if (r == 0) {
      //   for(int i= 0; i <= d; i++) {
      //       res.push_back(matrix[i][0]);
      //   }
      //   return res;
      // }
      //
      // int i = 0;
      // int j = 0;
      // bool reverse = false;
      //
      // res.push_back(matrix[0][0]);
      // // 确保最后只剩一行或者一列
      // while(l < r || t < d) { // 不能 && 丢失最后一行 不能 || 边界更新逻辑错误
      //   // 上边界右移动
      //   if (i == t){
      //     while(j < r) {
      //       j++;
      //       res.push_back(matrix[i][j]);
      //     }
      //     t++;
      //   }
      //   if (t == d) {
      //     break;
      //   }
      //
      //   // 右边界下移
      //   if (j == r ) {
      //     while(i < d) {
      //       i++;
      //       res.push_back(matrix[i][j]);
      //     }
      //     r--;
      //   }
      //   if (l == r){
      //     break;
      //   }
      //
      //   // 下边界左移
      //   if (i == d) {
      //     while(j > l){
      //       j--;
      //       res.push_back(matrix[i][j]);
      //     }
      //     d--;
      //   }
      //   if (t == d){
      //     break;
      //   }
      //
      //   // 左边界上移
      //   if (j == l) {
      //     while(i > t) {
      //       i--;
      //       res.push_back(matrix[i][j]);
      //     }
      //     l++;
      //   }
      //
      //   if (l == r) {
      //     break;
      //   }
      // }
      //
      // if (matrix.size() < matrix[0].size()) {
      //   if (matrix.size() % 2 == 0) {
      //     while(r >= l){
      //       res.push_back(matrix[t][r]);
      //       r--;
      //     }
      //   }else{
      //     while(l <= r) {
      //       res.push_back(matrix[t][l]);
      //       l++;
      //     }
      //   }
      // }else if (matrix.size() == matrix[0].size()){
      //   if (matrix.size() % 2 == 0) {
      //       while(r >= l){
      //       res.push_back(matrix[t][r]);
      //       r--;
      //     }
      //   }else {
      //   while(l <= r) {
      //       res.push_back(matrix[t][l]);
      //       l++;
      //     }
      //   }
      // }else{
      //   if (matrix[0].size() % 2 == 0) {
      //     while(d >= t) {
      //       res.push_back(matrix[d][l]);
      //       d--;
      //     }
      //   }else{
      //     while(t <= d) {
      //       res.push_back(matrix[t][l]);
      //       t++;
      //     }
      //   }
      // }
      vector<int> res;
      if (matrix.empty()) return res;
      int t = 0, l = 0;
      int d = matrix.size() - 1;
      int r = matrix[0].size() - 1;

      // 循环中只利用一个临时元素i 或 j 
      // 跳出循环条件 非== 而是 > <
      while(true){
        for(int j = l; j <= r; j++)
          res.push_back(matrix[t][j]);
        t++;
        if(t > d) break;

        for(int i = t; i <= d; i++)
          res.push_back(matrix[i][r]);
        r--;
        if (r < l) break;

        for(int j = r; j >= l; j--) 
          res.push_back(matrix[d][j]);
        d--;
        if (d < t) break;

        for(int i = d; i >= t; i--) 
          res.push_back(matrix[i][l]);
        l++;
        if (l > r) break;
      }

      return res;
    }
};

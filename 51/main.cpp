#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      // n = 4
      // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]
      // 回溯
      // 行限制 按行放，每行放一个
      // 列限制 vis nx1 从 vis 中取非1 位置放置
      // 斜线 
      // 2. 位运算
      // (2^n - 1) & (~(col | diag1 | diag)) 屏蔽高位干扰
      // 得到可以放置皇后的位置（该结果的值为 1 的位置表示可以放置皇后的位置）
      // int position = availablePositions & (-availablePositions);
      //  int column = __builtin_ctz(position);
      //  20 (10100)  4(100) 2 
      //  queens[row] = column; 改行的 位置 column 放Q
      // 3. vector<string> cur(n, string(n, '.'))  cur[level][j] = 'Q'; 不用getQStr
      vector<vector<string>> res;
      vector<int> col(n, 0);
      vector<int> diag1(2*n-1, 0);
      vector<int> diag2(2*n-1, 0);
      vector<string> cur;
      helper(res, cur, 0, col, diag1, diag2);
      return res;
    }

    void helper(vector<vector<string>>& res, vector<string>& cur, int row, vector<int>& col, 
                vector<int>& diag1, vector<int>& diag2) {
      int n = col.size();
      if(row == n) {
        res.push_back(cur);
        return;
      }

      // 遍历，分别检查 列 diag 1 diag2 限制 
      for(int j = 0; j < n; j++) {
        if(col[j] == 1) continue;
        if(diag1[row-j + n-1] == 1) continue;
        if(diag2[row+j] == 1) continue;
        // (row, j) 可放置
        cur.push_back(getQStr(n, j));
        col[j] = 1;
        diag1[row-j + n-1] = 1;
        diag2[row+j] = 1;
        helper(res, cur, row+1, col, diag1, diag2);
        col[j] = 0;
        diag1[row-j + n-1] = 0;
        diag2[row+j] = 0;
        cur.pop_back();
      }
      
    }

    string getQStr(int n, int pos) {
      string s = "";
      for(int i = 0; i < n; i++) {
        if (i == pos) s.push_back('Q');
        else s.push_back('.');
      }
      return s;
    }
};


int main() {
  Solution solu;
}

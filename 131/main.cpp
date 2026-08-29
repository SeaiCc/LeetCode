#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> f;
public:
    vector<vector<string>> partition(string s) {
      // 回文串 所有可能方案
      // 1. 最坏全拆开， 再组合
      // 2. 从头开始 找以第 i 个 位置开始的最长 
      // ababa  a/aba/ababa
      // s.substr(0, 5)
      // 3. 优化2 isReverse 用二维数组预先存储
      int n = s.length();
      f.assign(n, vector<int>(n, true));

      //  i >= j true , f 矩阵左下角全true
      //  i, j  需要 i + 1 (从下往上), j-1 （从左往右）
      for(int i = n - 2; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
          f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
        }
      }

      vector<vector<string>> res;
      vector<string> cur;
      helper(res, cur, s, 0);
      return res;
    }

    void helper(vector<vector<string>>& res, vector<string>& cur, string& s, int l){
      // 先判断 s[i:j) 是否回文
      
      if(l == s.length()) {
        res.push_back(cur);
        return;
      }

      // 到此位置，l之前的已经加入 res
      for(int i = l; i < s.length();i++) {
        // if(!isReverse(s, l, i)) continue;
        if(!f[l][i]) continue;
        cur.push_back(s.substr(l, i+1-l));
        helper(res, cur, s, i+1);
        cur.pop_back();
      }
    }

    bool isReverse(string& s, int i, int j) {
      while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
      }
      return true;
    }
};


int main() {
  Solution solu;
  string s = "aab";
  solu.partition(s);
}

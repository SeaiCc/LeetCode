#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size();
      if(m == 0) return false;
      int n = board[0].size();
      if(n == 0) return false;
      if (word.length() == 0) return true;

      vector<vector<bool>> vis(m, vector<bool>(n, false));
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          if(board[i][j] != word[0]) continue;
          if(helper(board, vis, i, j, word, 1)) return true;
        }
      }
      return false;
    }

    bool helper(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j,
                string& word, int pos) {
      if(pos == word.length()) return true;

      vis[i][j] = true;

      // 找(i, j) 附近 word [pos]
      if(i>0 && !vis[i-1][j] && board[i-1][j] == word[pos]) {
        if(helper(board, vis, i - 1, j, word, pos + 1)) return true;
      }
      if(i < board.size() - 1 && !vis[i+1][j] && board[i+1][j] == word[pos]) {
        if(helper(board, vis, i+1, j, word, pos+1)) return true;
      }
      if(j > 0 && !vis[i][j-1] && board[i][j-1] == word[pos]) {
        if(helper(board, vis, i, j-1, word, pos+1)) return true;
      }
      if(j < board[0].size() -1 && !vis[i][j+1] && board[i][j+1] == word[pos]) {
        if(helper(board, vis, i, j+1, word, pos+1)) return true;
      }

      vis[i][j] = false;
      return false;
    }
};


int main() {
  Solution* solu = new Solution;
  vector<vector<char>> board = {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}
  };
  string word = "ABCB";
  solu->exist(board, word);
}

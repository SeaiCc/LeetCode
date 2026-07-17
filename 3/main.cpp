#include <stdio.h>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int res = 0;
      unordered_set<char> occ;
      int n = s.size();

      int rk = -1;
      for(int i = 0; i < n; i++) {
        // 右移，移除前面一个字符
        if (i != 0) {
          occ.erase(s[i-1]);
        }
        while(rk + 1 < n && !occ.count(s[rk + 1])) {
          occ.insert(s[rk + 1]);
          rk++;
        }
        res = max(res, rk - i + 1);
      }
      return res;
    }
};


int main(int argc, int* argv) {
  string s = "abcabcbb";
  Solution* solu = new Solution();
  int res = solu->lengthOfLongestSubstring(s);
  std::cout << res << endl;
}

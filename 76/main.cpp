#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
  public:
    string minWindows(string s, string t) {
      int sLen = s.size(), tLen = t.size();
      if (sLen < tLen) 
        return "";

      // 最短：
      //
      //
      // 重复字符分别统计
      vector<int> count(128);
      for (int i = 0; i < tLen; i++) {
        count[t[i]]++;
      }

      // 滑动窗口左右指针
      int left = 0, right = 0;
      int minLen = sLen  + 1;
      int needCount = tLen;

      int start = 0;
      // 右侧指针右侧扩张
      while (right < sLen) {
        // 找到t中的字符， 且之前的不够
        if (count[s[right]] > 0) {
          needCount--;
        }

        // 所需字符-1, 可为负数表示多余
        count[s[right]]--;
        right++;

        // 所有字符都已经找到
        while(needCount == 0) {
          int temp = right - left;
          if (minLen > temp) {
            minLen = temp;
            start = left;
          }
          
          // 左边界缩进，直到删除了一个t中字符
          count[s[left]]++;
          if (count[s[left]] > 0) {
            needCount++;
          }
          left++;
        }
      }
      
      return minLen == sLen + 1 ? "" : s.substr(start, start + minLen);
   }

};


int main(int argc, char* argv[]) {
  Solution solu;
  string s = "ADOBECODEBANC";
  string t =  "ABC";
  string res = solu.minWindows(s, t);
  cout << res << endl;
}

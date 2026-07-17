#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      int sLen = s.size(), pLen = p.size();
      vector<int> res;
      if (sLen < pLen) {
        return vector<int>();
      }
      
      int diff = 0;
      vector<int> count(26); // 26字母

      // 第一个窗口
      for (int i = 0; i < pLen; i++) {
        ++count[s[i] - 'a'];
        --count[p[i] - 'a'];
      }

      for (int i = 0; i < 26; i++) {
        if (count[i] != 0) 
          diff++;
      }

      // p == s 
      if (diff == 0)
        res.emplace_back(0);

      // 滑动
      for (int i = 0; i < sLen - pLen; i++) {
        // 右滑
        // 当前窗口 s[i] 对应字母比 p多一个 剔除后differ 减一
        if (count[s[i] - 'a'] == 1) {
          --diff;
        }else if (count[s[i] - 'a'] == 0) {
          // 原先字母 s[i] 一致，剔除后 p多一个
          ++diff;
        }
        // 其他情况不会引起diff变化
        --count[s[i] - 'a']; // 更新countliang
        // 窗口右侧新增一个字母
        if (count[s[i + pLen] - 'a'] == -1) {
          // 若原先s比p少一个[i + pLen]处的字母，加进后diff少一个
          diff--;
        }else if(count[s[i+pLen] - 'a'] == 0) {
          // 加入后多一个
          diff++;
        }
        // 更新count 
        count[s[i + pLen] - 'a']++;
      
        if (diff == 0) {
          res.emplace_back(i + 1);
        }
      }

      return res;
      
    }
}


#include <cstdio>
#include <iostream>

class Solution {
public:
    vector<int> partitionLabels(string s) {
      // 尽可能多的片段, 仅由小写字母
      // 位置前移，找到 若开始结束都为字符'a', 整个为一个，中间判断无意义
      // 按字母出现顺序排序，同时维护最后出现的位置
      int n = s.length();
      vector<int> tail(26, 0);
      for (int i = 0; i < n; i++) {
        tail[s[i] - 'a'] = i;
      }

      int end = tail[s[0] - 'a'];
      int pre = -1;
      int i = 0;
      vector<int> res;
      while(end < n) {
        if(end == n-1) {
            res.push_back(end - pre);
            break;
        }
         if(i == end) {
          res.push_back(end - pre);
          pre = end;
          // 更新下一个end
          end = tail[s[i+1] - 'a'];
        }else if (tail[s[i] - 'a'] > end) {
          end = tail[s[i] - 'a'];
        }
        i++;
      }
      return res;
      // 第二次用for 不用while
    }

};

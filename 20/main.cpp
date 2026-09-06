#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      unordered_map<char, char> mp;

      mp['('] = ')';
      mp['{'] = '}';
      mp['['] = ']';

      if (s.length() == 0) return true;

      int i = 0;
      stk.push(s[i++]);

      while(i < s.length()) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
          stk.push(s[i]);
        else if (stk.empty()) return false;
        else if (mp[stk.top()] == s[i]) 
          stk.pop();
        else 
          return false;
        i++;
      }
      return stk.empty();
    }
};

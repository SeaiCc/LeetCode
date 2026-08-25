#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
private:
  vector<string> numbers = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
  };
public:
    vector<string> letterCombinations(string digits) {
      // 通过ascii 建立映射 '2' -> 0 -> 0*3/+1/+2 -> +'a' 'a' 'b' 'c'
      vector<string> res;
      helper(res, digits, "", 0);
      return res;
    }

    void helper(vector<string>& res, string digits, string cur, int pos) {
      if(pos == digits.length()) {
        res.push_back(cur);
        return;
      }

      // 在位置pos加入一个字符，n选1， 然后继续下一个字符
      int numPos = digits[pos]-'2';
      for(int i = 0; i < numbers[numPos].length(); i++) {
        char ch = numbers[numbers][i];
        cur.push_back(ch);
        helper(res, digits, cur, pos+1);
        cur.pop_back();
      }
    }
};

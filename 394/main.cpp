#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
       // 1.模拟 
       //  第一个字符串可能不以 [] 括起
       //  有可能出现嵌套
       //  2.单栈法同时存储数字字符
       int n = s.length();
       if(n == 0) return s;
      
       stack<string> stk_s;
       stack<int> stk_t;

       string res = "";
       int times = 0;
       // i位置必为数字
       for(int i = 0; i < n; i++) {
         if(isNum(s[i])) {
           times = times*10 + (s[i] - '0');
         }else if(s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
         }else if(s[i] == '[') {
            stk_t.push(times);
            stk_s.push(res); // 2[c3[b]a] push"" push"c"
            times = 0;
            res = "";
         }else if(s[i] == ']') {
            // res 统计完毕 
            // 2[c3[b]a]
            // 2[3[b]a]
            // 从stk_t 取出 3
            string temp = res;
            res = stk_s.top();
            for(int j = 0; j < stk_t.top(); j++) 
              res += temp;
            stk_t.pop();
            stk_s.pop();
         }else{
           cout << "other char: " << s[i] << endl;
         }
       }
       return res;
    }
    
     bool isNum(char c) {
       return c >= '0' && c <= '9';
     }

     bool isChar(char c) {
       return c >= 'a' && c <= 'z';
     }

};

int main() {
  Solution solu;
  // string s = "3[a]2[bc]";
  string s = "100[leetcode]";
  solu.decodeString(s);
}

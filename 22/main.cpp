#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
  shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    vector<string> generateParenthesis(int n) {
      // n =1 ()
      // n = 2 () () (())
      // n = 3 ()()() (()())  ((()))
      //              (())()
      // 1. int left / right = n 
      // 2. stack 
      // 3. cache + (a)b 
      // vector<string> res;
      // string s = "";
      // helper(res, s, n, n);
      // return res;
      return *generate(n);
    }

    shared_ptr<vector<string>> generate(int n) {
      if(cache[n] != nullptr) return cache[n];

      if(n==0) {
        return shared_ptr<vector<string>>(new vector<string>{""});
      }else{
        auto result = shared_ptr<vector<string>>(new vector<string>);
        for(int i = 0; i < n; i++) {
          auto left = generate(i);
          auto right = generate(n-i-1);
          for(auto &l : *left) {
            for(auto & r: *right) {
              result -> push_back("(" + l + ")" + r);
            }
          }
        }
        cache[n] = result;
      }

      return cache[n];
    }

    // void helper(vector<string>& res, string& cur, int left, int right) {
    //   if(left == 0 && right == 0) {
    //     res.emplace_back(cur);
    //     return;
    //   }
    //
    //   //  加左
    //   if(left > 0) {
    //     cur += '(';
    //     helper(res, cur, left-1, right);
    //     cur.pop_back();
    //   }
    //
    //   // left的数量必须要 小于right 加右
    //   if(left < right ) {
    //     cur += ')';
    //     helper(res, cur, left, right-1);
    //     cur.pop_back();
    //   }
    // }
};


int main() {
  // Solution* solu = new Solution();
  Solution solu;

  int n = 3;
  solu.generateParenthesis(n);
}

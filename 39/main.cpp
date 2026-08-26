#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      //同一个 数字可以 无限制重复被选取
      //1. 回溯
      //2. map 维护数量，不需要cur
      //3. 外层剪枝优化 + target 减（去掉sum） + emplace_back
      vector<vector<int>> res;
      vector<int> cur;
      //helper(res, candidates, cur, 0, target, 0);
      helper(res, candidates, cur, target, 0);
      return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int>& cur, int target, int pos) {
      if(pos == candidates.size()) return;
      if(target == 0) {
        res.emplace_back(cur);  
        return;
      }
      // pos + 1 表示只考虑pos后的数
      helper(res, candidates, cur, target, pos + 1);

      // 剪枝
      if(target - candidates[pos] >= 0) {
        // 对于i位置 可以加入cur 也可以不加入
        cur.emplace_back(candidates[pos]);
        // 还可以继续加 pos位置的数
        helper(res, candidates, cur, target-candidates[pos], pos);
        cur.pop_back();
      }
    }

    // void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int>& cur, int sum, int target, int pos) {
    //   cout << pos << candidates.size() << endl;
    //   if(sum > target || pos == candidates.size()) return;
    //   if(sum == target) {
    //     res.push_back(cur);  
    //     return;
    //   }
    //
    //   // 对于i位置 可以加入cur 也可以不加入
    //   cur.push_back(candidates[pos]);
    //   // 还可以继续加 pos位置的数
    //   helper(res, candidates, cur, sum+candidates[pos], target, pos);
    //   cur.pop_back();
    //   // pos + 1 表示只考虑pos后的数
    //   helper(res, candidates, cur, sum, target, pos + 1);
    // }
};


int main() {
  Solution solu;
  vector<int> can = {2,3,6,7};
  solu.combinationSum(can, 7);
}

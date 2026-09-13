#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      // 1. map 维护数量
      // 如何统计频次的同时维护频次顺序？
      // pair<int, int> 最大堆 以pair的second 排序，需要定位节点 更新节点 更新堆
      int n = nums.size();
      if (k == 0) return vector<int>();
      unordered_map<int, int> mp;
      for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
      }

      auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
      };
      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> dp(cmp);
      for (const auto& pair : mp) {
        dp.push(pair);
      }

      vector<int> res;
      for (int i = 0; i < k; i++) {
        res.emplace_back(dp.top().first);
        dp.pop();
      }

      return res;
      // 2.最小堆， 淘汰栈顶始终保持 size为k
      // 3.快排

    }
};

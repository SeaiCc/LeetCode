#include <stdio.h>
#include <iostream>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int len = nums.size();
      int res = 0;
      
      // // 1. 双重循环遍历
      // for (int i = 0; i < len; i++) {
      //   // 统计i开头的符合字数组 
      //   int sum = 0;
      //   for (int j = i; j < len; j++) {
      //     sum += nums[j];
      //     if (sum == k) 
      //       res++;
      //   }
      // }
      // return res;
      // 2.
      unordered_map<int, int> mp;
      mp[0] = 1;
      int count = 0, pre = 0;
      for (auto& x:nums) {
        // 前缀 + x
        pre += x;
        // mp 的key为前缀和 
        if (mp.find(pre - k) != mp.end()) {
          count += mp[pre - k]; // mp的值为 前缀和 对应的数量
        }
        mp[pre]++;

      }
      return count;
    }
};

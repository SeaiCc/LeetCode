#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int n = nums.size();

      // 1. 直接遍历
      // int i = 0;
      // for (; i < n; i++) {
      //   if(nums[i] >= target) return i;
      // }
      // return i;
      //
      //
      // 2.2fen
      // lower bound
      // 小于边界0 ， 大于有边界 n ，等于 r = mid ，介于两者之间 return l
      //
      int l = 0, r = n;
      while(l < r) {
        int mid = (l + r) / 2;
        if(nums[mid] < target) {
          //target 在 右侧
          l = mid+1;
        }else {  // >=
          r = mid;
        }
      }

      return l;
    }
};

#include <cstdio>
#include <iostream>

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n-1,i = 0;
      while(l < r && i < n) {
        if (nums[i] == 0 && i > l) {
          swap(nums[i], nums[l]);
          while(l < n && nums[l] == 0) l++;
          while(r >= 0 && nums[r] == 2) r--;
          i = l;
        }else if(nums[i] == 2 && i < r) {
          swap(nums[i], nums[r]);
          while(l < n && nums[l] == 0) l++;
          while(r >= 0 && nums[r] == 2) r--;
          i = l;
        }else{
            i++;
        }
        // cout << i << l << r << endl;
      }
      // 2. 单指针，第一次移动 0  第二次移动1 
      // 3.双指针 p0 p1 保证 p1 和p0 相等，或者在p0 之后
      // 发现0 时 同时移动  p0 p1
    }
      
};

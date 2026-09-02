#include <stdio.h>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res = {-1, -1};
      if(nums.size() == 0) return res;
      if(nums.size() == 1 && nums[0] == target) return {0,0};

      // 找小于targe的最大值和大于target的最小值
      int l = 0, r = nums.size()-1;
      while(l < r) {
        int mid = l + (r - l) / 2; // 1 2, mid = 1 
        if (nums[mid] < target) { // <:  找大于等于 target的位置
          l = mid + 1;  // + 1 防止死循环
        } else {
          r = mid; // [l,  mid] 当l r 都处于target范围，需要移动mid
        }
      }
      // 最终得到的l 为边界
      if (nums[l] == target) res[0] = l;
      l = 0, r = nums.size()-1;
      while(l < r) {
        int mid = l + (r - l) / 2 + 1; // 1 2, mid = 2
        if (nums[mid] <= target) { 
          l = mid; 
        }else{
          r = mid-1; //  防止死循环
        }
      }
      cout << l << r <<endl;
      if (nums[r] == target) res[1]  = r;
      return res;
    }
};

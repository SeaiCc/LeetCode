#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      // 未知的某个下标 k
      int n = nums.size();

        // nums[mid] < target 
        // l mid k r : target 在 mid, k 之间
        // l k mid r : target 在 l，k 或 mid ，r之间
        // nums[mid] > nums[l] mid < k, 或l r 顺序 
        // nums[mid] < nums[l] mid > k
        //
        // nums[mid] > target
        // l mid k r : l, mid 或  k+1, r
        // l k mid r : k ,mid 
        // 2. 利用nums[0] nums[n-1] 让每次循环使用排除或选择有序的一部分
      return helper(nums, 0, n - 1, target);
    }

    int helper(vector<int>& nums, int l, int r, int target) {
      if (l > r) return -1;

      int mid = l + (r - l) / 2;
      // 判断 l mid 连续还是 mid r 连续
      if (nums[mid] == target) return mid;
      int res = -1;
      if (nums[mid] >= nums[l]) {   // 左边界小于
        // l mid 连续，mid右侧可能出现比 nums[mid] 大或小的数
        res = helper(nums, mid+1, r, target);
        if (res != -1) return res; // 提前退出
        // target < nums[mid] 才需要遍历左侧
        if (target < nums[mid])
          res = helper(nums, l, mid - 1, target);
      }else{
        // mid r 连续, mid 必须要遍历左侧
        res = helper(nums, l, mid - 1, target);
        if (res != -1) return res;
        // target < nums[mid] 
        if (target > nums[mid])
          res = helper(nums, mid+1, r, target);
      }
      return res;
    }
};


int main() {
  Solution solu;
  //vector<int> nums = {4,5,6,7,0,1,2};
  vector<int> nums = {3, 1};
  int target = 1;
  solu.search(nums, target);
}

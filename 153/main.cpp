#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0];

    int l = 0, r = n-1;
    // while(l < r) {
    //   int mid = l + (r-l) / 2;

    //   if(nums[mid] < nums[0]) {
    //     // mid 右侧的可以排除
    //     r = mid;
    //   }else if (nums[mid] > nums[n-1]){
    //     // mid 左侧可以排除
    //     l = mid + 1;
    //   }else {
    //     r = mid -1;
    //   }
    // }

    // 2. 始终保持 l mid r 的形状
    // 最小值左侧 num[i] > nums[r] 的值都可以舍弃
    while(l < r) {
      int mid = l + (r-l) / 2;
      if(nums[mid] < nums[r])
        r = mid;
      else
        l = mid+1;
    }
 
    return nums[l];
  }
};

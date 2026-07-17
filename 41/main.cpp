#include <stdio.h>
#include <iostream>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      // 未排序 没有出现的最小的正整数
      // O(n): 排序(x) 常数空间(x)
      // 假设一个值为res，可能[0, res] 为完整，无效遍历
      // 遍历过程没有map 无法统计零散值
      // 分治：连续的值分散到 两个区域 [3,5] [2,4,] x
      // 递归：f(n -1) == num[i], res= ??
      // 关键信息：下标 0 - N-1, 连续 则值为 1 ~ N-1
      int len = nums.size();
      // 交换到正确的位置
      for(int i = 0; i < len; i++) {
          
          while(nums[i] > 0 && nums[i] <= len && nums[nums[i] -1] != nums[i]) { // 应移动到nums[i] - 1, 如 3 移动到 位置2 
            swap(nums[nums[i] -1], nums[i]);
          }
      }
      
      for(int i = 0 ; i < len; i++) {
        if (nums[i] != i + 1){
          return i+1;
        }
      }
      return len +1;
    }
};

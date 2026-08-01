#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 从后向前找 第一个顺序位置  7 98....
        // 从98... 找出大于7的最小值 与7 交换 ，然后反转后面的值
        int n = nums.size();
        if (n <= 1) return;
        int i =  n-2;
        for(; i >= 0; i--){
            if(nums[i] < nums[i+1]) break;
        }
        if(i != -1){
            // 不是全逆序排列
            int j = i + 1;
            for(; j < n; j++){
                if(nums[j] <= nums[i]) break;
            }
            j--;
            // 交换 i j
            swap(nums[i], nums[j]);
        }
        i++;
        int j = n - 1;
        while(i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
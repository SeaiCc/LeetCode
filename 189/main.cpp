#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
        k %= len;

        reverse(nums, 0, len - 1 );
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }

    void reverse(vector<int>& nums, int start, int end) {
      while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
      }
    }
};

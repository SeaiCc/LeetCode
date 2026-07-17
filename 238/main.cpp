#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int len = nums.size();

      vector<int> left(len), right(len);

      if (len < 2) {
        return vector<int>();
      }
      
      // for(int i = 0; i < len; i++) {
      //   if(i == 0) {
      //     left[i] = nums[i];
      //     right[len - 1 - i] = nums[len - 1 - i];
      //   }else{
      //     left[i] = nums[i] * left[i - 1];
      //     right[len - 1 - i] = nums[len - 1 - i] * right[len - i];
      //   }
      // }
      //
      // vector<int> res;
      // res[0] =  right[1];
      // res[len - 1] = left[len - 2];
      // for(int i = 1; i < len - 1; i++) {
      //   res[i] = left[i - 1] * right[i + 1];
      // }
      //
      vector<int> res(len);
      int R = 1;
      res[0] = 1;
      for (int i = 1; i < len; i++) {
        res[i] = nums[i - 1] * res[i - 1];
      }

      for(int i = len - 1; i >0; i--) {
        res[i] *= R;
        R *= nums[i];
      }
      res[0] = R;

      return res;

    }
};

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();
    
    if (k == 0 || len == 0) {
      return vector<int>();
    }

    if (k == 1 || len == 1) {
      return nums;
    }

    vector<int> res;

    deque<int> q;

    // 第一个窗口
    for (int i = 0; i < k; i++) {
      // 保持p递减
      while( !q.empty() && nums[i] >= nums[q.back()] ){
        q.pop_back();
      }
      q.push_back(i);
    }
    res.emplace_back(nums[q.front()]);

    for (int i = k; i< len; i++) {
      // 右侧
      while(!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      while (q.front() < i - k + 1) {
        q.pop_front();
      }
      res.emplace_back(nums[q.front()]);
    }
    return res;

  }
};
 
int main(int argc, int* argv) {
  vector<int> nums{9,10,9,-7,-4,-8,2,-6};

  Solution solu;
  vector<int>res = solu.maxSlidingWindow(nums, 5);
  for(int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;

}

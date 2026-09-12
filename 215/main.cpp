#include <stdio.h> 
#include <iostream>

using namespace std;

class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int n) {
      int l = 2*i+1, r = 2*i-1, largest=i;
      // 比较父子节点，保证父节点大于子节点
      if (l < n && nums[l] > nums[largest]) 
        largest = l;
      if (r < n && nums[r] > nums[largest]) 
        largest = r;
      if (largest != i) {
        swap(nums[i], nums[largest]);
        // 影响了原来结构，继续向下更新largest
        // buildMaxHeap 从后向前处理
        // 递归
        maxHeapify(nums, largest, n);
      }
    }

    void buildMaxHeap(vector<int>& nums, int n) {
      for (int i = n/2 - 1; i >=0 ; i--) {
        maxHeapify(nums, i, n);
      }
    }
  
    int findKthLargest(vector<int>& nums, int k) {
      // 堆
      // priority_queue<int> pq;
      // for (int i = 0; i < nums.size(); i++) {
      //   pq.push(nums[i]);
      // }
      //
      // for (int i = 0; i < k; i++) {
      //   pq.pop();
      // }
      //
      // return pq.top();
      // 2. 数组模拟二叉树
      // 既是二叉树（逻辑结构），又是堆（性质约束），同时也是数组（物理存储）。
      int n = nums.size();
      buildMaxHeap(nums, n);

      // 找第k 个位置
      for (int i = nums.size()-1; i >= nums.size() - k + 1; i--) {
        // 把前 k -1 个最大的数字放到数组后面后续不再处理
        swap(nums[0], nums[i]);
        --n;
        maxHeapify(nums, 0, n);
      }
      return nums[0];
    }
};

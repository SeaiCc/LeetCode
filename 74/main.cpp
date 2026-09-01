#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      if (m == 0) return false;
      int n = matrix[0].size();
      if (n == 0)  return false;

      // 1. 二分查找行，二分查找列 
      // 2. 展开成单个数组
      // 3. 借助upper_bound
      int top = 0, down = m; // 第五步  再判断边界时再确定
      // 找小于targe 的最大值
      while(top < down) {
        // 1 2 : mid = 1  2 3: mid= 2  
        int mid = top + (down - top) / 2; // 第一步 按习惯 边界相邻时 取左 决定了下面找的是 大于/大于等于target位置，而不是小于/小于等于位置
        if (matrix[mid][0] <= target) { // 第三步 < 找大于等于taget位置, <= 找大于taget第一个位置， <= 能和题意小于taget分隔开 
          // 更新 top 总与 < or <= 绑定
          // <=  不能搭配 mid ，当 down = top+1 时会陷入死循环
          // <= 搭配 mid + 1 ，当 = 成立时，左边界跳过 要找的行，后续down 收敛到 top 始终比需要找的值大1， 要么使 判断条件top <= down, 要么后续从top -1 行找
          // while 条件： 加= 使得 top down 结束循环必然不想等
          // < 搭配 mid  考虑down = top + 1， top不会更新
          // < 搭配 mid + 1 考虑 down = top + 1， 5 在 3，10 之间 top定位到的是 10  
          // 由于收敛时 1 2 : mid = 1  2 3: mid= 2 特性 top = mid 放这里会死循环
          top = mid + 1;      // 第二步 由于mid 特性, 必须 + 1，除非mid = ()/2 + 1
        }else{ // m[mid][0] == target
          // mid  不可能等与 down ， down =  mid 就算更新
          down = mid;  // 第四步 target 在[top, mid)  top 最后找的是 大于 taget第一位置，为了让最终top == down 这里不使用 mid -1 跳过
                       // 当mid = top, mid - 1就是要找的行， 当 mid = top + 1, mid - 1 - 1 才是要找的行
        }
      }
      // top down 结果是否相等是 有while条件 以及 down = mid 共同决定的
      // taget 小于最小值，top = down = 0 
      // taget 大于最大值，就应该找最大行

      if (top == 0) return false;
      
      int l = 0, r = n;
      while(l < r) {
        int mid = l + (r - l) / 2;  // 1 2: mid = 1 , 2 3: mid = 2
        if (matrix[top-1][mid] < target) { // 按行找 大于等于 或小于等于都可以, 这里找大于等于第一个位置，直接拿top判断
          l = mid + 1;  // 防死循环 mid + 1
        }else{
          r = mid;  // taget 在[top, mid] 中， mid - 1 会越过 mid , 保证 退出循环l == r 这里 用mid
        }
      }

      // target上界判断
      if (l == n) return false;
      return matrix[top-1][l] == target;
    }
};


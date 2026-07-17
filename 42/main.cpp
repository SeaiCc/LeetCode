#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
  public:
    int trap(vector<int>& height) {
      int left = 0, right = height.size()-1;
        int res = 0;
        
        bool moveLeft = true;

        // 计算left right围成的面积
        //std::cout << right << "," << left;
        res = min(height[left], height[right]) * (right - left);
        while (left < right) {
            //std::cout << "*******"  << res << std::endl;
            // 较为矮的一侧向中间移动
            moveLeft = height[left]<= height[right]? true : false;

            // left移动为例
            // 循环找到第一个 大于多边界的位置，
            // 同时减掉 柱子的高度
            
            if( moveLeft) {
            int old = left;
            left++;
            while(left < right && height[left] <= height[old]) {
                //std::cout << "left -=" << height[left] << std::endl;
                res -= height[left];
                left++;
            }
            //std::cout << "left -=" << height[old] << std::endl;
            res -= height[old];
            res += (right - left) * (min(height[right], height[left]) - height[old]);
            }else {
            int old = right;
            right--;
            while(left < right && height[right] <= height[old]) {
                //std::cout << "right -=" << height[right] << std::endl;
                res -= height[right];
                right--;
            }
            //std::cout << "right -=" << height[old] << std::endl;
            res -= height[old];
            
            res += (right - left) * (min(height[right], height[left]) - height[old]);
            }

            // 找到后，判断与右边界中较低一侧 减去原左边界 
            // res += 新增的雨水面积
        }

        return res;
    }
};


int main(int argc, int* argv) {
  
}

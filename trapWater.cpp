/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <vector>
using namespace std;

int trap(vector<int>& height) 
{
    int left = 0, right = height.size() - 1;
    int lmax = 0, rmax = 0;
    int res = 0;
    while(left < right)
    {
        lmax = max(lmax, height[left]);
        rmax = max(rmax, height[right]);
        if(lmax < rmax) // 只看当前小的, 因为只要足够小, 说明这部分水都可以算上 (即肯定都是有余量的)
        {
            res += lmax - height[left];
            left ++;
        }
        else
        {
            res = rmax - height[right];
            right --;
        }
    }
    return res;
}

// 42. 接雨水

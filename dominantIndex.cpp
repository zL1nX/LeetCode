/*
给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。

请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。

 

示例 1：

输入：nums = [3,6,1,0]
输出：1
解释：6 是最大的整数，对于数组中的其他整数，6 大于数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
示例 2：

输入：nums = [1,2,3,4]
输出：-1
解释：4 没有超过 3 的两倍大，所以返回 -1 。
示例 3：

输入：nums = [1]
输出：0
解释：因为不存在其他数字，所以认为现有数字 1 至少是其他数字的两倍。
 

提示：

1 <= nums.length <= 50
0 <= nums[i] <= 100
nums 中的最大元素是唯一的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int dominantIndex(vector<int>& nums) 
{
    int maxn = nums[0], second = INT_MAX, ind = 0;
    for(int i = 1;i < nums.size(); i++)
    {
        if(nums[i] > maxn)
        {
            second = maxn;
            maxn = nums[i];
            ind = i;
        }
        else if(nums[i] > second)
        {
            second = nums[i];
        }
    }
    return maxn >= second * 2 ? ind : -1;
}

// 好像也没别的更好的方法，最基本的方法无非就是一个循环找出max，再来一个循环判断是否满足条件

// 第二个循环可以简化为：在第一个循环中找到最大值和第二大值，最后不需要第二个循环了，直接比较最大值和第二大值之间是否满足二倍的关系

// 然后就是注意如何更新第二大值，把旧的max更新为第二大值，也可以在另一个if中更新单独更新第二大值

// 这个第二大值的方法还挺好玩的
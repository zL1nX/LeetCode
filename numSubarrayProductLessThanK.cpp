/*
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 

示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
示例 2：

输入：nums = [1,2,3], k = 0
输出：0
 

提示: 

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
通过次数45,610提交次数101,096

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    int accm = 1, n = nums.size();
    int left = 0, count = 0;
    for(int right = 0; right < n; right++)
    {
        accm *= nums[right];
        while(left <= right && accm >= k)
        {
            accm /= nums[left];
            left++;
        }
        count += right - left + 1; // 因为左边界是紧致的, 所以每个符合条件的子数组都是被考虑进去的了, 不会漏掉
    }
    return count;
}

// 大概想一下就知道代码应该是那种前缀和或者滑动窗口双指针那种形式

// 具体而言 双指针肯定是更合适的, 即控制一段区间每次叠加的时候都判断一下, 然后移动左边界到一个紧致的边界

// 因为每次都是从当前的紧致左边界开始移动到下一个值的, 因此当前的滑动窗口一定是最紧致的, 因此从左边界开始的逐个递增的左边界其实都是符合条件的子数组

// 这样一来每次移动只用看当前这段里有几个元素即可, 即每更新一次右边界, 就联动着更新左边界, 此时连带右边界的数组值的每个较小的左边界, 都是符合条件的子数组

// 感觉很经典的题目, 可以多写写
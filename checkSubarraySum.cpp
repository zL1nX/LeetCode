/*
给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 。

如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。

 

示例 1：

输入：nums = [23,2,4,6,7], k = 6
输出：true
解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
示例 2：

输入：nums = [23,2,6,4,7], k = 6
输出：true
解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
示例 3：

输入：nums = [23,2,6,4,7], k = 13
输出：false
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1
通过次数34,794提交次数148,569

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) 
{
    int n = nums.size(), remainder = 0;
    if(n < 2) // 记得子数组的条件是大于等于2
    {
        return false;
    }
    unordered_map<int, int> mp;
    mp[0] = -1; // 由于空前缀和的余数为0，因此置为-1
    for(int i = 0; i < n; i++)
    {
        remainder = (remainder + nums[i]) % k;
        if(mp.count(remainder))
        {
            int index = mp[remainder];
            if(i - index >= 2)
            {
                return true;
            }
        }
        else
        {
            mp[remainder] = i;
        } 
    }
    return false;
}

// 好诡异的一道题，但有一个点还挺神奇的

// 就是把前缀和倍数转化成判断每个数的余数是否相同

// 因为如果前缀和能整除某个数的话，那么前缀和端点的两个数也必定对这个数的余数相同

// 那么就可以结合哈希表，存每个前缀和位置的余数，然后判断相同余数间的距离是否大于等于2即可
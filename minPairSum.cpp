/*
一个数对 (a,b) 的 数对和 等于 a + b 。最大数对和 是一个数对数组中最大的 数对和 。

比方说，如果我们有数对 (1,5) ，(2,3) 和 (4,4)，最大数对和 为 max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8 。
给你一个长度为 偶数 n 的数组 nums ，请你将 nums 中的元素分成 n / 2 个数对，使得：

nums 中每个元素 恰好 在 一个 数对中，且
最大数对和 的值 最小 。
请你在最优数对划分的方案下，返回最小的 最大数对和 。

 

示例 1：

输入：nums = [3,5,2,3]
输出：7
解释：数组中的元素可以分为数对 (3,3) 和 (5,2) 。
最大数对和为 max(3+3, 5+2) = max(6, 7) = 7 。
示例 2：

输入：nums = [3,5,4,2,4,6]
输出：8
解释：数组中的元素可以分为数对 (3,5)，(4,4) 和 (6,2) 。
最大数对和为 max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8 。
 

提示：

n == nums.length
2 <= n <= 105
n 是 偶数 。
1 <= nums[i] <= 105
通过次数8,782提交次数10,495


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int minPairSum(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    int maxn = 0, n= nums.size();
    for(int i = 0; i < n / 2; i++)
    {
        maxn = max(nums[i] + nums[n - i - 1], maxn);
    }
    return maxn;
}

// 淦 虽然直觉上感觉没问题，但这就过了？

// 由于要找最小的最大数对，那么可以反面考虑，如果找最大的呢？，那必然是两个最大的数放一起

// 因为最小的就是，让那些大数不能加到一起，换句话说就是让更大数和更小数搭配组合，让数对的和变得更加均匀；不然的话，一旦有更大数没有更小数去制约它，它能形成的数对就会非常大

// 因此，代码上就是先排序，然后首尾相加，然后不断比较累加和
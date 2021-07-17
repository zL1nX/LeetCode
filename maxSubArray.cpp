/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

 

通过次数169,869提交次数281,849


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int n = nums.size(), maxn = nums[0];
    vector<int> dp(n);
    dp[0] = nums[0]; // 初始状态是nums0不是0
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 因为每步都是i，所以不妨用pre表示dp[i]，这样连dp数组也不用了
        maxn = max(maxn, dp[i]);
    }
    return maxn;
}

// 淦 原本以为要前缀和，结果看了半天不是特定长度的子数组

// 怎么老是你DP，dp[i]表示长度为i的数组里的最大子数组和，那么对于每个nums[i]就是选或不选

// 一路选一个最大的出来，然后用maxn来更新

// 感觉像面试题会写的
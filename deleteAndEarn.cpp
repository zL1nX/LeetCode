/*
给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

 

示例 1：

输入：nums = [3,4,2]
输出：6
解释：
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。
示例 2：

输入：nums = [2,2,3,3,3,4]
输出：9
解释：
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
 

提示：

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
通过次数14,283提交次数25,511

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-and-earn
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int rob(vector<int> SumTimes)
{
    int n = SumTimes.size();
    if(n == 0) return 0;
    if(n == 1) return SumTimes[0];
    int preVal = SumTimes[0], currVal = max(SumTimes[0], SumTimes[1]);
    for(int i = 2; i < n; i++)
    {
        int temp = currVal;
        currVal = max(currVal, preVal + SumTimes[i]);
        preVal = temp;
    }
    return preVal;
}

int rob_dp(vector<int> SumTimes)
{
    int n = SumTimes.size();
    if(n == 0) return 0;
    if(n == 1) return SumTimes[0];
    vector<int> dp(n, 0);
    dp[0] = SumTimes[0];
    dp[1] = max(dp[0], SumTimes[1]);
    for(int i = 2; i < n; i ++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + SumTimes[i]);
    }
    return dp[n - 1];
}

int deleteAndEarn(vector<int>& nums) 
{
    int maxVal = nums[0];
    for(int n : nums)
    {
        maxVal = max(maxVal, n); // 确定dp数组大小
    }
    vector<int> SumTimes(maxVal + 1);
    for(int n : nums)
    {
        SumTimes[n] += n; // 若有c个值为x，则x对应的点数是c * x
    }
    int results = rob_dp(SumTimes); // 直接打家劫舍的代码
    return results;
}

// 转化思路很巧妙，首先明确要选x的话，肯定是选择所有的x，这样能使点数最大

// 然后在删除时，只有x本身会被算入点数，与x相邻的元素就会被删除

// 那么，题目其实相当于，选中若干个值，每选中一个值，其相邻值就不能选择，给出最大的累加

// 这样一来，题意与打家劫舍那道题是一样的
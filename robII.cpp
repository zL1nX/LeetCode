/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [1,2,3]
输出：3
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 1000
通过次数278,246提交次数633,548

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int robII(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 1) return nums[0]; // 边界情况
    return max(robIdp(nums, 0, n - 2), robIdp(nums, 1, n - 1));
}

int robIdp(vector<int>& nums, int start, int end)
{
    vector<int> dp(nums.size() + 2, 0);
    for(int i = end; i >= start; i--)
    {
        dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    }
    return dp[start];
}

// 213. 打家劫舍 II

// 由于首尾的房子只能抢一个, 所以对原问题进行下转化, 就是要么只从第二个开始抢到最后一个, 要么只从第一个抢到倒数第二个

// 剩下的事情由第一题的代码复用即可
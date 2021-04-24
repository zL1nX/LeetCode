/*
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

 

示例 1：

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
示例 2：

输入：nums = [9], target = 3
输出：0
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 1000
nums 中的所有元素 互不相同
1 <= target <= 1000
 

进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？

通过次数29,059提交次数64,200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) 
{
    int n = nums.size();
    // dp[i] 表示累加元素为i时的方案数
    vector<long long> dp(target + 1);
    dp[0] = 1; // 因为nums均为正数，如果所有元素为0，说明没选任何元素，那么这也算一种
    for(int i = 1; i <= target; i++) // 考虑所有小于等于target的元素
    {
        for(int num : nums) //当dp[i]成型时，最后的那个num，一定是num <= i的元素
        {
            if(i >= num && dp[i - num] < INT_MAX) //此时，num + dp[i - num] 就是dp[i]的结果
            { // 由于所有小于等于i的元素num都有可能组成，所以都要考虑
                dp[i] += dp[i - num]; //递推
            }
        }
    }
    return dp[target];
}
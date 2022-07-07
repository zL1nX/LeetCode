/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
通过次数291,128提交次数560,585

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) 
{
    int sum = 0;
    for(int& n : nums)
    {
        sum += n;
    }
    if(sum % 2) return false;
    int n = nums.size(), cap = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(cap + 1, false));
    for(int k = 0; k <= n; k++)
    {
        dp[k][0] = true; //
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= cap; j++)
        {
            if(j - nums[i - 1] < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][cap];
}

// 在进行选择的时候, 首先要判断当前背包里的容量是否够, 也就是边界问题

// 之后在转移时, 因为dp定义中的值是布尔, 所以选或者不选这个进背包, 取决于两种情况对应的上一个状态

// 不论上一个状态哪个是true, 那么当前这个状态一定也可以成为true

// 如果上两个状态都成了false, 那么当前这个状态一定是false. 这个转移的机制和原来的序列dp有些不一样
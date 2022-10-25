/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。

 

示例 1：
输入：nums = [3,1,5,8]
输出：167
解释：
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
示例 2：

输入：nums = [1,5]
输出：10
 

提示：

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
通过次数90,739提交次数130,112

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> coins(n + 2, 1);
    for(int i = 1; i <= n; i++)
    {
        coins[i] = nums[i - 1];
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for(int i = n; i >= 0; i--) // 不是n+1处开始遍历
    {
        for(int j = i + 1; j < n + 2; j++) // 要从i+1处开始
        {
            for(int k = i + 1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + coins[i] * coins[k] * coins[j]);
            }
        }
    }
    return dp[0][n + 1];
}

// 312-戳气球

// dp的定义非常神奇, 非常巧妙, 将戳气球的这个过程和状态转移有机统一到了一起

// 在明确了dp定义后, dp的状态转移也就自然出来了

// 同时, 要注意dp重要的是, 遍历时子问题需要先被解决, 才能进行解决当前问题

// 因此遍历时, 可以根据base case和最终状态画个图, 发现需要行从下往上遍历, 列从左往右遍历
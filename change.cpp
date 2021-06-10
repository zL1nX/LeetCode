/*
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:

输入: amount = 10, coins = [10] 
输出: 1
 

注意:

你可以假设：

0 <= amount (总金额) <= 5000
1 <= coin (硬币面额) <= 5000
硬币种类不超过 500 种
结果符合 32 位符号整数
通过次数63,100提交次数104,231

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) 
{
    int n = coins.size();
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        int cash = coins[i - 1];
        for(int j = 0; j <= amount; j++)
        {
            dp[i][j] = dp[i - 1][j]; // 不选这个硬币
            if(j >= cash)
            {
                dp[i][j] += dp[i][j - cash]; // 能选 可以不选；这里不是i-1是因为可以重复选
            }
        }
    }
    return dp[n][amount];
}

int change(int amount, vector<int>& coins)
{
    int n = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 1; 
    for(int coin : coins)
    {
        for(int i = coin; i <= amount; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

// 完全背包问题
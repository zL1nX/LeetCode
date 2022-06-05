/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
 

提示：

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
通过次数452,069提交次数990,304

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++)
    {
        for(int& coin : coins)
        {
            if(i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

// 经典的动规问题, 多注意这里面的子问题是什么, 以及拿到子问题的解之后, 如何解决当前问题

// 当能满足子问题的答案, 子问题加一个硬币就应该是当前这个问题的结果

// 重点还是要明确dp的含义, 而且其实这种思想是和递归很想的, 也是和二叉树的后序遍历很像

// 拿到子问题的解, 当前问题该怎么办呢
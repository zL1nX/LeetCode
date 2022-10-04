/*
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
示例 2:

输入: prices = [1]
输出: 0
 

提示：

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0; dp[0][1] = -prices[0];
    for(int i = 1; i < n; i++)
    {
        if(i - 2 == -1)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]); // base case同步变化
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]); // 需要隔一天
    }
    return dp[n - 1][0];
}

// 309-最佳买卖股票时机含冷冻期

// 由于冷静期的存在，在买的时候的状态，i-1是等于i-2的，相当于i-2购入后，i-1这个状态啥也没干，再转移到i这个状态

// 所以可以直接从i-2这个状态过来，同时也要相应地修改base case

// 与II相比，就是多了个冷静期导致买入时的状态i其实本质上是从i-2过来的 （但i-2是怎么来的那就无所谓了，这也是dp的意义所在）
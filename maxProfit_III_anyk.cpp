/*
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 

提示：

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int maxProfit_freek(vector<int>& prices) 
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0; dp[0][1] = -prices[0]; // 相同的base case
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 这里是不用省略dp[i - 1][0]的, 因为
    }
    return dp[n - 1][0];
}


int maxProfit(int k, vector<int>& prices) 
{
    int n = prices.size();
    if(k * 2 > n) // 说明当前的天数相对于交易次数而言很少，即就算当前每天都交易，也用不完这些交易次数
    {
        return maxProfit_freek(prices); // 那就相当于k无穷，直接复用原来的代码
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    for(int i = 0; i < n;i ++) // 其实有没有这块都问题不大，因为不会用到k-1 1 这一系列状态
    {
        dp[i][0][0] = 0;
        dp[i][0][1] = INT_MIN;
    }
    for(int c = 0; c <= k; c++) // base case
    {
        dp[0][c][0] = 0;
        dp[0][c][1] = -prices[0];
    }
    for(int i = 1; i < n; i++)
    {
        for(int c = k; c >= 1; c--)
        {
            dp[i][c][0] = max(dp[i - 1][c][0], dp[i - 1][c][1] + prices[i]);
            dp[i][c][1] = max(dp[i - 1][c][1], dp[i - 1][c - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][k][0];
}

// 其实就是相当于把原来的代码的k换一下，但是三维dp这里就会遇到溢出的问题

// 所以需要复用下原来的代码，别的都一切正常

// 188-买卖股票的最佳时机 IV
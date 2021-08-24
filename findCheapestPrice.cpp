/*
有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 toi 抵达 pricei。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。

 

示例 1：

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释: 
城市航班图如下


从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
示例 2：

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
输出: 500
解释: 
城市航班图如下


从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
 

提示：

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
航班没有重复，且不存在自环
0 <= src, dst, k < n
src != dst
通过次数20,660提交次数57,632

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
    int maxn = 10000 * 101 + 1;
    vector<vector<int>> dp(k + 2, vector<int>(n, maxn));
    dp[0][src] = 0;
    for(int t = 1; t <= k + 1; t++)
    {
        for(auto& flight : flights)
        {
            int from = flight[0], to = flight[1], price = flight[2];
            dp[t][to] = min(dp[t][to], dp[t - 1][from] + price);
        }
    }
    int res = maxn;
    for(int i = 0; i <= k; i++)
    {
        res = min(res, dp[i][dst]);
    }
    return res == maxn ? -1 : res;
}

// dp[t][j] 表示经过「t次航班」到达目的地j所需的最小价格，注意到题目是k次中转，那么实际上就是t+1架航班

// 转移的话，只能由上一个目的地跑过来，没有别的路径了，因此转移方程就只有一种

// 最后查看dp[i][dst]，其中i <= k + 1的最小值
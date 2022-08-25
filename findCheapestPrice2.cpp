/*
有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。

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
通过次数57,082提交次数145,641

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;



int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
    int res = INT_MAX, mmax = 1e6;
    vector<vector<int>> dp(k + 2, vector<int>(n, mmax)); // 为什么不用INT_MAX
    dp[0][src] = 0;
    for(int i = 1; i <= k + 1; i++) // 在k步之内, 遍历每种可能的情况
    {
        for(vector<int>& flight : flights)
        {
            int from = flight[0], to = flight[1], weight = flight[2];
            dp[i][to] = min(dp[i][to], dp[i - 1][from] + weight); // 在当前步数下, 看从哪个航班在上一步转移过来消耗最少
        }
    }
    for(int i = 1; i <= k + 1; i++)
    {
        res = min(res, dp[i][dst]); // 从所有可能的结果中选一个
    }
    return res == mmax ? -1 : res; // 注意初始值

}


// 787- K 站中转内最便宜的航班
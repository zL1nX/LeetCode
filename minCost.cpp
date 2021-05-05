/*
在一个小城市里，有 m 个房子排成一排，你需要给每个房子涂上 n 种颜色之一（颜色编号为 1 到 n ）。有的房子去年夏天已经涂过颜色了，所以这些房子不需要被重新涂色。

我们将连续相同颜色尽可能多的房子称为一个街区。（比方说 houses = [1,2,2,3,3,2,1,1] ，它包含 5 个街区  [{1}, {2,2}, {3,3}, {2}, {1,1}] 。）

给你一个数组 houses ，一个 m * n 的矩阵 cost 和一个整数 target ，其中：

houses[i]：是第 i 个房子的颜色，0 表示这个房子还没有被涂色。
cost[i][j]：是将第 i 个房子涂成颜色 j+1 的花费。
请你返回房子涂色方案的最小总花费，使得每个房子都被涂色后，恰好组成 target 个街区。如果没有可用的涂色方案，请返回 -1 。

 

示例 1：

输入：houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
输出：9
解释：房子涂色方案为 [1,2,2,1,1]
此方案包含 target = 3 个街区，分别是 [{1}, {2,2}, {1,1}]。
涂色的总花费为 (1 + 1 + 1 + 1 + 5) = 9。
示例 2：

输入：houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
输出：11
解释：有的房子已经被涂色了，在此基础上涂色方案为 [2,2,1,2,2]
此方案包含 target = 3 个街区，分别是 [{2,2}, {1}, {2,2}]。
给第一个和最后一个房子涂色的花费为 (10 + 1) = 11。
示例 3：

输入：houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
输出：5
示例 4：

输入：houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
输出：-1
解释：房子已经被涂色并组成了 4 个街区，分别是 [{3},{1},{2},{3}] ，无法形成 target = 3 个街区。
 

提示：

m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 10^4
通过次数13,399提交次数19,695

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-house-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

const int INF = 0x3F3F3F3F;

int dp[105][25][105];

int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
{
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j][0] = INF; // 
        }
    }

    for(int i = 1; i <= m; i ++)
    {
        int house_color = houses[i - 1];
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= target; k++)
            {
                if( k > i )
                {
                    dp[i][j][k] = INF; //
                    continue;
                }

                if(house_color != 0) //
                {
                    if(house_color == j) //
                    {
                        int curr_cost = INF; // 
                        for(int p = 1; p <= n; p++) 
                        {
                            if(p != j) //
                            {
                                curr_cost = min(curr_cost, dp[i - 1][p][k - 1]);
                            }
                        }
        
                        dp[i][j][k] = min(curr_cost, dp[i - 1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k] = INF;
                    }
                    
                }
                else //
                {
                    int house_cost = cost[i - 1][j - 1];
                    int curr_cost = INF;
                    for(int p = 1; p <= n; p ++)
                    {
                        if(p != j)
                        {
                            curr_cost = min(curr_cost, dp[i - 1][p][k - 1] + house_cost);
                        }
                    }
                    dp[i][j][k] = min(curr_cost, dp[i - 1][j][k] + house_cost);
                }
            }    
        }
    }

    int result = INF;
    for(int i = 1; i <= n; i++)
    {
        result = min(result, dp[m][i][target]);
    }
    return result == INF ? -1 : result;
}

/*
const int INF = 0x3f3f3f3f;  //INF + INF 不会爆int
int f[105][25][105];

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //无效的状态
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                f[i][j][0] = INF;
            }
        }

        for(int i = 1; i <= m; i++){
            int color = houses[i - 1];
            for(int j = 1; j <= n;j++){
                for(int k = 1; k <= target; k++){
                    if(k > i) {
                        f[i][j][k] = INF;
                        continue;
                    }
                    //第i个房间已经上色
                    if(color != 0){
                        if(j == color){
                            int cur = INF;
                            //与上一个房间颜色不同
                            for(int p = 1; p <= n; p++){
                                if(p != j){ //颜色不同
                                    cur = min(cur,f[i - 1][p][k - 1]);
                                }
                            }
                            //与上一个房间颜色相同
                            f[i][j][k] = min(cur,f[i - 1][j][k]);
                        }
                        else f[i][j][k] = INF; //其他为无效状态
                    }    
                    else{ //第i个房间未上色
                        int u = cost[i - 1][j - 1];
                        //考虑第i个房间是否形成新的分区
                        //与上一个房间颜色不同，形成新分区
                        int cur = INF;
                        for(int p = 1; p <= n; p++){
                            if(p != j) cur = min(cur,f[i - 1][p][k - 1] + u);
                        }
                        //与上一个房间颜色相同，不形成新的分区
                        f[i][j][k] = min(cur,f[i - 1][j][k] + u);
                    }   
                }
            }
        }
        
        int ans = INF;
        for(int i = 1; i <= n; i++){
            ans = min(ans,f[m][i][target]);
        }
        return ans == INF ? -1 : ans;
    }
};

作者：AC_OIer
链接：https://leetcode-cn.com/problems/paint-house-iii/solution/gong-shui-san-xie-san-wei-dong-tai-gui-h-ud7m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
/*
给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 109 + 7 取余 后的结果。

 

示例 1：


输入：m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
输出：6
示例 2：


输入：m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
输出：12
 

提示：

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/out-of-boundary-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

bool isIn(int m, int n, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n ;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
{
    vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
    int moves[4][2] = {{0,1}, {0,-1},{1,0}, {-1,0}};
    dp[0][startRow][startColumn] = 1;
    int res = 0;
    for(int i = 0; i < maxMove; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < n; k++)
            {
                int nums = dp[i][j][k];
                if(nums > 0)
                {
                    for(auto& move: moves)
                    {
                        int nextj = j + move[0], nextk = k + move[1];
                        if(isIn(m,n,nextj, nextk))
                        {
                            dp[i + 1][nextj][nextk] = (dp[i + 1][nextj][nextk] + nums) % mod;
                        }
                        else
                        {
                            res = (res + nums) % mod;
                        }
                    }
                }
            }
        }
    }
    return res;
}

// dp[i][j][k]表示经过i次move后，在位置jk的出界路径数
// 转移的时候要是i+1还没出界，那就直接加上，要是出界了，就直接加到结果上
// 关键在于dp的定义，以及怎么去完成遍历（没想到这题的复杂度会这么高）
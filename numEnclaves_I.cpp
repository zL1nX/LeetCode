/*
给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。

 

示例 1：


输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
输出：3
解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
示例 2：


输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
输出：0
解释：所有 1 都在边界上或可以到达边界。
*/

#include <vector>
using namespace std;

int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


int numEnclaves(vector<vector<int>>& grid) 
{
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    for(int i = 0; i < m; i++)
    {
        dfs(grid, i, 0);
        dfs(grid, i, n - 1);
    }
    for(int j = 0; j < n; j++)
    {
        dfs(grid, 0, j);
        dfs(grid, m - 1, j);
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1)
            {
                res += 1; // 不用dfs了, 因为现在剩下的陆地都是可以算的飞地, 直接数一数有多少个单元格即可
            }
        }
    }
    return res;
}

void dfs(vector<vector<int>>& grid, int x, int y)
{
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
    {
        return;
    } // 先边界检查, 再考虑后面的事
    if(grid[x][y] == 0)
    {
        return;
    }
    grid[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        dfs(grid, x + d[i][0], y + d[i][1]);
    }
}

// 1020. 飞地的数量
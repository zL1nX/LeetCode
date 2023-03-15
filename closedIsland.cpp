/*
二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。

请返回 封闭岛屿 的数目。

 

示例 1：



输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
输出：2
解释：
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
示例 2：



输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
输出：1
示例 3：

输入：grid = [[1,1,1,1,1,1,1],
             [1,0,0,0,0,0,1],
             [1,0,1,1,1,0,1],
             [1,0,1,0,1,0,1],
             [1,0,1,1,1,0,1],
             [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
输出：2
 

提示：

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

#include <vector>
using namespace std;

int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


int closedIsland(vector<vector<int>>& grid) 
{
    int m = grid.size(), n = grid[0].size(), count = 0;
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

    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 0)
            {
                count += 1;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

void dfs(vector<vector<int>>& grid, int x, int y)
{
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
    {
        return;
    }
    if(grid[x][y] == 1)
    {
        return;
    }
    grid[x][y] = 1;
    for(int i = 0; i < 4; i ++)
    {
        dfs(grid, x + d[i][0], y + d[i][1]);
    }
}

//1254. 统计封闭岛屿的数目

// 注意海水跟陆地的标记反了
/*
给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向 （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。

如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。

请你返回 grid2 中 子岛屿 的 数目 。

 

示例 1：


输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
输出：3
解释：如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
示例 2：


输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
输出：2 
解释：如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
 

提示：

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。
*/

#include <vector>
using namespace std;


int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
{
    int m = grid1.size(), n = grid1[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid2[i][j] == 1 && grid1[i][j] == 0) // 如果grid2中是陆地, 但是grid1中是海洋, 那这个岛屿肯定不是子岛屿
            {
                dfs(grid2, i, j); // 淹掉
            }
        }
    }

    int cnt = 0; // 剩下的岛屿就都是了
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid2[i][j] == 1)
            {
                cnt ++;
                dfs(grid2, i, j);
            }
        }
    }

    return cnt;
}

void dfs(vector<vector<int>>& grid, int x, int y)
{
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
    {
        return;
    }
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
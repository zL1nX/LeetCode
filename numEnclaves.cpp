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
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] 的值为 0 或 1
通过次数14,440提交次数24,992

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-enclaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(vector<vector<int>>& grid, int x, int y)
{
    // 要记得先判断是不是海洋和陆地，因为如果是海洋，那就肯定不用判断了
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
    {
        return;
    }
    // 这部分要写到循环里面的话，就会把不是陆地给置0
    grid[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        dfs(grid, x + dir[i][0], y + dir[i][1]);
    }
}

int numEnclaves(vector<vector<int>>& grid) 
{
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    // 先把边界上的岛屿给淹了，剩下还为1的，就是所谓的飞地
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
                res += 1;
            }
        }
    }
    return res;
}
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
*/


#include <vector>

using namespace std;

int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int numIslands(vector<vector<char>>& grid) 
{
    int count = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == '1')
            {
                count += 1;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

void dfs(vector<vector<char>>& grid, int x, int y)
{
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
    {
        return;
    }
    if(grid[x][y] == '0')
    {
        return;
    }
    grid[x][y] = '0';
    for(int i = 0; i < 4; i ++)
    {
        dfs(grid, x + d[i][0], y + d[i][1]);
    }
}

// 200. 岛屿数量
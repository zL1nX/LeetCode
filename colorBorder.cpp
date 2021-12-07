/*
给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color 。网格中的每个值表示该位置处的网格块的颜色。

当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一 连通分量 。

连通分量的边界 是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。

请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色，并返回最终的网格 grid 。

 

示例 1：

输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
输出：[[3,3],[3,2]]
示例 2：

输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
输出：[[1,3,3],[2,3,3]]
示例 3：

输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
输出：[[2,2,2],[2,1,2],[2,2,2]]
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j], color <= 1000
0 <= row < m
0 <= col < n
 

通过次数7,413提交次数15,109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coloring-a-border
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;


int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>>& border, int row, int col, int target)
{
    bool isBorder = false;
    for(int i = 0; i < 4; i++)
    {
        int x = row + directions[i][0], y = col + directions[i][1];
        if(x < 0 || x > grid.size() - 1 || y < 0 || y > grid[0].size() - 1 || grid[x][y] != target )
        {
            isBorder = true;
        }
        else if(visited[x][y] == 0)
        {
            visited[x][y] = 1;
            dfs(grid, visited, border, x, y, target);
        }
    }
    // 对当前点的周围点都处理过后，只要有一个方向暴露了当前点其实是满足边界点的，那么就能确定当前点是边界点
    if(isBorder)
    {
        border.emplace_back(row, col);
    }
}    

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) 
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<pair<int, int>> border;
    int target = grid[row][col];
    visited[row][col] = 1;
    dfs(grid, visited, border, row, col, target);
    for(auto& [x, y] : border)
    {
        grid[x][y] = color;
    }
    return grid;
}

// dfs的整体思路其实很好理解，但要明确边界的条件：整个grid的边界，或者是色块不相同的点

// 那么这样一来，如果对于某个点，其下一步的四个方向点，若超出了边界，或者是颜色不相同，那么当前这个点就算是一个border

// 另外的，上面这个条件的另外的if即为连续的边界内的色块点，这样一来只要没有visited过，就继续dfs

// 这个题挺有意思的，可以多写两遍
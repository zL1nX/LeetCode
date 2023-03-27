/*
给定一个非空01二维数组表示的网格，一个岛屿由四连通（上、下、左、右四个方向）的 1 组成，你可以认为网格的四周被海水包围。

请你计算这个网格中共有多少个形状不同的岛屿。
两个岛屿被认为是相同的，当且仅当一个岛屿可以通过平移变换（不可以旋转、翻转）和另一个岛屿重合。
*/


#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int l[4] = {1, 2, 3, 4};
unordered_set<string> rec;


int numDistinctIslands(vector<vector<int>>& grid)
{
    rec.clear();
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                string curr = "";
                dfs(grid, i, j, curr, 666);
                rec.insert(curr);
            }
            
        }
    }
    return rec.size();
}

void dfs(vector<vector<int>>& grid, int x, int y, string& curr, int dir)
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
    curr += to_string(dir);

    for(int i = 0; i < 4; i++)
    {
        dfs(grid, x + d[i][0], y + d[i][1], curr, l[i]);
    }

    curr += to_string(-dir); // 退出递归返回上一层时也需要添加
}

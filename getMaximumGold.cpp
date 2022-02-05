/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
 

示例 1：

输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
示例 2：

输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
 

提示：

1 <= grid.length, grid[i].length <= 15
0 <= grid[i][j] <= 100
最多 25 个单元格中有黄金。
通过次数16,082提交次数24,668

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-maximum-gold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void backtrack(vector<vector<int>>& grid, int& maxn, int mined, int i, int j, int m, int n)
{
    mined += grid[i][j];
    maxn = max(maxn, mined);
    int tmp = grid[i][j];
    grid[i][j] = 0;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dir[k][0], y = j + dir[k][1];
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
        {
            backtrack(grid, maxn, mined, x, y, m, n);
        }
    }
    grid[i][j] = tmp;
}

int getMaximumGold(vector<vector<int>>& grid) 
{
    int m = grid.size(), n = grid[0].size();
    int maxn = 0;
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] != 0)
            {
                backtrack(grid, maxn, 0, i, j, m, n);
            }
        }
    }
    return maxn;
}

// 典型的DFS回溯题，不过如果不用DFS的话可以直接用BFS

// DFS+回溯主要就是注意那个backtrack函数怎么写，别的都是模板性质的题

// 这种在一个网格上求某一条路径什么的最大值，还是要有用回溯来求的意识
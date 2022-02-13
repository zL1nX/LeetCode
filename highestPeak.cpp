/*
给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。

 

示例 1：



输入：isWater = [[0,1],[0,0]]
输出：[[1,0],[2,1]]
解释：上图展示了给各个格子安排的高度。
蓝色格子是水域格，绿色格子是陆地格。
示例 2：



输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
输出：[[1,1,0],[0,1,1],[1,2,2]]
解释：所有安排方案中，最高可行高度为 2 。
任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
 

提示：

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] 要么是 0 ，要么是 1 。
至少有 1 个水域格子。
通过次数5,661提交次数9,548

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-of-highest-peak
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
{
    int m = isWater.size(), n = isWater[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> height(m, vector<int>(n, -1));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(isWater[i][j])
            {
                height[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty())
    {
        auto [x, y] = q.front();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0], ny = y + direction[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1)
            {
                height[nx][ny] = height[x][y] + 1;
                q.push({nx, ny});
            }
        }
        q.pop();

    }
    return height;
}

// 题目一看就是要整个BFS，但是下面说什么多源BFS还愣了下，但是结合题目中水域格子和其他格子的高度关系

// 这题目里面的BFS就是最直接的从水域作为起点的BFS，因为反正每个格子之间也是高度差1，直接每次都递增高度即可

// 题解里面把传统的visited和结果数组合并成了一个，这个要更好一些

// 除此之外就是一个平平无奇的BFS
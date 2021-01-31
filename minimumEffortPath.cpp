/*
你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

 

示例 1：



输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
示例 2：



输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
示例 3：


输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。
 

提示：

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class UF
{
public:
    unordered_map<int, int> father;
    unordered_map<int, int> rank_num;
    int num_count;
public:
    UF(int n)
    {
        for(int i = 0; i <= n; i++)
        {
            father[i] = i; 
            rank_num[i] = 1;
        }
        num_count = n;
    }

    int Find(int x)
    {
        if(x != father[x])
        {
            father[x] = Find(father[x]);
        }
        return father[x];
    }

    void Union(int x, int y)
    {
        int fx = Find(x), fy = Find(y);
        if(fx == fy)
        {
            return;
        }
        if(rank_num[x] < rank_num[y])
        {
            swap(x, y);
        }
        father[fy] = fx;
        rank_num[fx] += rank_num[fy];
        num_count --;
    }
};

int minimumEffortPath(vector<vector<int>>& heights) 
{
    int m = heights.size(), n = heights[0].size();
    UF uf(m * n);
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int id = i * n + j;
            if(i > 0)
            {
                edges.emplace_back(id - n, id, abs(heights[i - 1][j] - heights[i][j]));
            }
            if(j > 0)
            {
                edges.emplace_back(id - 1, id, abs(heights[i][j - 1] - heights[i][j]));
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
        auto& [x1, y1, v1] = a;
        auto& [x2, y2, v2] = b;
        return v1 < v2;
    });
    int ans = 0;
    for(const auto& [x, y, dis] : edges)
    {
        uf.Union(x, y);
        if(uf.Find(0) == uf.Find(m * n - 1))
        {
            ans = dis;
            break;
        }
    }
    return ans;
}

// 这题先将类似于dp的问题转化为图论，将是否有路径转化为连通问题

// 转化为连通问题后，就可以用并查集判断连通性

// 将格点之间的权值设为边，并且排序，之后向图中每加入一条边，就判断左上与右下是否连通，因为加入的是当前最短边，所以当格点连通时一定是最小高度差
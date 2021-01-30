/*
在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。

现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。

你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？

 

示例 1:

输入: [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。

等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
示例2:

输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输出: 16
解释:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
 

提示:

2 <= N <= 50.
grid[i][j] 是 [0, ..., N*N - 1] 的排列。
通过次数8,205提交次数15,826

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swim-in-rising-water
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
        num_count = 1;
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

int swimInWater(vector<vector<int>>& grid) 
{
    int m = grid.size(), n = grid[0].size();
    UF uf(m * n);
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int id = i * n + j;
            if(i > 0)
            {
                edges.emplace_back(id - n, id, max(grid[i][j], grid[i - 1][j])); // 注意加入的不是权值，而是相邻格点的较大值，因为我们返回的当前路径中的最大值
            }
            if(j > 0)
            {
                edges.emplace_back(id - 1, id, max(grid[i][j], grid[i][j - 1]));
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

// 题目和游动时间无关，因为游动不耗时。题意是，当时刻为t时，使得这个二维网格上数值小于等于 t的部分存在一条左上到右下的路径连通，且t相对最小

// 所以连通集的构造是，存储着每个格点周围较大的那个格点，然后从小到大排序，每次加入并查集，如果左上和右下连通了，说明此时加入的格点t是具有较小的最大值


/*
给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

 

示例 1：



输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：

我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
示例 2：

输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
示例 3：

输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
示例 4：

输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
示例 5：

输入：points = [[0,0]]
输出：0
 

提示：

1 <= points.length <= 1000
-106 <= xi, yi <= 106
所有点 (xi, yi) 两两不同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> father, num;

int find(int x)
{
    if(x != father[x])
    {
        father[x] = find(father[x]);
    }
    return father[x];
}

bool Union(int x, int y)
{
    int fx = find(x), fy = find(y);
    if(fx == fy)
    {
        return false;
    }
    father[fx] = fy;
    num[fy] += num[fx];
    return true;
}

int distance(vector<int> x, vector<int> y)
{
    return abs(x[0] - y[0]) + abs(x[1] - y[1]);
}

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
};

int minCostConnectPoints(vector<vector<int>>& points) 
{
    vector<Edge> edges;

    // 先生成所有边，即完全图
    for(int i = 0;i < points.size(); i++)
    {
        for(int j = i + 1 ; j < points.size(); j++)
        {
            edges.emplace_back(distance(points[i], points[j]), i, j);
        }
    }

    //初始化并查集
    for(int i = 0; i < points.size(); i ++)
    {
        father[i] = i;
        num[i] = 1;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.len < b.len;
    });
    int res = 0, cnt = 1; // 至少有一个边可以加进来
    for(auto& [len, x, y] : edges)
    {
        if(Union(x, y)) // 判断这条边对应的两个点是否是一个连通块
        {
            res += len;
            cnt ++;
            if(cnt == points.size()) // 最小生成树，几个点就有几条边
            {
                break;
            }
        }
    }
    return res;
}
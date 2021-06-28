/*
给你一个数组 routes ，表示一系列公交线路，其中每个 routes[i] 表示一条公交线路，第 i 辆公交车将会在上面循环行驶。

例如，路线 routes[0] = [1, 5, 7] 表示第 0 辆公交车会一直按序列 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... 这样的车站路线行驶。
现在从 source 车站出发（初始时不在公交车上），要前往 target 车站。 期间仅可乘坐公交车。

求出 最少乘坐的公交车数量 。如果不可能到达终点车站，返回 -1 。

 

示例 1：

输入：routes = [[1,2,7],[3,6,7]], source = 1, target = 6
输出：2
解释：最优策略是先乘坐第一辆公交车到达车站 7 , 然后换乘第二辆公交车到车站 6 。 
示例 2：

输入：routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
输出：-1
 

提示：

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
routes[i] 中的所有值 互不相同
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bus-routes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
{
    if(source == target)
    {
        return 0;
    }
    int n = routes.size();
    vector<vector<bool>> isconnected(n, vector<bool>(n));
    unordered_map<int, vector<int>> containedRoutes;
    for(int i = 0;i < n; i ++)
    {
        for(int& station : routes[i])
        {
            for(auto& reach : containedRoutes[station]) // 对于这个站点包含的线路而言
            {
                isconnected[i][reach] = isconnected[reach][i] = true;
                // 当前的线路肯定能和这些线路相连
            }
            containedRoutes[station].push_back(i); // 当前站点肯定包含在当前线路中
        }
    }
    // 上面做了两件事，将线路按站点进行分类；并记载线路之间的连通情况（有公共车站就能连通）

    queue<int> q;
    vector<int> distance(n, -1); // 初始都置为-1
    for(auto& route: containedRoutes[source])
    {
        q.push(route); // 搜索起点
        distance[route] = 1; // 起点到自己这个线路都设为1
    }

    while(!q.empty())
    {
        auto start = q.front();
        q.pop();
        for(int des = 0; des < n; des ++)
        {
            if(isconnected[start][des] && distance[des] == -1) // 两条线路间连通，且后面那个线路咱还没搜过
            {
                distance[des] = distance[start] + 1; //就能换乘过去，距离增加
                q.push(des);//继续BFS
            }
        }
    }

    int res = INT_MAX;
    for(auto& route : containedRoutes[target])
    {
        if(distance[route] != -1)
        {
            res = min(res, distance[route]); //此时的距离就代表换乘次数
        }
    }
    return res == INT_MAX ? -1 : res;
}


// 麻了，核心其实就是一条线路就是一个整体，从source到target最短，其实就是看线路之间的最短距离

// 即，里面的核心对象其实是一个个线路，站点实际上是更上层的归类方法

// 问题其实就是，考察每个站点所包含的线路，看从source所属的这些线路开始，BFS查找到target线路距离的最小值

// 因此，查找的是线路，同时需要一个distance来记载线路之间的距离（也起到visited的作用）

// 而且，需要用一isconnected来记载线路之间是否连通（要不连通那就憋搜了）

// 这个问题的转换还是很妙的，而且最后只用看做了几次公交就行

// 我好菜啊
/*
存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。

给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。

返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。

 

示例 1：


输入：graph = [[1,2,3],[0],[0],[0]]
输出：4
解释：一种可能的路径为 [1,0,2,0,3]
示例 2：



输入：graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
输出：4
解释：一种可能的路径为 [0,1,4,2,3]
 

提示：

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] 不包含 i
如果 graph[a] 包含 b ，那么 graph[b] 也包含 a
输入的图总是连通图
通过次数6,655提交次数10,915


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;

int shortestPathLength(vector<vector<int>>& graph) 
{
    int n = graph.size();
    queue<tuple<int, int, int>> nodes; // node, state, dist
    vector<vector<int>> visited(n, vector<int>(1 << n)); // node, state
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        nodes.emplace(i, 1 << i, 0); // 从所有节点出发都试一试
        visited[i][1 << i] = true;
    }
    while(!nodes.empty()) // 开始BFS队列实现版本
    {
        auto [node, state, dist] = nodes.front();
        nodes.pop();
        if(state == (1 << n) - 1) // 所有节点都走了一遭，即都置为了1
        {
            res = dist;
            break;
        }
        for(int& neighbour : graph[node])
        {
            int currStat = state | 1 << neighbour; // 更新状态
            if(!visited[neighbour][currStat]) // 这个状态之前没经历过再继续
            {
                nodes.emplace(neighbour, currStat, dist + 1);
                visited[neighbour][currStat] = true;
            }
        }
    }
    return res;
    
    
}

// 状态的定义真的顶，而且要同时想到使用另外一个字段来进行状态压缩

// 虽然可以重复经过节点，但是第一次经过与第二次经过时 state是不一样的

// 这样使用BFS + 状态压缩就可以找到符合必要条件的结果，如果是广度优先的时候第一次搜到，那就是最短结果了（think again）
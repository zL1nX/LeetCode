/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

二维数组的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些节点，空就是没有下一个结点了。

译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a 。

 

示例 1：



输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
示例 2：



输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
示例 3：

输入：graph = [[1],[]]
输出：[[0,1]]
示例 4：

输入：graph = [[1,2,3],[2],[3],[]]
输出：[[0,1,2,3],[0,2,3],[0,3]]
示例 5：

输入：graph = [[1,3],[2],[3],[]]
输出：[[0,1,2,3],[0,3]]
 

提示：

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i（即，不存在自环）
graph[i] 中的所有元素 互不相同
保证输入为 有向无环图（DAG）
通过次数20,219提交次数26,543


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std; 

vector<vector<int>> paths;
vector<int> stack;

void dfs(vector<vector<int>> graph, int curr, int target)
{
    if(curr == target)
    {
        paths.push_back(stack); // 注意这里stack已经存了curr，此处只用存stack即可
        return;
    }
    for(int& neighbour : graph[curr]) // 开始搜索
    {
        stack.push_back(neighbour);
        dfs(graph, neighbour, target);
        stack.pop_back(); // 回溯
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
    stack.push_back(0);
    dfs(graph, 0, graph.size() - 1);
    return paths;
}

// dfs+回溯的模板题，需要记住
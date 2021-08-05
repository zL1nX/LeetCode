/*
在有向图中，以某个节点为起始节点，从该点出发，每一步沿着图中的一条有向边行走。如果到达的节点是终点（即它没有连出的有向边），则停止。

对于一个起始节点，如果从该节点出发，无论每一步选择沿哪条有向边行走，最后必然在有限步内到达终点，则将该起始节点称作是 安全 的。

返回一个由图中所有安全的起始节点组成的数组作为答案。答案数组中的元素应当按 升序 排列。

该有向图有 n 个节点，按 0 到 n - 1 编号，其中 n 是 graph 的节点数。图以下述形式给出：graph[i] 是编号 j 节点的一个列表，满足 (i, j) 是图的一条有向边。

 

示例 1：


输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
输出：[2,4,5,6]
解释：示意图如上。
示例 2：

输入：graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
输出：[4]
 

提示：

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
graph[i] 按严格递增顺序排列。
图中可能包含自环。
图中边的数目在范围 [1, 4 * 104] 内。
通过次数11,881提交次数22,926

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-eventual-safe-states
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;



vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
{
    //
    int n = graph.size();
    vector<int> state(n), res; // 0 for not visited, 1 for not safe, 2 for safe
    function<bool(int)> isSafe = [&](int loc)
    {
        if(state[loc] > 0) // visited
        {
            return state[loc] == 2; // return if safe
        }
        state[loc] = 1; // first visited
        for(int n : graph[loc]) // check every neighbour
        {
            if(!isSafe(n))
            {
                return false; // loc is in a circle
            }
        }
        state[loc] = 2; // then it is not in a circle;
        return true;
    };
    for(int i = 0; i < n; i++)
    {
        if(isSafe(i))
        {
            res.push_back(i);
        }
    }
    return res;
}

// 乍一看好像挺难？，理解思路之后其实还好

// 本质上就是dfs看有没有环，但可以用一个state数组来记录每个点的状态，从而进行剪枝

// 最后返回那些能一路为true的点
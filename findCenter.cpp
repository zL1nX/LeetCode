/*
有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。星型图有一个 中心 节点，并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。

给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。请你找出并返回 edges 所表示星型图的中心节点。

 

示例 1：


输入：edges = [[1,2],[2,3],[4,2]]
输出：2
解释：如上图所示，节点 2 与其他每个节点都相连，所以节点 2 是中心节点。
示例 2：

输入：edges = [[1,2],[5,1],[1,3],[1,4]]
输出：1
 

提示：

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
题目数据给出的 edges 表示一个有效的星型图

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-center-of-star-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

int findCenter(vector<vector<int>>& edges) 
{
    unordered_map<int, int> rec;
    for(auto& edge : edges)
    {
        rec[edge[0]]++;
        rec[edge[1]]++;
    }
    for(auto& it : rec)
    {
        if(it.second == edges.size())
        {
            return it.first;
        }
    }
    return -1;
}

// 淦 写完才发现其他结点之间都是没有边的

// 因此就可以直接判断前两条边的公共结点是谁，然后直接返回就行

// 我本以为是只有中心结点的边数为n，其他结点之间也可能会相连，但不会像中心结点一样这么多，所以用哈希表记录了一下进行判断

// 但发现题目给的条件里 整张图里其实只有中心结点会有超过1条边的存在，那就没啥好说直接判断就行了
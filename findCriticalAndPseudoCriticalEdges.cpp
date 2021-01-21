/*
给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。

 

示例 1：



输入：n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
输出：[[0,1],[2,3,4,5]]
解释：上图描述了给定图。
下图是所有的最小生成树。

注意到第 0 条边和第 1 条边出现在了所有最小生成树中，所以它们是关键边，我们将这两个下标作为输出的第一个列表。
边 2，3，4 和 5 是所有 MST 的剩余边，所以它们是伪关键边。我们将它们作为输出的第二个列表。
示例 2 ：



输入：n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
输出：[[],[0,1,2,3]]
解释：可以观察到 4 条边都有相同的权值，任选它们中的 3 条可以形成一棵 MST 。所以 4 条边都是伪关键边。
 

提示：

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti <= 1000
所有 (fromi, toi) 数对都是互不相同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <unordered_map>
using namespace std;
class UnionFind{
public:
    unordered_map<int, int> father;
    unordered_map<int, int> rank_num;
    int connected_num = 0;

public:
    UnionFind(int n)
    {
        //连通分量的数量
        connected_num = n;
        for(int i = 0; i < n; i++)
        {
            father[i] = i;
            rank_num[i] = 1;
        }
    }


    int Find(int x)
    {
        if(x != father[x])
        {
            father[x] = Find(father[x]);
        }
        return father[x];
    }

    bool Union(int x, int y)
    {
        int fx = Find(x), fy = Find(y);
        if(fx == fy)
        {
            return false;
        }
        father[fx] = fy;
        rank_num[fy] += rank_num[fy];
        --connected_num;
        return true;
    }
};


vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
{
    // 首先进行Kruskal算法，生成最小生成树，以获取最小标准权重value
    int m = edges.size();
    vector<vector<int>> res;


    for(int i = 0; i < m; i++)
    {
        edges[i].push_back(i); // 作为边的索引号
    }
    // 排序（Kruskal的第一步）
    sort(edges.begin(), edges.end(), [](const auto u, const auto v){
        return u[2] < v[2];
    });

    // 添加到图中以得到最小生成树，Kruskal的主要步骤
    UnionFind uf(n);
    int value = 0;
    for(int i = 0; i < m;i++)
    {
        if(uf.Union(edges[i][0], edges[i][1]))
        {
            value += edges[i][2];
        }
    }

    // 开始判断每条边是关键边，还是非关键边
    for(int i = 0; i < m; i++)
    {
        // 关键边：去掉这个边要么生成不了最小生成树，要么得到的value1比value大
        UnionFind u1(n);
        int value1 = 0;
        for(int j = 0; j < m; j++)
        {
            if(i != j && uf.Union(edges[j][0], edges[j][1]))
            {
                value1 += edges[j][2];
            }
        }
        if(uf.connected_num != 1 || (uf.connected_num == 1 && value1 > value)) // 分别对应：无法构成最小生成树 和 构成最小生成树但权值变大 两个条件
        {
            res[0].push_back(edges[i][3]);
            continue;
        }
        

        // 伪关键边：一定出现在某个最小生成树中，但不是出现在所有最小生成树里；因此考虑以这个边生成的最小生成树的权值value2与value的大小
        UnionFind u2(n);
        u2.Union(edges[i][0], edges[i][1]);
        int value2 = edges[i][2];

        for(int j = 0; j < m; j++)
        {
            if(i != j && u2.Union(edges[j][0], edges[j][1]))
            {
                value2 += edges[j][2];
            }
        }
        // 由于此时这条边肯定不是关键边，因此要是还能生成和value一样的最小生成树，就说明是伪关键边
        if(value2 == value)
        {
            res[1].push_back(edges[i][3]);
        }
    }
    return res;
}


/*
unordered_map<int, int> father, rank_num;
    int connected_num = 0;

    void Init(int n)
    {
        for(int i = 0; i < n; i++)
        {
            father[i] = i;
            rank_num[i] = 1;
        }
        connected_num = n;
    }

    int Find(int x)
    {
        if(x != father[x])
        {
            father[x] = Find(father[x]);
        }
        return father[x];
    }

    bool Union(int x, int y)
    {
        int fx = Find(x), fy = Find(y);
        if(fx == fy)
        {
            return false;
        }
        father[fx] = fy;
        rank_num[fy] += rank_num[fx];
        --connected_num;
        return true;

    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        vector<vector<int>> res(2);
        for(int i = 0; i < m; i++)
        {
            edges[i].push_back(i); // 作为边的索引号
        }
        // 排序（Kruskal的第一步）
        sort(edges.begin(), edges.end(), [](const auto u, const auto v){
            return u[2] < v[2];
        });

        // 添加到图中以得到最小生成树，Kruskal的主要步骤
        Init(n);
        int value = 0;
        for(int i = 0; i < m;i++)
        {
            if(Union(edges[i][0], edges[i][1]))
            {
                value += edges[i][2];
            }
        }

        // 开始判断每条边是关键边，还是非关键边
        for(int i = 0; i < m; i++)
        {
            // 关键边：去掉这个边要么生成不了最小生成树，要么得到的value1比value大
            Init(n);
            int value1 = 0;
            for(int j = 0; j < m; j++)
            {
                if(i != j && Union(edges[j][0], edges[j][1]))
                {
                    value1 += edges[j][2];
                }
            }
            if(connected_num != 1 || (connected_num == 1 && value1 > value)) // 分别对应：无法构成最小生成树 和 构成最小生成树但权值变大 两个条件
            {
                res[0].push_back(edges[i][3]);
                continue;
            }
            

            // 伪关键边：一定出现在某个最小生成树中，但不是出现在所有最小生成树里；因此考虑以这个边生成的最小生成树的权值value2与value的大小
            Init(n);
            Union(edges[i][0], edges[i][1]);
            int value2 = edges[i][2];

            for(int j = 0; j < m; j++)
            {
                if(i != j && Union(edges[j][0], edges[j][1]))
                {
                    value2 += edges[j][2];
                }
            }
            // 由于此时这条边肯定不是关键边，因此要是还能生成和value一样的最小生成树，就说明是伪关键边
            if(value2 == value)
            {
                res[1].push_back(edges[i][3]);
            }
        }
        return res;
    }
*/

// 注意并查集初始化时的尺寸
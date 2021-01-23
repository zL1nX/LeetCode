/*
用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。

网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1 。 

 

示例 1：



输入：n = 4, connections = [[0,1],[0,2],[1,2]]
输出：1
解释：拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
示例 2：



输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
输出：2
示例 3：

输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
输出：-1
解释：线缆数量不足。
示例 4：

输入：n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
输出：0
 

提示：

1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
没有重复的连接。
两台计算机不会通过多条线缆连接。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

int connected;
unordered_map<int, int> father, rank_num;

void Init(int n)
{
    for(int i = 0; i <= n; i ++)
    {
        father[i] = i;
        rank_num[i] = 1;
    }
    connected = n;
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
    father[fx] = fy;
    rank_num[fy] += rank_num[fx];
    --connected;
}


int makeConnected(int n, vector<vector<int>>& connections) 
{
    if(connections.size() < n - 1)
    {
        return -1;
    }
    Init(n);
    for(int i = 0; i < connections.size(); i++)
    {
        Union(connections[i][0], connections[i][1]);
    }
    return connected - 1;

}

// 重点是理解题意：目前有一些节点和边（已经形成了m个连通分量），要使整个网络连通（原m个连通块都要连通，则至少需要m-1个边），所需的最少操作次数（对所有的边进行union，记录要将原来这m个连通块连起来的操作次数，which is m - 1）


// 将原来网络看做是若干个连通块，将最终的全连通看做是 将所有连通块连通，将操作次数看做是所需的操作次数，那么题意就变成了求解m-1，即求解m；那么对原来的边进行union，即统计原来究竟有多少个连通块即可。
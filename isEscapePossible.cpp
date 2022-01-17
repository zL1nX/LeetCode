/*
在一个 106 x 106 的网格中，每个网格上方格的坐标为 (x, y) 。

现在从源方格 source = [sx, sy] 开始出发，意图赶往目标方格 target = [tx, ty] 。数组 blocked 是封锁的方格列表，其中每个 blocked[i] = [xi, yi] 表示坐标为 (xi, yi) 的方格是禁止通行的。

每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格 不 在给出的封锁列表 blocked 上。同时，不允许走出网格。

只有在可以通过一系列的移动从源方格 source 到达目标方格 target 时才返回 true。否则，返回 false。

 

示例 1：

输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
输出：false
解释：
从源方格无法到达目标方格，因为我们无法在网格中移动。
无法向北或者向东移动是因为方格禁止通行。
无法向南或者向西移动是因为不能走出网格。
示例 2：

输入：blocked = [], source = [0,0], target = [999999,999999]
输出：true
解释：
因为没有方格被封锁，所以一定可以到达目标方格。
 

提示：

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= xi, yi < 106
source.length == target.length == 2
0 <= sx, sy, tx, ty < 106
source != target
题目数据保证 source 和 target 不在封锁列表内
通过次数4,990提交次数14,134

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/escape-a-large-maze
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<long long> st;
int MAX = 1e5, edge = 1e6;
const long long base = 13331;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
{
    for(auto& b : blocked)
    {
        st.insert(b[0] * base + b[1]); // 用一个素数进行hash，将二维格点一维化
    }
    int n = blocked.size();
    MAX = n *(n - 1) / 2; // 这个神奇的界
    return isConnect(source, target) && isConnect(target, source); // 两个点之间连通
}

bool isConnect(vector<int>& source, vector<int>& target)
{
    unordered_set<long long> vis;
    queue<pair<int, int>> q;
    q.push({source[0], source[1]});
    vis.insert(source[0] * base + source[1]);
    while(q.size() && vis.size() <= MAX) // BFS
    {
        auto p = q.front();
        q.pop();
        if(p.first == target[0] && p.second == target[1])
        {
            return true;
        }
        for(int i = 0; i < 4; i ++)
        {
            int nx = p.first + dir[i][0], ny = p.second + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= edge || ny >= edge)
            {
                continue;
            }
            if(st.count(nx * base + ny) || vis.count(nx * base + ny))
            {
                continue;
            }
            q.push({nx, ny});
            vis.insert(nx * base + ny);
        }
    }// 如果是走完了，即q为空跳出的循环，则说明经历的点vis其实是不够多的，即block的范围很大
    return vis.size() > MAX; // 经历点的数量足够多
}

/*
作者：AC_OIer
链接：https://leetcode-cn.com/problems/escape-a-large-maze/solution/gong-shui-san-xie-bfs-gei-ding-zhang-ai-8w63o/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

// 麻中麻

// 我只知道大概是用BFS去寻址，甚至都想这是不是A*算法之类的

// 结果人家直接来了一手神之MAX。整体思路其实就是，分别对起点和终点进行BFS，并记录二者BFS过程中经历的点的数量，如果这个数足够多，说明是block不住的

// （当然，如果直接到了对方那边，那肯定是连通的）

// 那么，这个点数足够多的「界」是多少呢？这里大神直接告诉你是 n * (n - 1) / 2，甚至还有证明

// 因此，只要做好BFS以及经历点的记录就可以了
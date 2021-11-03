/*
给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。

 

示例 1:



输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
输出: 4
解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
示例 2:



输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
输出: 10
 

提示:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104
 

通过次数11,867提交次数23,623

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int trapRainWater(vector<vector<int>>& heightMap) 
{
    if(heightMap.size() <= 2 || heightMap[0].size() <= 2)
    {
        return 0;
    }
    int m = heightMap.size(),n = heightMap[0].size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    // 
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || i == m - 1 || j == 0 || j == n - 1)
            {
                pq.push({heightMap[i][j], i * n + j}); // 边界，先将这些木板放进去
                visited[i][j] = true;
            }
        }
    }

    int res = 0;
    int dirs[5] = {-1, 0, 1, 0, -1}; // 这种神奇的direction写法
    while(!pq.empty())
    {
        pii curr = pq.top(); // 在这样一个小顶堆里，top出来的始终是目前木桶外围的最短板，然后根据这个最短板周围的块，如果有更短的那就灌，如果有更高的那就加进来
        pq.pop();
        for(int k = 0; k < 4; k++)
        {
            int nx = curr.second / n + dirs[k], ny = curr.second % n + dirs[k + 1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny])
            {
                if(curr.first > heightMap[nx][ny]) // 确保只有高的才灌
                {
                    res += curr.first - heightMap[nx][ny];
                }
                visited[nx][ny] = true;
                pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny}); // 都要记录，不管灌没灌，这块都要去把高点给push进去，这样才能不断更新所谓的木桶外围
            }
        }
    }
    return res;
}


// 这题是真的强，题解也有一种大巧不工的感觉，本质上就是在一直搜索，只不过用优先队列来进行限制（或者说剪枝？）


// 核心思想就是先确定木桶的外围，找到外围的最短板子后对其周围能填水的地方填水，然后更新木桶外围。学到了。


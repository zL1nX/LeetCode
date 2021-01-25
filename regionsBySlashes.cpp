/*
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

返回区域的数目。

 

示例 1：

输入：
[
  " /",
  "/ "
]
输出：2
解释：2x2 网格如下：

示例 2：

输入：
[
  " /",
  "  "
]
输出：1
解释：2x2 网格如下：

示例 3：

输入：
[
  "\\/",
  "/\\"
]
输出：4
解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：

示例 4：

输入：
[
  "/\\",
  "\\/"
]
输出：5
解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：

示例 5：

输入：
[
  "//",
  "/ "
]
输出：3
解释：2x2 网格如下：

 

提示：

1 <= grid.length == grid[0].length <= 30
grid[i][j] 是 '/'、'\'、或 ' '。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, int> father;
int num_count = 0;

void Init(int n)
{
    for(int i = 0; i < n + 1; i ++)
    {
        father[i] = i;
    }
    num_count = n;
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
    --num_count;
}

int regionsBySlashes(vector<string>& grid) 
{
    // 初始化并查集
    int n = grid.size();
    Init(n);

    //对网格中“相邻”节点进行合并
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int current_id = i * n + j;
            // 将当前格点中下面三角与右边三角和相邻格点中的三角合并
            if(i < n - 1)
            {
                int below = current_id + n;
                Union(current_id * 4 + 2, below * 4); //下合并
            }
            if(j < n - 1)
            {
                int right = current_id + 1;
                Union(current_id * 4 + 1, right * 4 + 3); //右合并
            }

            // 判断格点内容，按照是否位于对角线一侧的标准合并小三角
            if(grid[i][j] == '/') // 注意合并时，两组三角形都要合并 
            {
                Union(current_id * 4, current_id * 4 + 3);
                Union(current_id * 4 + 1, current_id * 4 + 2);
            }
            else if(grid[i][j] == '\\')
            {
                Union(current_id * 4, current_id * 4 + 1);
                Union(current_id * 4 + 2, current_id * 4 + 3);
            }
            else
            {
                Union(current_id * 4, current_id * 4 + 1);
                Union(current_id * 4 + 1, current_id * 4 + 2);
                Union(current_id * 4 + 2, current_id * 4 + 3);
            }
        }
    }
    // 合并之后，此时并查集内连通分量的个数，就是网格中连通区域的个数
    unordered_set<int> nums;
    for(int i = 0; i < n * n * 4; i ++)
    {
        nums.insert(Find(i));
    }
    return nums.size();
    //return num_count;
}

// 用三角形来表示并查集中图的元素，是非常妙的
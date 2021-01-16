/*有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是：

一块砖直接连接到网格的顶部，或者
至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失，然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。

返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。

注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。

 

示例 1：

输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
输出：[2]
解释：
网格开始为：
[[1,0,0,0]，
 [1,1,1,0]]
消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0]
 [0,1,1,0]]
两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
[[1,0,0,0],
 [0,0,0,0]]
因此，结果为 [2] 。
示例 2：

输入：grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
输出：[0,0]
解释：
网格开始为：
[[1,0,0,0],
 [1,1,0,0]]
消除 (1,1) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [1,0,0,0]]
剩下的砖都很稳定，所以不会掉落。网格保持不变：
[[1,0,0,0], 
 [1,0,0,0]]
接下来消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [0,0,0,0]]
剩下的砖块仍然是稳定的，所以不会有砖块掉落。
因此，结果为 [0,0] 。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[i][j] 为 0 或 1
1 <= hits.length <= 4 * 104
hits[i].length == 2
0 <= xi <= m - 1
0 <= yi <= n - 1
所有 (xi, yi) 互不相同


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bricks-falling-when-hit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> father, ranknum;

int get_index(int x, int y, int c)
{
    return c * x + y;   
}

bool ingrid(int x, int y, int rows, int cols)
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}


int find(int x)
{
    if(x != father[x])
    {
        father[x] = find(father[x]);
    }
    return father[x];
}


void Union(int x, int y)
{
    int fx = find(x), fy = find(y);
    if(fx == fy)
    {
        return;
    }
    else
    {
        father[fx] = fy;
        ranknum[fy] += ranknum[fx];
    }
}


vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
{
    int rows = grid.size(), cols = grid[0].size();
    // 复制新数组进行初始化和后续修改等操作
    vector<vector<int>> new_grid(rows, vector<int>(cols));
    for(int i = 0; i < rows;i ++)
    {
        for(int j = 0; j < cols; j++)
        {
            new_grid[i][j] = grid[i][j];
        }
    }
    // 由于后续要逆序添加砖块，因此这一步要先把要敲碎的砖块敲掉，再去还原
    for(int i = 0; i < hits.size();i++)
    {
        new_grid[hits[i][0]][hits[i][1]] = 0;
    }

    // 之后将所谓的网格顶部先连接到屋顶
        // 先进行并查集的初始化
    int size = rows * cols;
    for(int i = 0; i < size + 1; i++)
    {
        father[i] = i;
        ranknum[i] = 1;
    }
        //再进行顶部砖块的合并
    for(int i = 0; i < cols;i++)
    {
        if(new_grid[0][i] == 1)
        {
            Union(i, size);
        }
    }

    // 此外，由于要为后续砖块的逐个添加做好准备，因此还得把那些相连的砖块先都连起来，这样当有砖块添加上后，就能立即得到相应的连接情况
    for(int i = 1; i < rows;i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(new_grid[i][j] == 1)
            {
                if(new_grid[i - 1][j])
                {
                    Union(get_index(i - 1, j, cols), get_index(i, j, cols));
                }
                if(j > 0 && new_grid[i][j - 1])
                {
                    Union(get_index(i, j - 1, cols), get_index(i, j, cols));
                }
            }
        }
    }

    // 接下来进行逆序计算，即砖块往上拼接，观察变化数量
    vector<int> res(hits.size(), 0);
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i = hits.size() - 1; i >= 0; i--)
    {
        int x = hits[i][0], y = hits[i][1];
        if(grid[x][y] == 0) // 假如在原砖块中 要hit的砖块恰为0，即这个hit是无效的，那么肯定就不管了
        {
            continue;
        }
        
        // 还没补砖块之前的数量
        int origin = ranknum[find(size)];

        if(x == 0) // 要是要补的砖块就是顶部，那么就得让它去和屋顶连接。
        {
            Union(y, size);
        }


        // 然后看补上去的这个砖块会能带动周围多少砖块，即形成联通
        for(vector<int> move : directions)
        {
            int nx = x + move[0], ny = y + move[1];
            if(ingrid(nx, ny, rows, cols) && new_grid[nx][ny] == 1)
            {
                Union(get_index(nx, ny, cols), get_index(x, y, cols));
            }
        }


        // 补了砖块后的数量
        int current = ranknum[find(size)]; // 注意这里是find(size)的节点数量，即包含其本身在内的连通分量的节点个数，即在并查集的根结点的子树包含的结点总数

        // 计算补了砖块后，“稳固”的砖块的数量；由于补了之后可能等于没补，所以可能为0；减1是减去补了这个砖块本身
        res[i] = max(0, current - origin - 1);
        // 最后把这个砖块补上
        new_grid[x][y] = 1;
    }
    return res;
}
/*
给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

每次「迁移」操作将会引发下述活动：

位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
请你返回 k 次迁移操作后最终得到的 二维网格。

 

示例 1：



输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
输出：[[9,1,2],[3,4,5],[6,7,8]]
示例 2：



输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
示例 3：

输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
输出：[[1,2,3],[4,5,6],[7,8,9]]
 

提示：

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100
通过次数19,125提交次数30,726

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shift-2d-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
{
    vector<int> one;
    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            one.push_back(grid[i][j]);
        }
    }
    k %= m * n;
    vector<int> temp(m * n);
    for(int i = 0; i < m * n; i++)
    {
        temp[(i + k) % (m * n)] = one[i];
    }
    for(int i = 0; i < m * n; i++)
    {
        cout << temp[i] << " ";
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            grid[i][j] = temp[i * m + j]; // 注意这里是 *m 不是 *n
        }
    }
    return grid;
}

// 转换成一维以后再循环移位即可

int main()
{
    int k = 1;
    vector<vector<int>> grid = {{1}, {2}, {3}, {4}, {7}, {6}, {5}};
    // {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    // {{1,2,3},{4,5,6},{7,8,9}};
    shiftGrid(grid, 23);
    return 0;
}
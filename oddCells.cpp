/*

给你一个 n 行 m 列的矩阵，最开始的时候，每个单元格中的值都是 0。

另有一个索引数组 indices，indices[i] = [ri, ci] 中的 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

你需要将每对 [ri, ci] 指定的行和列上的所有单元格的值加 1。

请你在执行完所有 indices 指定的增量操作后，返回矩阵中 「奇数值单元格」 的数目。

 

示例 1：



输入：n = 2, m = 3, indices = [[0,1],[1,1]]
输出：6
解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
示例 2：



输入：n = 2, m = 2, indices = [[1,1],[0,0]]
输出：0
解释：最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
 

提示：

1 <= n <= 50
1 <= m <= 50
1 <= indices.length <= 100
0 <= indices[i][0] < n
0 <= indices[i][1] < m


*/
#include <vector>
using namespace std;
void row_add(vector<vector<int>>& board, int row)
{
    for(int i = 0; i < board[row].size(); i ++)
    {
        board[row][i]++;
    }
}

void column_add(vector<vector<int>>& board, int col)
{
    for(int i = 0; i < board.size(); i ++)
    {
        board[i][col]++;
    }
}

int oddCells(int n, int m, vector<vector<int>>& indices) 
{
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i = 0;i < indices.size(); i ++)
    {
        row_add(board, indices[i][0]);
        column_add(board, indices[i][1]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m;j ++)
        {
            cnt += board[i][j] % 2;
        }
    }
    return cnt;
}
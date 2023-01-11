/*
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]
 

提示：

1 <= n <= 9
*/

#include <vector>
#include <string>
using namespace std;

vector<vector<string>> res;

vector<vector<string>> solveNQueens(int n) 
{
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0); // 从第一行开始按行放置皇后
    return res;
}

void backtrack(vector<string>& board, int row)
{
    if(row == board.size())
    {
        res.push_back(board);
        return;
    }
    int n = board[row].size();
    for(int col = 0; col < n; col++)
    {
        if(!isValid(board, row, col))
        {
            continue;
        }
        // 如果当前格落子没问题, 那就开始暴搜
        board[row][col] = 'Q';
        backtrack(board, row + 1);
        board[row][col] = '.';
    }
}

bool isValid(vector<string>& board, int row, int col)
{
    int n = board[row].size();
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 'Q')
        {
            return false;
        }
    }
    // 这一列上是否冲突
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }
    // 检查左上是否会冲突
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }
    // 检查右上是否会冲突 (注意这里的边界条件)
    return true;
}

// 51. N 皇后
/*
在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，右下单元格是 (n - 1, n - 1) 。

象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。



每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。

骑士继续移动，直到它走了 k 步或离开了棋盘。

返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。

 

示例 1：

输入: n = 3, k = 2, row = 0, column = 0
输出: 0.0625
解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
在每一个位置上，也有两种移动可以让骑士留在棋盘上。
骑士留在棋盘上的总概率是0.0625。
示例 2：

输入: n = 1, k = 0, row = 0, column = 0
输出: 1.00000
 

提示:

1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/knight-probability-in-chessboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

int dir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

double knightProbability(int n, int k, int row, int column) 
{
    vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n)));
    // 
    for(int step = 0; step <= k;step++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(step == 0)
                {
                    dp[step][i][j] = 1 ; //
                }
                else
                {
                    for(int k = 0; k < 8; k++)
                    {
                        int ni = i + dir[k][0], nj = j + dir[k][1];
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n)
                        {
                            dp[step][i][j] += dp[step-1][ni][nj] / 8; //
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column];
}

// 本以为是dfs，但是又不知道该怎么表示概率这个写法。没想到题解是用的dp

// dp的概念很有意思，表示在剩余step的条件下，从i j出发最终能落在棋盘内的概率

// 那么当step=0时，所有的dp项必然都是1了，所以dp[0][i][j] = 1，就有了起始条件

// 而在这个dp的定义下，下一个状态的就是step-1，然后坐标相应地进行变化；但实际上在写的时候，是从step-1倒推回step的，并且乘上0.125

// 这样就表示了从下一个状态的概率的八分之一是由当前这个状态贡献的（因为每个这8个方向都是独立的，所以可以累加）

// 最终三重遍历完就是结果

// 很神奇的一道dp题
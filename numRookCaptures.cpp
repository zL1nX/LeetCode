/*

在一个 8 x 8 的棋盘上，有一个白色的车（Rook），用字符 'R' 表示。棋盘上还可能存在空方块，白色的象（Bishop）以及黑色的卒（pawn），分别用字符 '.'，'B' 和 'p' 表示。不难看出，大写字符表示的是白棋，小写字符表示的是黑棋。

车按国际象棋中的规则移动。东，西，南，北四个基本方向任选其一，然后一直向选定的方向移动，直到满足下列四个条件之一：

棋手选择主动停下来。
棋子因到达棋盘的边缘而停下。
棋子移动到某一方格来捕获位于该方格上敌方（黑色）的卒，停在该方格内。
车不能进入/越过已经放有其他友方棋子（白色的象）的方格，停在友方棋子前。
你现在可以控制车移动一次，请你统计有多少敌方的卒处于你的捕获范围内（即，可以被一步捕获的棋子数）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/available-captures-for-rook
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
#include <vector>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) 
{
    int x = 0, y = 0;
    int hd[4] = {0, 1, 0, -1};
    int vd[4] = {1, 0, -1, 0};
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == 'R')
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 4; i ++)
    {
        for (int step = 0; ; step ++)
        {
            int xs = x + step * hd[i];
            int ys = y + step * vd[i];
            if(xs < 0 || xs >= 8 || ys < 0 || ys >= 8 || board[xs][ys] == 'B')
            {
                break;
            }
            if(board[xs][ys] == 'p')
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
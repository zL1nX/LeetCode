/*
用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
示例 1:
输入: board = ["O  ", "   ", "   "]
输出: false
解释: 第一个玩家总是放置“X”。

示例 2:
输入: board = ["XOX", " X ", "   "]
输出: false
解释: 玩家应该是轮流放置的。

示例 3:
输入: board = ["XXX", "   ", "OOO"]
输出: false

示例 4:
输入: board = ["XOX", "O O", "XOX"]
输出: true
说明:

游戏板 board 是长度为 3 的字符串数组，其中每个字符串 board[i] 的长度为 3。
 board[i][j] 是集合 {" ", "X", "O"} 中的一个字符。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-tic-tac-toe-state
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;

bool validTicTacToe(vector<string>& board) 
{
    int xcnt = 0, ccnt = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(char& c : board[i])
        {
            if(c == 'X') xcnt++;
            else if(c == 'O') ccnt++;
        }
    }
    if(ccnt > xcnt || ccnt < xcnt - 1) return false; // 先看最基本的棋子数量
    if(tictactoewin(board, 'X') && xcnt != ccnt + 1) return false; // 再看如果出现胜负时，棋子的数量
    if(tictactoewin(board, 'O') && xcnt != ccnt) return false;
    return true;
    
}

bool tictactoewin(vector<string>& board, char t) // 用来判断是否有一方获胜
{ // 这种函数参数的定义与写法，还是挺工整的
    for(int i = 0; i < 3; i ++)
    {
        if(t == board[i][0] && t == board[i][1] && t == board[i][2]) return true;
        if(t == board[0][i] && t == board[1][i] && t == board[2][i]) return true;
    }
    if(t == board[0][0] && t == board[1][1] && t == board[2][2]) return true;
    if(t == board[0][2] && t == board[1][1] && t == board[2][0]) return true;
    return false;
}

// 这道题的目的是判断当前井字棋游戏棋盘是否符合是一个有效的井字棋游戏，即是否符合井字棋规则。

// 规则其实已经给出了，主要就是 棋子数量 和 胜负规则 比较重要，而且在判断胜负时，也要考虑棋子数量

// 总而言之，简单来想想，判断一个下棋类游戏是否合法，不就是判断棋子数量的状态吗（因为什么非法的下棋位置啥的，并不是我们考虑的事情）

// 所以这道题就是用来判断各种情况下，棋子数量是否正常的
    
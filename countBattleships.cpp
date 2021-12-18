/*
给你一个大小为 m x n 的矩阵 board 表示甲板，其中，每个单元格可以是一艘战舰 'X' 或者是一个空位 '.' ，返回在甲板 board 上放置的 战舰 的数量。

战舰 只能水平或者垂直放置在 board 上。换句话说，战舰只能按 1 x k（1 行，k 列）或 k x 1（k 行，1 列）的形状建造，其中 k 可以是任意大小。两艘战舰之间至少有一个水平或垂直的空位分隔 （即没有相邻的战舰）。

 

示例 1：


输入：board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
输出：2
示例 2：

输入：board = [["."]]
输出：0
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 是 '.' 或 'X'
 

进阶：你可以实现一次扫描算法，并只使用 O(1) 额外空间，并且不修改 board 的值来解决这个问题吗？

通过次数16,430提交次数21,456

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/battleships-in-a-board
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int countBattleships(vector<vector<char>>& board) 
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    function<int(int, int)> dfs = [&](int i, int j)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '.')
        {
            return 0;
        }
        board[i][j] = '.'; // 防止重复计数，相当于visited数组
        for(int k = 0; k < 4; k++)
        {
            dfs(i + dir[k][0], j + dir[k][1]); // 中间这些dfs只是为了把战舰的格子走一遍，防止被重复计数
        }
        return 1; // 只要上面没有return 0，这里就可以return 1
    };

    int sum = 0;
    for(int i = 0;i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 'X')
            {
                sum += dfs(i, j);
            }
        }
    }
    return sum;
}

// 其实这道题和岛屿数量统计很相似，甚至还更简单，因为战舰相当于是 只会横着或者竖着分布的岛屿

// 因此，只要判定当前的格子是个合法的战舰格子，就可以让数量增加，中间的dfs只是为了把战舰的格子都走一遍，防止重复计数
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

例如，上图是一个7 x 3 的网格。有多少可能的路径？

 

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

int uniquePaths(int m, int n) 
{
    int board[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n;j ++)
            board[i][j] = 0;
    for(int i = 0;i < m;i ++)
    {
        for(int j = 0; j < n;j ++)
        {
            if(i == 0 || j == 0)
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = board[i - 1][j] + board[i][j - 1];
            } 
        }
    }
    return board[m - 1][n - 1];
}


// 注意到这是一个组合问题，直接计算C(m+n-2,min(m-1, n-1))即可。时间复杂度为O(n)，空间复杂度O(1)


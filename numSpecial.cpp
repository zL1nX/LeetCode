/*
给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵 mat 中特殊位置的数目 。

特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j 列中的所有其他元素均为 0（行和列的下标均 从 0 开始 ），则位置 (i, j) 被称为特殊位置。

 

示例 1：

输入：mat = [[1,0,0],
            [0,0,1],
            [1,0,0]]
输出：1
解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
示例 2：

输入：mat = [[1,0,0],
            [0,1,0],
            [0,0,1]]
输出：3
解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
示例 3：

输入：mat = [[0,0,0,1],
            [1,0,0,0],
            [0,1,1,0],
            [0,0,0,0]]
输出：2
示例 4：

输入：mat = [[0,0,0,0,0],
            [1,0,0,0,0],
            [0,1,0,0,0],
            [0,0,1,0,0],
            [0,0,0,1,1]]
输出：3
 

提示：

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
using namespace std;

int isspecial(int x, int y, vector<vector<int>>& mat)
{
    for(int i = 0; i < mat.size(); i++)
    {
        if(mat[i][y] == 1 && i != x)
        {
            return 0;
        }
    }
    for(int j = 0; j < mat[0].size(); j++)
    {
        if(mat[x][j] == 1 && j != y)
        {
            return 0;
        }
    }
    return 1;
}
int numSpecial(vector<vector<int>>& mat) 
{
    int cnt = 0;
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[0].size();j++)
        {
            if(mat[i][j])
            {
                cnt += isspecial(i, j, mat);
            }
        }
    }
    return cnt;
}
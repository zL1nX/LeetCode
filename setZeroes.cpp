/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) 
{
    int m = matrix.size(), n = matrix[0].size();
    //vector<int> row_zero, col_zero;
    set<int> row_zero, col_zero;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                row_zero.insert(i);
                col_zero.insert(j);
            }
        }
    }
    for(auto it = row_zero.begin(); it != row_zero.end(); it++)
    {
        for(int c = 0; c < matrix[0].size(); c++)
        {
            matrix[*it][c] = 0;
        }
    }
    for(auto it = col_zero.begin(); it != col_zero.end(); it++)
    {
        for(int r = 0; r < matrix.size(); r ++)
        {
            matrix[r][*it] = 0;
        }
    }
}
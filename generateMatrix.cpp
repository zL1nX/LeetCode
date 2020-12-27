/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) 
{
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int num = 1, i = 0;
    while(num <= n * n )
    {
        for(int j = i; j < n - i; j++)
        {
            mat[i][j] = num++;
        }
        for(int j = i + 1; j < n - i;j++)
        {
            mat[j][n - i - 1] = num++;
        }
        for(int j = n - i - 2; j >= i; j--)
        {
            mat[n - i - 1][j] = num++;
        }
        for(int j = n - i - 2; j > i; j--)
        {
            mat[j][i] = num++;
        }
        i ++;
    }
    return mat;
}
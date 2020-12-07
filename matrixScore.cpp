/*
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

 

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

提示：

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <math.h>
using namespace std;

int matrixScore(vector<vector<int>>& A) {
int m = A.size(), n = A[0].size();
    for(int i = 0; i < m; i ++)
    {
        if(A[i][0]!= 1)
        {
            for(int j = 0; j < n; j++)
            {
                A[i][j] = !A[i][j];
            }
        }
    }

    for(int i = 1; i < n; i ++)
    {
        int cnt = 0;
        for(int j = 0; j < m; j++)
        {
            if(A[j][i]) cnt++;
        }
        if(cnt < (m + 1) / 2) 
        {
            for(int j = 0; j < m; j++)
                A[j][i] = !A[j][i];
        }
    }
    int sum = 0;
    for(int i = 0; i < m; i ++)
    {
        int row_sum = 0;
        for(int j = n - 1;j >= 0; j--)
        {
            row_sum += A[i][j] * pow(2, n - 1 - j);
        }
        sum += row_sum;
    }
    return sum;
}
/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：


输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int up = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    if(bottom < 0 || right < 0)
    {
        return {};
    }
    vector<int> res;
    while(true)
    {
        for(int i = left; i <= right; i++)
        {
            res.push_back(matrix[up][i]);
        }
        up++;
        if(up > bottom) break;
        for(int i = up; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        right --;
        if(right < left) break;
        for(int i = right; i >= left; i--)
        {
            res.push_back(matrix[bottom][i]);
        }
        bottom --;
        if(bottom < up) break;
        for(int i = bottom; i >= up; i--)
        {
            res.push_back(matrix[i][left]);
        }
        left++;
        if(left > right) break;
        
    }
    return res;
}

// 典型的回字形矩阵的题，值得多练习
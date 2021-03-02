/*
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。


上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0)
        {
            int n = matrix[0].size(); // 注意此处如果矩阵为空的话，是不能直接访问matrix0的，因此需要写到条件里
            sums.resize(m, vector<int>(n + 1)); // resize xdl
            for(int i = 0; i < m; i ++)
            {
                for(int j = 0; j < n; j++)
                {
                    sums[i][j + 1] = sums[i][j] + matrix[i][j]; // 前缀和，sums中的每个元素都表示这一行前面的元素相加
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int res = 0;
        for(int i = row1; i <= row2; i++)
        {
            res += sums[i][col2 + 1] - sums[i][col1];
        }
        return res;
    }
};
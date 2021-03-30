/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
通过次数94,775提交次数226,130


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(matrix[mid / n][mid % n] > target)
        {
            right = mid - 1;
        }
        else if(matrix[mid / n][mid % n] < target)
        {
            left = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// 乍一看以为是要做两次二分查找，但实际上对坐标进行转换后，只用做一次二分就够了

// 练练二分
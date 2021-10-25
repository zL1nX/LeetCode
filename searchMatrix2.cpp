/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
 

示例 1：


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
示例 2：


输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
每行的所有元素从左到右升序排列
每列的所有元素从上到下升序排列
-109 <= target <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size(), n = matrix[0].size();
    if(m == 0 || n == 0) return false;
    int i = m - 1, j = 0; // 从左下角的节点开始搜索，来保证能全部搜到；如果随便选一个其他节点，将不能保证最后的收敛位置
    while( i >= 0 && j < n )
    {
        if(matrix[i][j] == target)
        {
            return true;
        }
        else if(matrix[i][j] < target)
        {
            j += 1; // 小于target，向右移一列（变大）
        }
        else
        {
            i -= 1; // 大于target，向上走一行（变小）
        }   
    }
    return false;
}
// 这题有点神奇奥，当时以为是两种思路：嵌套的二分，或者全局编号二分

// 但底下评论说，这样的矩阵从右上角开始看，其实是一颗BST，这就确实有点巧妙了

// 所以这道题就是转换成了BST的搜索问题，即从一个底层结点开始，逐个结点判断（这本质上也相当于一种全局二分）
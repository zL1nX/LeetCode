/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) 
{
    vector<int> lastRow, currentRow;
    for(int i = 1; i <= rowIndex + 1; i ++)
    {
        currentRow = vector<int>(i, 1);
        for(int j = 1; j < i - 1; j++)
        {
           currentRow[j] = lastRow[j - 1] + lastRow[j];
        }
        lastRow.clear();
        lastRow = currentRow;
    }
    return currentRow;
}
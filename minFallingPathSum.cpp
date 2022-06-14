/*
给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

 

示例 1：



输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
输出：13
解释：如图所示，为和最小的两条下降路径
示例 2：



输入：matrix = [[-19,57],[-40,-5]]
输出：-59
解释：如图所示，为和最小的下降路径
 

提示：

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-falling-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int threemin(int a, int b, int c)
{
    return min(a, min(b, c));
}

int minFallingPathSum(vector<vector<int>>& matrix) 
{
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(r, vector<int>(c + 2, 10001)); // 
    for(int j = 1; j <= c; j ++)
    {
        dp[0][j] = matrix[0][j - 1]; //
    }
    for(int i = 1; i < r; i++)
    {
        for(int j = 1; j <= c; j++) //
        {
            dp[i][j] = matrix[i][j - 1] + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1]));
        }
    }
    return *min_element(dp[r - 1].begin(), dp[r - 1].end());
}

int main()
{
    vector<vector<int>> m = {{17, 82}, {1, -44}};
    cout << minFallingPathSum(m) << endl;
}

// 看题目应该是很明显的dp状态转移, 和地图寻址很类似

// 但这个题很好地体现了dp中初始值的设定问题
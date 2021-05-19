/*
给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。

矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。

请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。

 

示例 1：

输入：matrix = [[5,2],[1,6]], k = 1
输出：7
解释：坐标 (0,1) 的值是 5 XOR 2 = 7 ，为最大的值。
示例 2：

输入：matrix = [[5,2],[1,6]], k = 2
输出：5
解释：坐标 (0,0) 的值是 5 = 5 ，为第 2 大的值。
示例 3：

输入：matrix = [[5,2],[1,6]], k = 3
输出：4
解释：坐标 (1,0) 的值是 5 XOR 1 = 4 ，为第 3 大的值。
示例 4：

输入：matrix = [[5,2],[1,6]], k = 4
输出：0
解释：坐标 (1,1) 的值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的值。
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) 
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> prefix(m, vector<int>(n, 0));
    for(int i = 0; i < m;i ++) // 对每一行求前缀和
    {
        int last = 0;
        vector<int> row_dp;
        for(int j = 0; j < n; j++)
        {
            last ^= matrix[i][j];
            row_dp.push_back(last);
        }
        prefix[i] = row_dp;
    }

    vector<int> xor_res;
    for(int i = 0; i < n; i ++)
    {
        int cur = 0;
        for(int j = 0; j < m; j ++)
        {
            cur ^= prefix[j][i]; // 对每一列求前缀和
            xor_res.push_back(cur);
        }
    }
    sort(xor_res.begin(), xor_res.end());
    return xor_res[m * n - k];
}

// 二维前缀和问题

// 直接模拟就好

// 但其实有一种简洁的写法，就是只管自己这片的

/*for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                results.push_back(pre[i][j]);
            }
        }
*/
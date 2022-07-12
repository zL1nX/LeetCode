/*
给你一个 m x n 的矩阵，最开始的时候，每个单元格中的值都是 0。

另有一个二维索引数组 indices，indices[i] = [ri, ci] 指向矩阵中的某个位置，其中 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

对 indices[i] 所指向的每个位置，应同时执行下述增量操作：

ri 行上的所有单元格，加 1 。
ci 列上的所有单元格，加 1 。
给你 m、n 和 indices 。请你在执行完所有 indices 指定的增量操作后，返回矩阵中 奇数值单元格 的数目。

 

示例 1：



输入：m = 2, n = 3, indices = [[0,1],[1,1]]
输出：6
解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
示例 2：



输入：m = 2, n = 2, indices = [[1,1],[0,0]]
输出：0
解释：最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
 

提示：

1 <= m, n <= 50
1 <= indices.length <= 100
0 <= ri < m
0 <= ci < n
 

进阶：你可以设计一个时间复杂度为 O(n + m + indices.length) 且仅用 O(n + m) 额外空间的算法来解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;


int oddCells(int m, int n, vector<vector<int>>& indices) 
{
    vector<int> row(m), col(n);
    for(vector<int>& id : indices)
    {
        row[id[0]]++;
        col[id[1]]++;
    }
    int oddcount_r = 0, oddcount_c = 0;
    for(int i = 0; i < m; i ++)
    {
        if(row[i] & 1) oddcount_r++; // 计算奇数的操作次数
    }
    for(int j = 0; j < n; j++)
    {
        if(col[j] & 1) oddcount_c++;
    }
    return oddcount_r * (n - oddcount_c) + oddcount_c * (m - oddcount_r);
}

// 直接模拟肯定谁都能写, 但进一步抽象一下, 一个位置如果最后是奇数, 说明行和列其中一个操作了奇数次, 一个操作了偶数次

// 因此, 分别统计行和列中的奇数操作次数, 对于单独的某一行而言, 如果操作了奇数次那就这一行中偶数列的位置对应的矩阵点就是奇数

// 同理, 如果操作了偶数次, 就找那些奇数操作次数的列

// 最终结果就是 奇数行 * 偶数列 + 偶数行 * 奇数列
/*
给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。

题目数据保证总会存在一个数值和不超过 k 的矩形区域。

 

示例 1：


输入：matrix = [[1,0,1],[0,-2,3]], k = 2
输出：2
解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
示例 2：

输入：matrix = [[2,2,-1]], k = 3
输出：3
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105
 

进阶：如果行数远大于列数，该如何设计解决方案？

通过次数9,653提交次数23,381

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <set>

using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
{
    int m = matrix.size(), n = matrix[0].size();
    int res = INT_MIN;
    for(int i = 0; i < m; i++)
    {
        vector<int> sum(n);
        for(int j = i; j < m; j++)
        {
            for(int t = 0; t < n ; t++)
            {
                sum[t] += matrix[j][t]; 
            }
            set<int> SumSet{0};
            int s = 0;
            for(int c : sum)
            {
                s += c;
                auto l = SumSet.lower_bound(s - k);
                if( l != SumSet.end())
                {
                    res = max(res, s - *l);
                }
                SumSet.insert(s);
            }
        }
    }
    return res;
}

// 淦 太难了，先unsolved
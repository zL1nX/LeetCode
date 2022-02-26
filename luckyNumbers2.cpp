/*
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
 

示例 1：

输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
输出：[15]
解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 2：

输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
输出：[12]
解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 3：

输入：matrix = [[7,8],[1,2]]
输出：[7]
 

提示：

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5
矩阵中的所有元素都是不同的
通过次数22,665提交次数30,214


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <unordered_map>
using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) 
{
    vector<int> res;
    unordered_map<int, int> rec;
    for(int i = 0; i < matrix.size(); i++)
    {
        int minn = *min_element(matrix[i].begin(), matrix[i].end());
        rec[minn]++;
    }
    for(int j = 0; j < matrix[0].size(); j++)
    {
        int maxn = matrix[0][j];
        for(int i = 1; i < matrix.size(); i++)
        {
            maxn = max(maxn, matrix[i][j]);
        }
        if(rec[maxn] > 0)
        {
            res.push_back(maxn);
        }
    }
    return res; 
}

// 怎么说呢，这个题目给出的要求感觉就只能遍历，而且题解也没别的方法

// 所以写出来的代码无非是各种遍历的优化，像我这个就是用的哈希表，这样最后的时候就不用再对比一遍双方的最大最小值了

// 别的没啥，就是直接最大最小去maxmin就行
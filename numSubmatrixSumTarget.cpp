/*
给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。

子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。

如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），那么这两个子矩阵也不同。

 

示例 1：



输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
输出：4
解释：四个只含 0 的 1x1 子矩阵。
示例 2：

输入：matrix = [[1,-1],[-1,1]], target = 0
输出：5
解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
示例 3：

输入：matrix = [[904]], target = 0
输出：0
 

提示：

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
通过次数4,954提交次数8,928

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

int findUpperBound(vector<int> sum, int target)
{
    unordered_map<int, int> prefix_appr; // 存储每种前缀和值出现的次数
    int curr_all = 0, res = 0;
    prefix_appr[0] = 1;
    for(auto& cur : sum)
    {
        curr_all += cur; // currall实际上就是矩阵形式而非列形式的真正的前缀和
        // cur - upper_bound_prefix = target
        // 因为前缀和实际上表示的是上界到下界的累加值，而要找的是子数组上界值，因此做一个简单的减法和移项，就会发现这个特点
        if(prefix_appr.find(curr_all - target) != prefix_appr.end())
        {
            res += prefix_appr[curr_all - target]; // 有对应子数组上界值的话，有几种算几种，都能使中间这段和为target
        }
        prefix_appr[curr_all] ++;
    }
    return res;
}
// 因为最开始的时候，i从0开始，j会从0一直到m，因此最开始的几次循环会覆盖整个数组，那么不用担心会不会找不到值

// 后面i不断变大，那么子数组们也会被不断找到，所以不用担心会不会漏掉

// 哈希表中0置为1的那一项很关键，因为很可能先碰到一个为target的数组，此时减一下就是0

//  不用担心哈希表会漏了，之前的上下界机制以及哈希表里面的currall都会保证每个情况都加的进来
    // 同时0也确保了露不掉

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size(), n = matrix[0].size();
    int kinds = 0;
    for(int i = 0; i < m; i ++)
    {
        vector<int> sum(n); // 当前上界下对应的所有前缀和数组

        for(int j = i; j < m ; j++) // 对每列求前缀和，因此i j就是这一列的上下边界
        {
            for(int c = 0; c < n; c ++)
            {
                sum[c] += matrix[j][c]; // 每针对一个下界遍历一次
            }
            kinds += findUpperBound(sum, target);// 就去调这个函数看下有多少匹配的值
        }
        // 因为sum是只有上界变才会变，所以一个上界对应着一种sum，
    }
    return kinds;
}

// 又是前缀和，淦

// 这题总感觉似曾相识的样子，结果发现确实是

// 核心在于正确处理 前缀和矩阵 与 最终目标匹配 之间的关系

    // 之前的有道题是需要二分查找，这道题是数值匹配

/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

 

示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：

输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 

提示：

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100
通过次数44,311提交次数77,335


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
using namespace std;

vector<int> count_bits(string s)
{
    vector<int> res(2);
    for(const char& c : s)
    {
        if(c == '0')
        {
            res[0]++;
        }
        else
        {
            res[1]++;
        }
    }
    return res;

}


int findMaxForm(vector<string>& strs, int m, int n) 
{
    int l = strs.size();
    vector<vector<vector<int>>> dp(l + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
    // 题目问啥，dp就定义成啥
    for(int i = 1; i <= l; i++)
    {
        vector<int> count_res = count_bits(strs[i - 1]);
        int zeros = count_res[0], ones = count_res[1];
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k]; // 不选第i-1个字符串，那么最多的字符串数量肯定没变
                if(j >= zeros && k >= ones) // 只有当前字符串的01数量小于等于上界值时才能考虑选的问题
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1); 
                    // 那就看到底是选了大（选了的话，因为要至多jk个，所以前面的就直接减了） 还是没选大
                }
            }
        }
    }
    return dp[l][m][n];
}

// 要用dp我是没想到的，我本以为要哈希表 + 位运算选子集

// 但想到本质其实是一个背包问题，用dp也就无可厚非了

// dp[i][j][k] 定义的就是在前i个字符串中，满足至多j个0和k个1的最多子集数量 dp[l][m][n]即为最终答案

// 那么状态转换其实就是看第i-1个字符串选不选
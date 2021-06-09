/*
集团里有 n 名员工，他们可以完成各种各样的工作创造利润。

第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。

工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。

有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。

 

示例 1：

输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
输出：2
解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
总的来说，有两种计划。
示例 2：

输入：n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
输出：7
解释：至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
有 7 种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。
 

提示：

1 <= n <= 100
0 <= minProfit <= 100
1 <= group.length <= 100
1 <= group[i] <= 100
profit.length == group.length
0 <= profit[i] <= 100
通过次数4,854提交次数10,601

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/profitable-schemes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
{
    int m = group.size();
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
    dp[0][0][0] = 1;
    for(int i = 1; i <= m; i++)
    {
        int need_group = group[i - 1], will_profit = profit[i - 1];
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= minProfit; k++)
            {
                if(j < need_group)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else
                {
                    dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - need_group][max(0, k - will_profit)]) % mod;
                }   
            }
        }
    }

    int count = 0;
    for(int j = 0; j <= n; j ++)
    {
        count = (count + dp[m][j][minProfit]) % mod;
    }
    return count;
    
}

// 没做出来，但也不是完全没做出来；起码知道要三维dp

// 其中dp[i][j][k] 表示在前 i 个工作中选择了 j 个员工，并且满足工作利润至少为 k 的情况下的盈利计划的总数目

// 那么在状态转移时，需要考虑选下一个工作需要的人数 以及  下一个工作能挣多少钱

// 要是人数比当前遍历得到的j多了，那肯定没法开展，只能直接赋值；要需要的人数少的话，可以选择

// 同时要考虑挣得钱够不够，要是够k的话，其实i-1只需要0即可

// 与前几天的题还是挺像的，感觉可以多做几遍
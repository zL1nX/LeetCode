/*
给你一个整数数组 jobs ，其中 jobs[i] 是完成第 i 项工作要花费的时间。

请你将这些工作分配给 k 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间 是完成分配给他们的所有工作花费时间的总和。请你设计一套最佳的工作分配方案，使工人的 最大工作时间 得以 最小化 。

返回分配方案中尽可能 最小 的 最大工作时间 。

 

示例 1：

输入：jobs = [3,2,3], k = 3
输出：3
解释：给每位工人分配一项工作，最大工作时间是 3 。
示例 2：

输入：jobs = [1,2,4,7,8], k = 2
输出：11
解释：按下述方式分配工作：
1 号工人：1、2、8（工作时间 = 1 + 2 + 8 = 11）
2 号工人：4、7（工作时间 = 4 + 7 = 11）
最大工作时间是 11 。
 

提示：

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

// 神之dp以及状态压缩

int minimumTimeRequired(vector<int>& jobs, int k) 
{
    int n = jobs.size(), job_assign = 1 << n; // job assign即为有多少种工作分配状态，比如3个工作有8种状态（工作0分配了，工作1没分配，工作2分配了这种）
    vector<int> work_load(job_assign); // 表示每种分配状态对应的工作时间
    for(int i = 1; i < job_assign; i ++) //用前缀和的方法预计算
    {
        int unassigned = __builtin_ctz(i); // trail zero，即i对应二进制末尾0的个数（还有多少工作没被分配）
        int assigned_word_load = i - (1 << unassigned); // 已经分配了状态数目
        work_load[i] += work_load[assigned_word_load] + jobs[unassigned]; // 当前状态的工作时间 = 已经分配了的工作时间 + 还没被分配的工作时间
    }

    vector<vector<int>> dp(k, vector<int>(job_assign)); // dp[i][j] 表示分配给i个人j个工作时的最小总工作时间
    for(int j = 0; j < job_assign; j ++)
    {
        dp[0][j] = work_load[j]; // 分配给0个人j个工作，意味着最小工作时间就是这j个工作量的时间
    }

    for(int i = 1; i < k; i ++)
    {
        for(int j = 0; j < job_assign; j ++)
        {
            int min_load = INT_MAX;
            for(int x = j; x ; x = (x - 1) & j) // 此处的递减是 补 意义下的递减，而不是十进制下的递减，因为工作要么被分配，要么没被分配
            {
                // 状态转移，前i - 1个人的补集那么多工作，再加上单独分配的这个工作
                min_load = min(min_load, max(dp[i - 1][j - x], work_load[x]));
            }
            dp[i][j] = min_load;
        }
    }
    return dp[k - 1][job_assign - 1]; //最终的结果
}

// 太鸡儿难了

/*
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }

        vector<vector<int>> dp(k, vector<int>(1 << n));
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = sum[i];
        }

        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) {
                    minn = min(minn, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = minn;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/solution/wan-cheng-suo-you-gong-zuo-de-zui-duan-s-hrhu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
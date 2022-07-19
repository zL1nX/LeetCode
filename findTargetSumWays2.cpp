/*
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1
 

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
通过次数250,999提交次数510,882

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) 
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    if(sum < abs(target) || (sum + target) % 2 == 1)
    {
        return 0;
    }
    target = (sum + target) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    // base case 有点不一样
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= target; j++)
        {
            if(j - nums[i - 1] < 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
}

// 494-目标和

// 回溯解法就是暴力的后序递归

// 而要转换成dp, 核心在于转换成一个背包问题, 因此核心在于推导出赋予加号的数字和总的nums和, 以及target之间的关系

// 推导出后, 那么就是一个01背包问题

// 不过有一点不同的是, num可以取0, 因此base case就不同了, 因为dp[i][0]不一定等于1 (可以有很多个0)

// 其他地方都相同
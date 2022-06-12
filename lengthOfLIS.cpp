#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size(), res = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 300-最长递增子序列

// 典中典的递归问题，明确dp数组的定义是：dp[i]是以nums[i]结尾的LCS的数目

// 那么状态转移的话，dp[i]就应该从它前面元素中的最大值转移过来（当然前提是要保证当前的这个值比前面元素那个值大）

// dp[i] = max(dp[i], dp[j] + 1), where nums[i] > nums[j]

// 这是对于一个元素的LCS，那么对于整个数组的LCS，就是取所有dp[i]的最大值
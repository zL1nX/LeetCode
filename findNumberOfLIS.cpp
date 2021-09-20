/*
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

通过次数31,120提交次数78,011


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int findNumberOfLIS(vector<int>& nums) 
{
    int n = nums.size(), maxLen = 0, res;
    vector<int> dp(n), cnt(n);
    for(int i = 0; i < n; i++) // 以最后要加进来的元素去遍历
    {
        dp[i] = 1;
        cnt[i] = 1; // 单独元素也是一个上升子序列，因此初始时为1
        for(int j = 0; j < i; j++) // 依次考察前面的元素，看nums[i]是否能与前面元素的子序列进行组合
        {
            if(nums[i] > nums[j]) // 由于是上升子序列，因此只有在nums[i]比前面元素大的时候才考虑这事
            {
                if(dp[j] + 1 > dp[i]) // 如果dp j转移后还比dp i要长
                {
                    dp[i] = dp[j] + 1; // 那为了满足「最长」的性质，直接让dp i更新，更新为dp j + 1
                    cnt[i] = cnt[j]; // 同时 cnt也要重新开始
                    // 一旦nums j转移后比nums i要长，之前的就从头来过，下面这个分支之前做的所有事情都没用了
                }
                else if(dp[j] + 1 == dp[i]) //如果转移后刚好和此时的dp i一样 
                {
                    cnt[i] += cnt[j]; // 那结果直接累加
                }
            }
        }
        if(dp[i] > maxLen) // 同理，每遍历一次nums i，就更新一次对应的结果，道理和上面类似
        {
            maxLen = dp[i];
            res = cnt[i];
        }
        else if(dp[i] == maxLen)
        {
            res += cnt[i];
        }
    }
    return res;
}
// 由于是找子序列的问题，因此一定要用到dp

// dp[i]表示以nums i结尾的当前最长的子序列，cnt i表示以nums i结尾的当前最长子序列的个数

// 要转移的话，就是dp[j] + 1 到dp[i] ， 同时记得更新cnt
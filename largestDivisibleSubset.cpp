/*
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
示例 2：

输入：nums = [1,2,4,8]
输出：[1,2,4,8]
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
nums 中的所有整数 互不相同
通过次数15,675提交次数37,534

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-divisible-subset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) 
{
    // dp[i] 表示以nums[i]为最大整数的整除子集的大小，即0-（i-1）这些数里哪些能整除nums[i]
    int n = nums.size();
    if(n < 2)
    {
        return nums;
    }
    sort(nums.begin(), nums.end()); // 需要首先将没有重复数组的进行排序
    vector<int> dp(n, 1); // 都初始化为1，表示每个数肯定是自己的因子
    
    int maxSize = 1, maxValue = nums[0]; // 注意这里maxSize最少也是1，即自己
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++) // 考虑i之前的所有数
        {
            if(nums[i] % nums[j] == 0) // 凡是能整除nums[i]的，都算进来
            {
                dp[i] = max(dp[i], dp[j] + 1); // 因为一旦nums[j] 整除nums[i]，说明dp[j]代表的那些元素也能整除nums[i]，因此要用max做一下转移
            }
        }
        // 与此同时找到谁有最多的整除子集（题意要求）
        if(dp[i] > maxSize)
        {
            maxSize = dp[i];
            maxValue = nums[i];
        }
    }

    vector<int> res;
    if(maxSize == 1) // 找了半天发现都是1，由于本题不存在重复元素，那只有可能是nums为1了
    {
        res.push_back(nums[0]);
        return res;
    }
    // 倒序开始，因为这是排序后的数组
    for(int c = n - 1; c >= 0 && maxSize > 0; c--)
    {
        // 找到最大整除子集对应的元素后，先确保maxVal要么是自己，要么能被这个c元素整除
        if(dp[c] == maxSize && (maxValue % nums[c]  == 0))
        {
            // 将其算上结果里后，将maxSize-1，继续看有没有合适的元素了
            res.push_back(nums[c]);
            maxValue = nums[c];
            maxSize --;
        }
        // 这样递推完，能确保每一步都是将拥有最大整除子集的元素加进来，所以结果也必然是最大的
    }
    return res;
    
}

// dp的定义非常巧妙，而且最后的倒序查找元素也非常直击问题的关键
/*
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

 

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
示例 2:

输入: nums = [1,2,3,4], k = 3
输出: false
 

提示：

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000
每个元素的频率在 [1,4] 范围内
*/

#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> memo;

bool canPartitionKSubsets(vector<int>& nums, int k) 
{
    int n = nums.size(), sum = 0;
    for(int v : nums)
    {
        sum += v;
    }
    if(k > n || sum % k != 0)
    {
        return false;
    }
    int target = sum / k;
    int state = 0;
    return backtrack(k, 0, nums, 0, state, target);
}

bool backtrack(int k, int current, vector<int>& nums, int start, int state, int target)
{
    if(k == 0) // 没有剩下的桶了
    {
        return true;
    }
    if(current == target)
    {
        bool next_res = backtrack(k - 1, 0, nums, 0, state, target);
        memo[state] = next_res; // 缓存当前这条暴力路径的状态对应的结果, 以后遇到类似的状态, 就不用再遍历了
        return next_res;
    }
    if(memo.find(state) != memo.end())
    {
        return memo[state];
    }
    for(int i = start; i < nums.size(); i++)
    {
        if(((state >> i) & 1) == 1)
        {
            continue;
        }
        if(nums[i] + current > target)
        {
            continue;
        }

        state |= (1 << i);
        current += nums[i];

        if(backtrack(k, current, nums, i + 1, state, target))
        {
            return true;
        }

        state ^= (1 << i);
        current -= nums[i];
    }

    return false;
}

// 698. 划分为k个相等的子集
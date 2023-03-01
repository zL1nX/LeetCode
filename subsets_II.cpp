/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> track;

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    return res;
}

void backtrack(vector<int>& nums, int start)
{
    res.push_back(track);

    for(int i = start; i < nums.size(); i++)
    {
        if(i > start && nums[i] == nums[i - 1])
        {
            continue;
        }
        track.push_back(nums[i]);
        backtrack(nums, i + 1);
        track.pop_back();
    }
}

// 先排序再跳过相同元素, 避免重复选择
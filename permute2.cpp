/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
*/

#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> curr;

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<bool> used(nums.size(), false);
    curr.empty();
    backtrack(nums, curr, used);
    return res;
}

void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used) 
{
    if(curr.size() == nums.size())
    {
        res.emplace_back(curr);
        curr.empty();
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(used[i])
        {
            continue;
        }
        used[i] = true;
        curr.push_back(nums[i]);
        backtrack(nums, curr, used);
        used[i] = false;
        curr.pop_back();
    }
}
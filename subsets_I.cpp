/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
*/

#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> track;

vector<vector<int>> subsetsI(vector<int>& nums) 
{
    backtrack(nums, 0);
    return res;
}

void backtrack(vector<int>& nums, int start)
{
    res.push_back(track);
    for(int i = start; i < nums.size(); i++)
    {
        track.push_back(nums[i]);
        backtrack(nums, i + 1); // 最先被遍历的是最深层的N个全选的叶子
        track.pop_back(); // 恢复状态
    }
}

// 78-子集

// 通过循环来模拟添加元素的过程, 当一层backtrack结束后, 就会返回到上一层递归添加元素
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


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <math.h>
#include <set>

using namespace std;

vector<int> construct(int index, vector<int>& nums)
{
    vector<int> rows;
    for(int i = 0; i < nums.size(); i++)
    {
        if((index >> i) & 1)
        {
            rows.push_back(nums[i]);
        }
    }
    return rows;
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    if(nums.empty())
    {
        return vector<vector<int>> ();
    }
    sort(nums.begin(), nums.end());
    int sizes = pow(2, nums.size());
    vector<vector<int>> res, res;
    for(int i = 0; i < sizes; i++)
    {
        res.push_back(construct(i, nums));
    }
    set<vector<int>> temp(res.begin(), res.end());
    res.assign(temp.begin(), temp.end());
    return res;
}

// 注意原数组中有重复元素，就会导致生成的子数组会有重复元素，而且有可能是位置不一样但元素一模一样的这种重复

// 因为为了消除位置不一样带来的差异，可以首先sort原数组后，再使用位向量法生成子集，最后使用set去重
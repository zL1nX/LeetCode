/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> track;

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end()); // 同样地, 先排序, 这样对于相同元素好处理
    backtrack(nums, used);
    return res;
}

void backtrack(vector<int>& nums, vector<bool>& used)
{
    if(track.size() == nums.size())
    {
        res.push_back(track);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(used[i])
        {
            continue;
        }
        if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) // 只有前面的元素用过了, 自己才能去用, 否则相同元素之间的相对位置就乱了
        {
            continue;
        }

        track.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, used);
        track.pop_back();
        used[i] = false;
    }
}
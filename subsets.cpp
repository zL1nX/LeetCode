/*
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/
#include <vector>
#include <math.h>
using namespace std;

// void construct(vector<int>& nums, int depth, vector<int> subres, vector<vector<int>>& res)
// {
//     if(depth >= nums.size())
//     {
//         res.push_back(subres);
//         return;
//     }
//     vector<int> ssub = vector<int>(subres);
//     subres.push_back(nums[depth]);
//     construct(nums, depth + 1, ssub, res);
//     construct(nums, depth + 1, subres, res);
// }

// vector<vector<int>> subsets(vector<int>& nums) 
// {
//     vector<vector<int>> res;
//     vector<int> subres;
//     construct(nums, 0, subres, res);
//     return res; 
// }


// 位向量法，将选与不选转化成向量来表示，使时间复杂度更低
vector<int> construct(int index, vector<int>& nums)
{
    vector<int> subres;
    for(int i = 0; i < nums.size(); i ++)
    {
        if((index >> i) & 1)
        {
            subres.push_back(nums[i]);
        }
    }
    return subres;
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> res;
    int sizes = pow(2, nums.size());
    for(int i = 0; i < sizes; i ++)
    {
        res.push_back(construct(i, nums));
    }
    return res;
}
/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 

提示:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> track;
int trackSum = 0;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, 0, target);
    return res;
}

void backtrack(vector<int>& candidates, int start, int& target)
{
    if(trackSum == target)
    {
        res.push_back(track);
    }
    if(trackSum > target)
    {
        return;
    }

    for(int i = start; i < candidates.size(); i++)
    {
        if(i > start && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        trackSum += candidates[i];
        track.push_back(candidates[i]);
        backtrack(candidates, i + 1, target);
        track.pop_back();
        trackSum -= candidates[i];
    }
}
/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
 

提示：

1 <= n <= 20
1 <= k <= n
*/

#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> track;

vector<vector<int>> combineI(int n, int k) 
{
    backtrack(n, k, 1);
    return res;
}

void backtrack(int n, int k, int start)
{
    if(track.size() == k)
    {
        res.push_back(track);
        return;
    }
    for(int i = start; i <= n; i ++)
    {
        track.push_back(i);
        backtrack(n, k, i + 1);
        track.pop_back();
    }
}
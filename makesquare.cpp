/*
你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。

如果你能使这个正方形，则返回 true ，否则返回 false 。

 

示例 1:



输入: matchsticks = [1,1,2,2,2]
输出: true
解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: matchsticks = [3,3,3,3,4]
输出: false
解释: 不能用所有火柴拼成一个正方形。
 

提示:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/matchsticks-to-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
bool dfs(int index, vector<int>& matchsticks, vector<int>& currentEdges, int edgeLen)
{
    if(index == matchsticks.size())
    {
        return true;
    }
    for(int i = 0; i < currentEdges.size(); i++)
    {
        currentEdges[i] += matchsticks[index];
        if(currentEdges[i] <= edgeLen && dfs(index + 1, matchsticks, currentEdges, edgeLen))
        {
            return true;
        }
        currentEdges[i] -= matchsticks[index];
    }
    return false;
}

bool makesquare(vector<int>& matchsticks) 
{
    int sumLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if(sumLen % 4 != 0)
    {
        return false;
    }
    int edgeLen = sumLen / 4;
    sort(matchsticks.begin(), matchsticks.end(), [](const int& a, const int& b){
        return a > b;
    });
    vector<int> currentEdges(4);
    return dfs(0, matchsticks, currentEdges, edgeLen);
}

// 473-火柴拼正方形

// 题解框架还就内个暴力回溯，也就是每个都试一遍

// 但不论如何刚开始应该都能想到这是一个规划问题，即很快明确若干个元素的和要等于某个值

// 而方法呢最基础的暴力回溯，当然也有动态规划状态压缩什么的
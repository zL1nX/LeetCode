/*
 * @lc app=leetcode.cn id=1395 lang=cpp
 *
 * [1395] 统计作战单位数
 * n 名士兵站成一排。每个士兵都有一个 独一无二 的评分 rating 。

每 3 个士兵可以组成一个作战单位，分组规则如下：

从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]
作战单位需满足： rating[i] < rating[j] < rating[k] 或者 rating[i] > rating[j] > rating[k] ，其中  0 <= i < j < k < n
请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。

 

示例 1：

输入：rating = [2,5,3,4,1]
输出：3
解释：我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
示例 2：

输入：rating = [2,1,3]
输出：0
解释：根据题目条件，我们无法组建作战单位。
示例 3：

输入：rating = [1,2,3,4]
输出：4
 

提示：

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5
 */


// @lc code=start
#include <vector>
using namespace std;

int numTeams(vector<int>& rating) 
{
    int sum = 0;
    for(int i = 1; i < rating.size() - 1; i++)
    {
        int left_small = 0, left_big = 0;
        for(int b = 0; b < i; b ++)
        {
            if(rating[b] < rating[i]) left_small++;
            if(rating[b] > rating[i]) left_big ++;
        }
        int right_small = 0, right_big = 0;
        for(int a = i + 1; a < rating.size(); a ++)
        {
            if(rating[a] > rating[i]) right_big++;
            if(rating[a] < rating[i]) right_small++;
        }
        sum += left_small * right_big + left_big * right_small;
    }
    return sum;
}

int numTeams(vector<int>& rating) 
{
    int count = 0;
    for(int i = 0;i < rating.size(); i++)
    {
        for(int j = i + 1; j < rating.size(); j++)
        {
            if(rating[j] > rating[i])
            {
                for(int k = j + 1; k < rating.size(); k++)
                {
                    if(rating[k] > rating[j])
                        count ++;
                }
            }

            if(rating[j] < rating[i])
            {
                for(int k = j + 1; k < rating.size(); k++)
                {
                    if(rating[k] < rating[j])
                        count ++;
                }
            }
        }
    }
    return count;
}
// @lc code=end


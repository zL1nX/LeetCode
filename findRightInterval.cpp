/*
给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。

区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。

返回一个由每个区间 i 的 右侧区间 的最小起始位置组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。

 
示例 1：

输入：intervals = [[1,2]]
输出：[-1]
解释：集合中只有一个区间，所以输出-1。
示例 2：

输入：intervals = [[3,4],[2,3],[1,2]]
输出：[-1,0,1]
解释：对于 [3,4] ，没有满足条件的“右侧”区间。
对于 [2,3] ，区间[3,4]具有最小的“右”起点;
对于 [1,2] ，区间[2,3]具有最小的“右”起点。
示例 3：

输入：intervals = [[1,4],[2,3],[3,4]]
输出：[-1,2,-1]
解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
 

提示：

1 <= intervals.length <= 2 * 104
intervals[i].length == 2
-106 <= starti <= endi <= 106
每个间隔的起点都 不相同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-right-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<int> findRightInterval(vector<vector<int>>& intervals) 
{
    vector<pair<int, int>> sintervals;
    int n = intervals.size();
    for(int i = 0; i < n; i++)
    {
        sintervals.emplace_back(intervals[i][0], i);
    }
    sort(sintervals.begin(), sintervals.end());
    vector<int> res(n, -1);
    for(int i = 0; i < n; i++)
    {
        auto it = lower_bound(sintervals.begin(), sintervals.end(), pair<int, int>{intervals[i][1], 0});
        if(it != sintervals.end())
        {
            res[i] = it->second;
        }
    }
    return res;

}

// 436. 寻找右区间

// start各不相同其实就能意识到是要sort，而sort之后就可以直接二分查找了

// 这里有一个小技巧就是利用pair将索引也一块放进去， 这样就能查找时顺便知道索引是啥了
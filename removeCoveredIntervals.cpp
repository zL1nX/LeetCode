/*
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

 

示例：

输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 

提示：​​​​​​

1 <= intervals.length <= 1000
0 <= intervals[i][0] < intervals[i][1] <= 10^5
对于所有的 i != j：intervals[i] != intervals[j]
*/

#include <vector>
#include <algorithm>
using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0])
        {
            return b[1] < a[1];
        }
        return a[0] < b[0];
    }); //
    int res = 0;
    int cleft = intervals[0][0], cright = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++)
    {
        vector<int> curr = intervals[i];
        if(cleft <= curr[0] && cright >= curr[1])
        {
            res++;
        }
        else if(cright >= curr[0] && cright <= curr[1])
        {
            cright = curr[1];
        }
        else if(cright < curr[0])
        {
            cleft = curr[0];
            cright = curr[1];
        }
    }
    return intervals.size() - res;
}


// 1288-删除被覆盖区间

// 隐含条件是一个区间如果被其他若干区间的合并区间给覆盖了, 其实也算, 不一定只能被一个区间覆盖

// 所以在运算过程中需要顺带把区间合并, 然后判断覆盖
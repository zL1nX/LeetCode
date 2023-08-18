/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) {
            return b[1] < a[1];
        }
        return a[0] < b[0];
    });
    vector<vector<int>> res;
    int cleft = intervals[0][0], cright = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++)
    {
        vector<int> curr = intervals[i];
        if(cleft <= curr[0] && cright >= curr[1])
        {
            continue;
        }
        else if(cright >= curr[0] && cright <= curr[1])
        {
            cright = curr[1];
        }
        else if(cright < curr[0])
        {
            res.push_back({cleft, cright});
            cleft = curr[0];
            cright = curr[1];
        }
    }
    return res;

}

// 之前1288题目可以改改直接用, 如果对效率有追求的话, 其实只需要动态维护最大的区间右端点即可

/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // 按区间的 start 升序排列
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            auto& curr = intervals[i];
            // res 中最后一个元素的引用
            auto& last = res.back(); // 因为是引用, 所以会动态更新
            if (curr[0] <= last[1]) {
                last[1] = max(last[1], curr[1]);
            } else {
                // 处理下一个待合并区间
                res.push_back(curr);
            }
        }
        return res;
    }
};
*/
/*
给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。

实现 SummaryRanges 类：

SummaryRanges() 使用一个空数据流初始化对象。
void addNum(int val) 向数据流中加入整数 val 。
int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
 

示例：

输入：
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
输出：
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

解释：
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // 返回 [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
 

提示：

0 <= val <= 104
最多调用 addNum 和 getIntervals 方法 3 * 104 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <map>
using namespace std;

class SummaryRanges {
private:
    map<int, int> intervals; // map本身是有序的，即按照第一个int排序
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        auto interval1 = intervals.upper_bound(val);
        auto interval0 = (interval1 == intervals.begin() ?  intervals.end() : prev(interval1));
        if(interval0 != intervals.end() && interval0->first <= val && interval0->second >= val)
        {
            return;
        }
        else
        {
            bool leftneighbour = (interval0 != intervals.end() && interval0->second + 1 == val);
            bool rightneighbour = (interval1 != intervals.end() && interval1->first -1 == val);
            if(rightneighbour && leftneighbour)
            {
                int nleft = interval0->first, nright = interval1->second;
                intervals.erase(interval0);
                intervals.erase(interval1);
                intervals.emplace(nleft, nright);
            }
            else if(rightneighbour)
            {
                // 因为是按照left进行排序的，所以得重新添加
                int right = interval1->second;
                intervals.erase(interval1);
                intervals.emplace(val, right);
            }
            else if(leftneighbour)
            {
                ++interval0->second;
            }
            else
            {
                intervals.emplace(val, val);
            }
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for(auto& [left, right] : intervals)
        {
            result.push_back({left, right});
        }
        return result;
    }
};

// https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/solution/jiang-shu-ju-liu-bian-wei-duo-ge-bu-xian-hm1r/

// 看完题解似乎觉得也不难？但那几种情况的分类讨论是真的牛
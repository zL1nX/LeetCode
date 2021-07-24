/*
给你一个二维整数数组 ranges 和两个整数 left 和 right 。每个 ranges[i] = [starti, endi] 表示一个从 starti 到 endi 的 闭区间 。

如果闭区间 [left, right] 内每个整数都被 ranges 中 至少一个 区间覆盖，那么请你返回 true ，否则返回 false 。

已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti <= x <= endi ，那么我们称整数x 被覆盖了。

 

示例 1：

输入：ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
输出：true
解释：2 到 5 的每个整数都被覆盖了：
- 2 被第一个区间覆盖。
- 3 和 4 被第二个区间覆盖。
- 5 被第三个区间覆盖。
示例 2：

输入：ranges = [[1,10],[10,20]], left = 21, right = 21
输出：false
解释：21 没有被任何一个区间覆盖。
 

提示：

1 <= ranges.length <= 50
1 <= starti <= endi <= 50
1 <= left <= right <= 50
通过次数5,474提交次数9,068


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 

#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] != b[0])
    {
        return a[0] < b[0];
    }
    else
    {
        return a[1] < b[1];
    }   
}

bool isCovered(vector<vector<int>>& ranges, int left, int right)
{
    sort(ranges.begin(), ranges.end(), cmp);
    for(int num = left; num <= right; num ++)
    {
        bool flag = false;
        for(auto& range : ranges)
        {
            if(range[0] <= num && range[1] >= num)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            return false;
        }
    }
    return true;
}

// 这是直接暴力的写法，本质就是看数是否在某个区间里

// 还有其他什么差分数组啥的，淦这特么算简单题？
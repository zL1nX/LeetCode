/*
给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0
 

提示：

2 <= timePoints <= 2 * 104
timePoints[i] 格式为 "HH:MM"
通过次数29,505提交次数45,272

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int findMinDifference(vector<string>& timePoints) 
{
    vector<int> times;
    for(string& time : timePoints)
    {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3));
        times.push_back(hour * 60 + minute);
    }
    sort(times.begin(), times.end());
    int mind = INT_MAX;
    for(int i = 0; i < times.size() - 1; i++)
    {
        mind = min(mind, times[i + 1] - times[i]);
    }
    mind = min(mind, times[0] + 1440 - times[times.size() - 1]);
    return mind;
}

// 直接转换成整数之后排序相减即可

// 唯一要注意的地方就是发生循环的地方，就是最后的时间和最开始的时间

// 因为排序之后，发生循环的时间中，必然是第一个时间和最后一个时间之间差的也可能比较小，倒数第二个和第二个之间的差值就不可能那么小了

// 所以，要额外判断一下首尾的值，这一点比较重要
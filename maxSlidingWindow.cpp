/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    priority_queue<pair<int, int>> maxKeeper;
    vector<int> res;
    for(int i = 0; i < k; i++)
    {
        maxKeeper.emplace(nums[i], i);
    }
    res.push_back(maxKeeper.top().first);
    for(int i = k; i < nums.size(); i++)
    {
        maxKeeper.emplace(nums[i], i);
        while(!maxKeeper.empty() && maxKeeper.top().second <= i - k) // not in the window, need to be removed
        {
            maxKeeper.pop();
        }
        res.push_back(maxKeeper.top().first); // now the maximum is in our answer
    }
    return res;
}

// 选择合适的数据结构能解决很多问题，比如大根堆，就是时刻帮你把当前元素中的最大值放到堆顶，那么你只需要进行选择就够了
/*
给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在两个下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

 

示例 1：

输入：nums = [1,2,3,1], k = 3, t = 0
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1, t = 2
输出：true
示例 3：

输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false
 

提示：

0 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
0 <= k <= 104
0 <= t <= 231 - 1
通过次数34,003提交次数127,549

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <set>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
    set<long> window;
    for(int i = 0; i < nums.size(); i++)
    {
        auto it = window.lower_bound(long(nums[i]) - t);
        if(it != window.end() && *it <= long(nums[i]) + t)
        {
            return true;
        }
        window.insert(nums[i]); // 要插入的是谁
        if(i >= k)
        {
            window.erase(nums[i - k]);
        }
        // 哪怕现在这前k个没有，等遍历到后面肯定考虑上，要是后面也没有那肯定是无了
        // 将双边问题转化为了单边问题
    }
    return false;
}

// 滑动窗口其实很容易想，但是在与窗口的更新与维护

// 题目是将问题转化为了 考察在k个元素中是否有元素落入[x-t, x+t]的区间内，而且由于这种判断是双向的

// 且是存在性准则，因此当所有元素遍历完后还没有return true，就说明return false

// 因为涉及到查找，所以选用有upper bound 以及有序这种集合set
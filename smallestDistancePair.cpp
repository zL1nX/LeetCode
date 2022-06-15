/*
数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。

给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。返回 所有数对距离中 第 k 小的数对距离。

 

示例 1：

输入：nums = [1,3,1], k = 1
输出：0
解释：数对和对应的距离如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
距离第 1 小的数对是 (1,1) ，距离为 0 。
示例 2：

输入：nums = [1,1,1], k = 2
输出：0
示例 3：

输入：nums = [1,6,1], k = 3
输出：5
 

提示：

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-k-th-smallest-pair-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

int smallestDistancePair(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums.back() - nums.front();
    while(left < right)
    {
        int cnt = 0, mid = left + (right - left) / 2;
        for(int j = 0; j < n; j++)
        {
            int i = lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid) - nums.begin(); // 枚举右端点, 找到最左端的那个小端点
            cnt += j - i; // 当前这个右端点和距离对应的数对数量
        }
        if(cnt >= k) // 数量太多, 缩小距离
        {
            right = mid + 1;
        }
        else
        {
            left = mid;
        }
    }
    return left;
}

// 一眼以为要用堆, 但实际上二分套二分

// 第一层二分是为了搜索距离, 第二层二分是为了搜索在某个距离下, 符合条件的数对数目

// 因此, 肯定先要对数组整体排序一下, 这样就能通过一个元素定位出数对距离的范围

// 而在第一层二分的查找距离过程中, 我们每次要去枚举数对的右端点, 在枚举过程中可以再用二分, 查看符合距离要求的左端点

// 因为nums是排序的, 有了右端点和左端点, 就有了数对的数量, 枚举完一轮之后

// 根据这个数对的数量判断, 移动最外层二分的left (数量太小, 增加距离)或right (数量太多, 减小距离)
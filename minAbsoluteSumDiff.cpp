/*
给你两个正整数数组 nums1 和 nums2 ，数组的长度都是 n 。

数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i < n）的 总和（下标从 0 开始）。

你可以选用 nums1 中的 任意一个 元素来替换 nums1 中的 至多 一个元素，以 最小化 绝对差值和。

在替换数组 nums1 中最多一个元素 之后 ，返回最小绝对差值和。因为答案可能很大，所以需要对 109 + 7 取余 后返回。

|x| 定义为：

如果 x >= 0 ，值为 x ，或者
如果 x <= 0 ，值为 -x
 

示例 1：

输入：nums1 = [1,7,5], nums2 = [2,3,5]
输出：3
解释：有两种可能的最优方案：
- 将第二个元素替换为第一个元素：[1,7,5] => [1,1,5] ，或者
- 将第二个元素替换为第三个元素：[1,7,5] => [1,5,5]
两种方案的绝对差值和都是 |1-2| + (|1-3| 或者 |5-3|) + |5-5| = 3
示例 2：

输入：nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
输出：0
解释：nums1 和 nums2 相等，所以不用替换元素。绝对差值和为 0
示例 3：

输入：nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
输出：20
解释：将第一个元素替换为第二个元素：[1,10,4,4,2,7] => [10,10,4,4,2,7]
绝对差值和为 |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
 

提示：

n == nums1.length
n == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 105
通过次数7,612提交次数19,127

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-sum-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

static constexpr int mod = 1'000'000'007;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> sorted(nums1);
    sort(sorted.begin(), sorted.end());
    int n = nums1.size(), sum = 0, max_diff = nums1[0];
    for(int i = 0; i < n; i ++)
    {
        int diff = abs(nums1[i] - nums2[i]);
        sum = (sum + diff) % mod;
        int j = lower_bound(sorted.begin(), sorted.end(), nums2[i]) - sorted.begin();
        if(j < n) // 这个是为了确保找到了合法的值（即有值比nums2大）
        {
            max_diff = max(max_diff, diff - (sorted[j] - nums2[i]));
        }
        if(j > 0) // 这个是为了确保有值比nums2i小
        {
            max_diff = max(max_diff, diff - (nums2[i] - sorted[j - 1]));
        }
    }
    return (mod + sum - max_diff) % mod;
}

// 二分是没有想到的，太强了

// 反正nums1与nums2是等价的，因此核心就是找与每个nums2[i]最相近的元素

// 那么就是是个查找，但同时最坏也就n2，那么不妨先排序再二分，这样复杂度也会降低

// 排序之后就可直接用lower bound找最近的元素了，但此时找到的元素肯定是比nums2i大的元素（只要j<n）

// 因此还需要看下比nums2i小的元素（但要确保j > 0), 综合判断后就能知道当前对应的最大差值了，然后用sum减去即可
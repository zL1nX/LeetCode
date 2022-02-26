/*
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。

 

示例 1：

输入：nums = [7,1,5,4]
输出：4
解释：
最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
示例 2：

输入：nums = [9,4,3,2]
输出：-1
解释：
不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
示例 3：

输入：nums = [1,5,2,10]
输出：9
解释：
最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
 

提示：

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 109
通过次数11,778提交次数20,124

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <climits>
using namespace std;

int maximumDifference(vector<int>& nums) 
{
    int maxDiff = 0, minn = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] - minn > maxDiff)
        {
            maxDiff = nums[i] - minn;
        }
        if(nums[i] < minn)
        {
            minn = nums[i];
        }
    }
    return maxDiff == 0 ? -1 : maxDiff;
}

// 这道题第一次看到说实话会有点懵逼，或者说会不自觉地去想哈希表的解法

// 但实际上最大的差值一定是出现在前面元素的最小值和后面的某个元素中的

// 因此，只要遍历时维护一个minn表示已经遍历过的元素中的最小值，同时维护一个maxDiff为最大差值

// 在遍历过程中用每个元素去减去minn，就一定是当前情况下的最大差值了，诚然如果后续新的最小值或新的元素能产生更大的maxDiff，那么就更新maxDiff

// 写的时候注意题目要求，即最大差值一定是要大于0的（即后面的元素一定要比当前元素要大）。如果不存在满足要求的 i 和 j ，返回 -1 。
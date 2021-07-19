/*
元素的 频数 是该元素在一个数组中出现的次数。

给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。

执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

 

示例 1：

输入：nums = [1,2,4], k = 5
输出：3
解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
4 是数组中最高频元素，频数是 3 。
示例 2：

输入：nums = [1,4,8,13], k = 5
输出：2
解释：存在多种最优解决方案：
- 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
- 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
- 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。
示例 3：

输入：nums = [3,9,6], k = 2
输出：1
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105
通过次数7,467提交次数18,226

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

#include <vector>
using namespace std;

int maxFrequency(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end()); 
    int n = nums.size(), right = 1, left = 0, res = 0;
    long long sum = 0;
    for(; right < n; right++ )
    {
        sum += (long long)(nums[right] - nums[right - 1]) * (right - left); // 当前这个柱子要填的话需要多少 
        while(sum > k) // 一旦超过了k，说明这种从头开始填的方法不行，因此要缩减预案
        {
            sum -= (nums[right] - nums[left]); // 同时要让sum减去这些要填的
            left++;// 那么就要移动左窗口，减少「拖后腿」的
        }
        res = max(res, right - left + 1); // 每次填完，都记录下窗口的最长长度
    }
    return res;
}

// 其实这道题不难的想到的是，题目中的操作，实际上就是一个不断填坑的过程（因此先排个序再说）

// 但挺难想到的是，用滑动窗口去做，即不断增长窗口，看要填多少东西，然后累加这些要填的和k

// 在这种解法下，所谓频数就是窗口的大小（因为能填，表示能形成一样的）

// 仔细理解了题目思路后，会觉得好棒这道题
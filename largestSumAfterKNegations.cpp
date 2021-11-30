/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

 

示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
示例 2：

输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
示例 3：

输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 

提示：

1 <= nums.length <= 104
-100 <= nums[i] <= 100
1 <= k <= 104
通过次数33,846提交次数63,917

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) 
{
    int sum = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0;i < nums.size(); i++)
    {
        if(nums[i] < 0 && k > 0)
        {
            nums[i] = -nums[i];
            k--;
        }
        sum += nums[i];
    }
    sort(nums.begin(), nums.end()); // 用于找到当前处理后的数组中的最小数（最小非负数）
    return sum - (k % 2 == 0 ? 0 : 2 * nums[0]); // 如果k为奇数，则最小数是最小非负数，此时就是nums【0】
}

// 能想到的第一步就是，我们每次要尽可能把小的负数变成正数，这种贪心才能使得最后的结果最大

// 因此必然要排序，并且要首先处理前面的小负数 

// 如果最后处理完了（k = 0），就不用再处理了；如果k还有值，只能去处理那些小的正数

// 此时需要想到，k的奇偶对结果的影响；k如果是偶数，对结果同样没有影响（不论动的是0还是一个小正数）

// 如果k为奇数，则只能去弄那个最小的正数

// 核心在于想到，在弄完负数之后，其余的数和k的关系，以及该怎么办（剩没剩下？按奇偶性讨论？）

// 还是挺有意思的一道题，而且要注意，sort你甚至可以多用几次
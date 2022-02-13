/*
给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。

从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。

返回可能的 最小差值 。

 

示例 1：

输入：nums = [90], k = 1
输出：0
解释：选出 1 名学生的分数，仅有 1 种方法：
- [90] 最高分和最低分之间的差值是 90 - 90 = 0
可能的最小差值是 0
示例 2：

输入：nums = [9,4,1,7], k = 2
输出：2
解释：选出 2 名学生的分数，有 6 种方法：
- [9,4,1,7] 最高分和最低分之间的差值是 9 - 4 = 5
- [9,4,1,7] 最高分和最低分之间的差值是 9 - 1 = 8
- [9,4,1,7] 最高分和最低分之间的差值是 9 - 7 = 2
- [9,4,1,7] 最高分和最低分之间的差值是 4 - 1 = 3
- [9,4,1,7] 最高分和最低分之间的差值是 7 - 4 = 3
- [9,4,1,7] 最高分和最低分之间的差值是 7 - 1 = 6
可能的最小差值是 2
 

提示：

1 <= k <= nums.length <= 1000
0 <= nums[i] <= 105
通过次数10,831提交次数17,531

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int minimumDifference(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());
    int mind = INT_MAX;
    for(int i = 0; i <= nums.size() - k; i++)
    {
        int d = nums[i + k - 1] - nums[i];
        mind = min(d, mind);
    }
    return mind;
}

// 这种一看就是要排序从而来贪心

// 贪心之后用滑动窗口两个端点值之间相减就ok

// 写的时候注意哪里可以取等就好
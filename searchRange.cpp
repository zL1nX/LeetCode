/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
通过次数156,098提交次数381,956

*/

#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
    if(nums.size() == 0)
    {
        return {-1, -1};
    }

    int start = 0, end = nums.size() - 1;
    while(nums[start] != nums[end] && start < end)
    {
        if(nums[start] != target) start++;
        if(nums[end] != target) end--;
    }

    if(nums[start] != target || start > end)
    {
        return {-1, -1};
    }
    return {start, end};
}
// 也可用二分查找求解，但不如这种简单
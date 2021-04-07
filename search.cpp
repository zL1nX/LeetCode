/*
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

 

示例 1：

输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true
示例 2：

输入：nums = [2,5,6,0,0,1,2], target = 3
输出：false
 

提示：

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-104 <= target <= 104
 

进阶：

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
通过次数65,390提交次数170,983

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

bool search1(vector<int>& nums, int target) 
{
    for(int n : nums)
    {
        if(target == n)
        {
            return true;
        }
    }
    return false;
}

// 直接遍历显然也是能通过的，但面试时肯定不希望你有这样的回答
// 此外，该题明显是想考察二分查找的解法，一种直接的解法是找到分隔点，然后做两次二分，但这样的复杂度就成了n+logn，甚至不如普通查找
// 因此，还是希望能一次遍历找出，即logn的复杂度，那么就需要在二分本身的细节上进行修改


bool search2(vector<int>& nums, int target) 
{
    int n = nums.size();
    if(n == 0)
    {
        return false;
    }
    int left = 0, right = n - 1;
    while(left <= right) // 注意取等，否则会有一个边界值取不到
    {
        int mid = (left + right) / 2;
        if(target == nums[mid])
        {
            return true;
        }// 到这步还都是和传统二分一样

        if(nums[left] == nums[mid] && nums[right] == nums[mid])// 因为有重复元素，因此这种情况下不能判定继续到哪里的区间，所以重新缩减区间范围判断
        {
            left++;
            right--;
        }
        else if(nums[left] <= nums[mid]) // 当left与mid在同侧时
        {
            if(target < nums[mid] && nums[left] <= target) // 当target在left与mid之间时
            {
                right = mid - 1; // 缩减右边界
            }
            else
            {
                left = mid + 1; // left与mid在同一侧时，其余的所有情况，都去缩减左边界
            }
        }
        else
        {
            if(nums[mid] < target && nums[n - 1] >= target) // left与mid不在同侧时，target在mid右侧（即较小的那段区间里）
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return false;
    
}
// 根据target在left mid之间还是mid right之间来决定区间的移动


// 淦 结果直接遍历比二分查找快，尴尬
// 只能说这个题真的奇怪
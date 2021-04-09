/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

 

示例 1：

输入：nums = [1,3,5]
输出：1
示例 2：

输入：nums = [2,2,2,0,1]
输出：0
 

提示：

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
 

进阶：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
通过次数62,443提交次数121,319

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int findMin(vector<int>& nums) 
{
    int left = 0, right = nums.size() - 1, mid = 0;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] < nums[right]) // 因为右半部分的元素一定小于等于左半边部分的元素
        {
            right = mid; // 最小值在右半部分
        }
        else if(nums[mid] > nums[right])
        {
            left = mid + 1; // 最小值在左半部分
        }
        else // 重复元素的存在，使得可以忽略右端点
        {
            right -= 1;
        }
        
    }
    return nums[left];
}

// 画图会帮助理解，并且这个最后一个元素x的作用很大
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/
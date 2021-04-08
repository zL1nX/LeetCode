/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 4 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

 

示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
示例 3：

输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
 

提示：

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums 中的所有整数 互不相同
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
通过次数127,880提交次数238,542

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int findMin(vector<int>& nums) 
{
    int n = nums.size();
    for(int i = 0; i < n - 1; i++)
    {
        if(nums[i] > nums[i + 1])
        {
            return nums[i + 1];
        }
    }
    return nums[0];
}
// 这种写显然面试通不过

int findMin2(vector<int>& nums)
{
    int n = nums.size();
    int left = 0, right = n - 1, mid = 0;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] < nums[right]) // 最后比较时是r与r+1，不会出现同元素比较
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }  
    }
    return nums[mid];
}
// 一旦数组有序，就应该考虑用二分去做，这里再次体现了二分查找的易错性，即各种边界问题以及比较问题
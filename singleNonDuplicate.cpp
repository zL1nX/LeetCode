/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

 

示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10
 

提示:

1 <= nums.length <= 105
0 <= nums[i] <= 105
通过次数53,091提交次数88,971

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) 
{
    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == nums[mid ^ 1]) // 一个奇偶数的相邻的一个数，就是异或1
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}

// 好牛的一道题，如果不对复杂度进行限制，那直接异或就可以，但这个logn的复杂度和有序的条件一摆，那必然是二分了

// 二分的时候，对下标的判定还真有意思。在这种成对出现的数组中，一个事实是，目标元素左右的元素对下标，奇偶性恰好相反

// 因此在计算mid并进行判定时，可以根据mid的奇偶性与对应的一对元素是否相等来说明是否在左边还是右边

// 不过在实现时有一个trick就是可以用mid ^ 1来统一

// 其实如果不用这个trick直接老老实实移动两格，其实也能写，这种奇偶性的判定方法只是将普通的移动两格进行了统一和抽象

// 这种统一的写法确实牛

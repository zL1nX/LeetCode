/*
峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

 

示例 1：

输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。
示例 2：

输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) 
{
    int n = nums.size(), left = 0, right = n;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

// 因为题目限制了是logn级别的，所以肯定是要用二分的写法，但怎么写是另一个问题

// 考虑当前有 nums[i] < nums[i + 1]，那么继续往i + 2的方向走，如果nums[i + 2]是更大的，那二分查找只会继续向右走

// 如果是小的，那么right 应该会与left重合，即返回；最差情况走到底，此时nums[n] = - 无穷，因此也是个峰顶

// 所以在设定了两个端点都是最小值之后，往大的那一边走，必定会遇到个更小值

// 二分的过程就是，先定到一个比右边值大的地方（right=mid），然后left会不断移过来和right重合；

// 否则right就移过去；总之就是，在遇到非单调的点之前，left和right会不断向对方移动

// 挺有意思的这题
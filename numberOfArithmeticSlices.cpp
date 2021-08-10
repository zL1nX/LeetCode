/*
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。

 

示例 1：

输入：nums = [1,2,3,4]
输出：3
解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
示例 2：

输入：nums = [1]
输出：0
 

提示：

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
通过次数41,516提交次数61,757

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) 
{
    int n= nums.size(), res = 0, count = 0;
    if(n < 3)
    {
        return 0;
    }
    int diff = nums[0] - nums[1];
    for(int i = 2; i < nums.size(); i++)
    {
        if(nums[i - 1] - nums[i] == diff)
        {
            count++; // count实际上表示了当前长度的等差数组能贡献几个新的等差子数组（旧的已经被累加上去了）
        }
        else
        {
            diff = nums[i - 1] - nums[i];
            count = 0;
        }
        res += count;  // 每一轮都要加上 ，这样就有1，1+2， 1+2+3来保证结果正确
    }
    return res;
}

// 总感觉其实自己也能写出来这种（汗，核心思路非常朴素，但朴素中带有一点巧妙

// 注意到不同长度的等差数组贡献的等差子数组数量不同，而这个数量实际上就是最基本的累加式：1+2，1+2+3

// 因此在写代码时应当在每一轮都去累加上当前的结果，即count

// 感觉面试会喜欢搞这种，需要多写
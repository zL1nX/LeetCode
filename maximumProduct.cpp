/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;


int maximumProduct(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    long long a = nums[n - 1] * nums[n - 2] * nums[n - 3];
    long long b = nums[0] * nums[1] * nums[n - 1];
    return max(a, b);
}

// 若排序后，后三个数全为正数，则就是后三个数相乘

// 若有一个负数，则还是后三个数相乘

// 若有两个负数，则应为最小的两个负数与最后的数相乘

// 若有三个负数，则还是后三个数相乘
/*
给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
通过次数72,248提交次数125,562

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int maxl = 0;
    int left = 0, right = 0;
    while(right < nums.size())
    {
        if(nums[right] == 1)
        {
            right++;
        }
        else
        {
            maxl = max(maxl, right - left);
            left = ++right;
        }
    }
    maxl = max(maxl, right - left);
    return maxl;
}

// 经典滑窗，注意对最后一次的比较
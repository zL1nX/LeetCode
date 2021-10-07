/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

 

示例 1：

输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。
示例 2：

输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。
示例 3：

输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 

提示：

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？

通过次数64,448提交次数174,898

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

int thirdMax(vector<int>& nums) 
{
    long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
    for(int n : nums)
    {
        if(n > a)
        {
            c = b;b = a;a = n;
        }
        else if(a > n && n > b)
        {
            c = b;b = n;
        }
        else if(b > n && n > c)
        {
            c = n;
        }
    }
    return c == LONG_MIN ? a : c;
}

// 不用排序，直接用三个变量维护前三个最大的值即可

// 挺适合作为面试题，要注意判断时三个变量的顺序
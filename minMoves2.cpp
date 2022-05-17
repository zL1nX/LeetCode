/*
给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。

在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。

 

示例 1：

输入：nums = [1,2,3]
输出：2
解释：
只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
示例 2：

输入：nums = [1,10,2,9]
输出：16
 

提示：

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

int minMoves2(vector<int>& nums) 
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int middle = nums[n / 2], res = 0;
    for(int i = 0; i < n; i++)
    {
        res += abs(nums[i] - middle);
    }
    return res;
}

// 找中位数 具体的证明就不看了 但本质上有点类似于一个极值和动态调整的问题 (图与网络里的思想)

// 所以代码就是排序 + 中位数
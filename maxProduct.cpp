/*

给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。

 

示例 1：

输入：nums = [3,4,5,2]
输出：12 
解释：如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
示例 2：

输入：nums = [1,5,4,5]
输出：16
解释：选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
示例 3：

输入：nums = [3,7]
输出：12
*/
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) 
{
    int m = 0;
    for(int i = 0;i < nums.size();i ++)
    {
        for(int j = i + 1; j < nums.size(); j ++)
        {
            m = max((nums[i] - 1) * (nums[j] - 1), m);
        }
    }
    return m;
}
/*

var maxProduct = function(nums) {
    var a = nums[0];
    var b = nums[1];

    for (var i = 2; i < nums.length; i++) {
        if (a > b) {
            nums[i] > b && (b = nums[i]);
        } else {
            nums[i] > a && (a = nums[i]);
        }
    }

    return (a - 1) * (b - 1);
};

作者：tanglj
链接：https://leetcode-cn.com/problems/maximum-product-of-two-elements-in-an-array/solution/bu-shi-yong-sort-fang-fa-yi-ci-for-xun-huan-by-tan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
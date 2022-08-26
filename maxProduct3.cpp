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
 

提示：

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
通过次数39,434提交次数51,136

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) 
{
    int maxm = nums[0], maxn = nums[1];
    for(int i = 2; i < nums.size(); i++)
    {
        if(maxm > maxn)
        {
            if(nums[i] > maxn) maxn = nums[i];
        }
        else
        {
            if(nums[i] > maxm) maxm = nums[i];
        }
    }
    return (maxm - 1) * (maxn - 1);
}

// 维护最大值与次最大值

// 记得写的时候要注意, 很多用例一不小心就错了

/*
int maxProduct(vector<int>& nums) {
        int a = nums[0], b = nums[1];
        if (a < b) {
            swap(a, b); // a是最大值, b是次大值
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
            } else if (nums[i] > b) {
                b = nums[i];
            }// 注意这里是if和else if, 保证了先更新最大的
        }
        return (a - 1) * (b - 1);
    }

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/solution/shu-zu-zhong-liang-yuan-su-de-zui-da-che-oqkf/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

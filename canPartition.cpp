/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;


/*
// 超时代码
bool search(int sum, int target, int ind, vector<int>& nums)
{
    if(sum > target)
    {
        return false;
    }
    if(sum == target)
    {
        return true;
    }
    if(ind >= nums.size())
    {
        return false;
    }
    return search(sum + nums[ind], target, ind + 1, nums) || search(sum, target, ind + 1, nums);
}

bool canPartition(vector<int>& nums) 
{
    int allSum = 0, target = 0;
    for(int n : nums) allSum += n;
    if(allSum % 2)
    {
        return false;
    }
    else
    {
        target = allSum / 2;
    }
    return search(0, target, 0, nums);
}
*/
// 方法主要有递归选择、动态规划；其中递归的方法容易超时，需要进行记忆化处理
// 实际通过代码待补充
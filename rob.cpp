/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [0]
输出：0
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 1000
通过次数88,668提交次数213,401

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int rob(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    return max(rob1(nums, 0, n - 1), rob1(nums, 1, n)); // 分成第一个房子不抢与最后一个房子不抢两种情况考虑

}

int rob1(vector<int>& nums, int start, int end)
{
    int maxVal = 0, preVal = 0, prepreVal = 0;
    // f[n] = max(f[n-1], f[n-2]+nval)
    // 重点是这个转移方程
    for(int i = start; i < end; i++)
    {
        int temp = preVal; // n - 1
        preVal = max(preVal, prepreVal + nums[i]); // n - 1 to n
        prepreVal = temp; // n - 2 to n - 1
    }
    return preVal;
}
/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

 

示例 1：

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
示例 2：

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 

提示：

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105
*/

#include <vector>

using namespace std;

bool canJump(vector<int>& nums) 
{
    int jump_far = 0, n = nums.size();
    for(int i = 0; i < n - 1; i++)
    {
        jump_far = max(jump_far, i + nums[i]);
        if(jump_far <= i)
        {
            return false;
        }
    }
    return jump_far >= n - 1;
}

// 55-跳跃游戏

// 纯粹的贪心, 即每次看最远能跳到哪里, 最后只要超过了就是可以

// 在处理0时, 就是让最远点无法跳出某个i, 就说明会陷入这个点
/*
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

 

示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:

输入: nums = [2,3,0,1,4]
输出: 2
 

提示:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

#include <vector>
using namespace std;

int canJumpII(vector<int>& nums) 
{
    int curr_farthest = 0;
    int curr_end = 0, jump = 0, n = nums.size();
    for(int i = 0; i < n - 1; i++)
    {
        curr_farthest = max(i + nums[i], curr_farthest);
        if(curr_end == i)
        {
            jump ++;
            curr_end = curr_farthest;
        }
    }
    return jump;
}

// 45. 跳跃游戏 II

// 与55的区别在于, 输出的结果是具体多少次, 这个的判定是在于多少次

// 贪心的原则同样是, 在选择下一次跳到哪的时候, 选能覆盖最远的那个地方, 这样贪心下去得到的次数就是最少得 
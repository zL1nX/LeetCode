/*
存在一个不含 0 的 环形 数组 nums ，每个 nums[i] 都表示位于下标 i 的角色应该向前或向后移动的下标个数：

如果 nums[i] 是正数，向前 移动 nums[i] 步
如果 nums[i] 是负数，向后 移动 nums[i] 步
因为数组是 环形 的，所以可以假设从最后一个元素向前移动一步会到达第一个元素，而第一个元素向后移动一步会到达最后一个元素。

数组中的 循环 由长度为 k 的下标序列 seq ：

遵循上述移动规则将导致重复下标序列 seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
所有 nums[seq[j]] 应当不是 全正 就是 全负
k > 1
如果 nums 中存在循环，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [2,-1,1,2,2]
输出：true
解释：存在循环，按下标 0 -> 2 -> 3 -> 0 。循环长度为 3 。
示例 2：

输入：nums = [-1,2]
输出：false
解释：按下标 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。
示例 3:

输入：nums = [-2,1,-1,-2,-2]
输出：false
解释：按下标 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为 nums[1] 是正数，而 nums[2] 是负数。
所有 nums[seq[j]] 应当不是全正就是全负。
 

提示：

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
nums[i] != 0
 

进阶：你能设计一个时间复杂度为 O(n) 且额外空间复杂度为 O(1) 的算法吗？

通过次数11,037提交次数28,652


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-array-loop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

bool circularArrayLoop(vector<int>& nums) 
{
    int n = nums.size();
    auto next = [&](int loc)
    {
        return (n + (loc + nums[loc]) % n) % n; //
    };
    for(int i = 0; i < n; i++) // 依次以每个点为起点看一遍
    {
        if(nums[i] == 0) // 访问过了
        {
            continue;
        }
        int slow = i, fast = next(i);
        while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0)
        {
            if(slow == fast)
            {
                if(slow != next(slow)) // 小心有的点的步数刚好是n，即next是自己
                {
                    return true; //
                }
                else
                {
                    break;
                }
                
            }
            slow = next(slow);
            fast = next(next(fast));
        }
        int add = i; // 这个起点没找到合适的
        while(nums[add] * nums[next(add)] > 0)
        {
            int temp = add;
            add = next(add);
            nums[temp] = 0; // 相关点都置零
        }
    }
    return false;
}

// 两个点：用0表示已经访问过了，即相当于visited数组；从每个点开始走一遍，反正是确定性的，你要有就有，没有就没有

// 一旦这个点走完之后没有，说明一定是反方向了，不然同方向走的话，肯定能碰上（这是必然的）

// 因此这个点为起点的都不行，就都置0（因为你要还从这个点走，那就重蹈覆辙了），所以说，要循环的话，从这条路上哪个点开始走都可以成环


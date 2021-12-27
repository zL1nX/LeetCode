/*
给你一个 下标从 0 开始 的整数数组 nums ，返回满足下述条件的 不同 四元组 (a, b, c, d) 的 数目 ：

nums[a] + nums[b] + nums[c] == nums[d] ，且
a < b < c < d
 

示例 1：

输入：nums = [1,2,3,6]
输出：1
解释：满足要求的唯一一个四元组是 (0, 1, 2, 3) 因为 1 + 2 + 3 == 6 。
示例 2：

输入：nums = [3,3,6,4,5]
输出：0
解释：[3,3,6,4,5] 中不存在满足要求的四元组。
示例 3：

输入：nums = [1,1,1,3,5]
输出：4
解释：满足要求的 4 个四元组如下：
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
 

提示：

4 <= nums.length <= 50
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-special-quadruplets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

int countQuadruplets(vector<int>& nums) 
{
    unordered_map<int, int> rec;
    int cnt = 0, n = nums.size();
    for(int b = n - 3; b >= 1; b--) // b逆序来遍历
    {
        for(int d = b + 2; d < n; d++) // d从b的后面开始遍历
        {
            rec[nums[d] - nums[b + 1]]++; // 因为每从后往前遍历一个b，c的可能就多一个，最开始的时候是b+1就是c
            // 那么b每往前走一个，实际上c就是每次多的这个b+1
            // 妙啊，可以减少很多代码上的工作与debug
        }
        for(int a = 0; a < b; a++) // 与此同时 枚举a，这个就是正常的从前往后枚举
        {
            int s = nums[a] + nums[b];
            if(rec.count(s))
            {
                cnt += rec[s];
            }
        }
    }
    return cnt;
}

// 首先，这不就是类似于two sum的吗，只不过变成了four sum，所以说，优化的思路还是不变的，即用哈希表去预存储

// 无非是移到另外一端然后用哈希表搜索，这样能减少for循环的层数

// 本来我想的枚举cd的差的组合，但没想到题解可以通过枚举b，来达到顺便枚举c的效果

// 而实现这一点就是用的逆序遍历（有点巧）


// 这一点确实有点牛，别的都是正常的实现方法

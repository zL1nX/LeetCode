/*
给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。

子数组 是数组的一段连续部分。

 

示例 1：

输入：nums = [1,0,1,0,1], goal = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
示例 2：

输入：nums = [0,0,0,0,0], goal = 0
输出：15
 

提示：

1 <= nums.length <= 3 * 104
nums[i] 不是 0 就是 1
0 <= goal <= nums.length
通过次数10,106提交次数21,810

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-subarrays-with-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) 
{
    int n = nums.size(), prefix = 0;
    int count = 0;
    unordered_map<int, int> rec;
    rec[0] = 1; // 注意初值的设置
    for(int i = 0; i < n; i++)
    {
        prefix += nums[i];
        if(rec.count(prefix - goal))
        {
            count += rec[prefix - goal];
            // 一旦存在这样的差值，因为这个差值必然小于sums[j]，所以可以保证是一定前面的一部分前缀和
            // 那么这样的结果必然是一段连续子数组的
        }
        rec[prefix]++;
    }
    return count;
}

// 一个致命的信息：子数组指的是连续子数组，因此必然会用到前缀和或者滑动窗口这种

// 另外一个致命的信息：数组的元素只有1或0，不存在负数；后面的前缀和必然大于等于前面的前缀和

// sums[j] - sums[i] = goal ==> sums[j] - sums[goal] = sums[i]

// 此时又成致命two sum局了

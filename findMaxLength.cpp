/*
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

 

示例 1:

输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
示例 2:

输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 

提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1
通过次数13,449提交次数28,151

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;


int findMaxLength(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> prefix(n);
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0)
        {
            nums[i] = -1;
        }
    }
    int maxLength = 0, sum = 0;
    unordered_map<int, int> record;
    for(int i = 0; i < n; i ++)
    {
        sum += nums[i];
        if(sum == 0 && i > maxLength)
        {
            maxLength = i + 1; // 记得+1
        }
        else if(record.find(sum) != record.end())
        {
            maxLength = max(maxLength, i - record[sum]);
        }
        else
        {
            record[sum] = i;
        }
    }
    return maxLength;
}

// 核心是把0换成-1（其实这个比较好想到）

// 然后就是模板化的代码，用哈希表容易实现；之后就是看是否有直接为0的，以及前缀和是否出现过
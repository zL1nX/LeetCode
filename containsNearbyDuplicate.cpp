/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false
 

 

提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
通过次数151,549提交次数343,743


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    unordered_map<int, bool> rec;
    for(int i = 0; i < nums.size(); i++)
    {
        if(i > k)
        {
            rec.erase(nums[i - k]);
        }
        if(rec.count(nums[i]))
        {
            return true;
        }
        rec[nums[i]] = true;
    }
    return false;
}

// 哈希表 + 滑动窗口，妙啊

// 不过写的时候要多注意下端点的取值问题
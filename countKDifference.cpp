/*
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
 

示例 1：

输入：nums = [1,2,2,1], k = 1
输出：4
解释：差的绝对值为 1 的数对为：
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
示例 2：

输入：nums = [1,3], k = 3
输出：0
解释：没有任何数对差的绝对值为 3 。
示例 3：

输入：nums = [3,2,1,5,4], k = 2
输出：3
解释：差的绝对值为 2 的数对为：
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99
通过次数10,583提交次数12,304

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-pairs-with-absolute-difference-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <unordered_map>

using namespace std;

int countKDifference(vector<int>& nums, int k) 
{
    int res = 0;
    unordered_map<int, int> rec;
    for(int i = 0;i < nums.size();i++)
    {
        if(rec.find(nums[i] + k) != rec.end())
        {
            res += rec[nums[i] + k];
        }
        if(rec.find(nums[i] - k) != rec.end())
        {
            res += rec[nums[i] - k];
        }
        rec[nums[i]]++;
    }
    return res;
}

// 这题用哈希表有一个非常微妙的地方在于

// 原题中要求，i必须先于j，而这一点在哈希表中寻找时，找到的项必然是先前遍历过的，已经加进来的项

// 因此，本题用哈希表获得的结果必然是在当前元素之前的，可以和其相差k的元素

// 正常的思维模式是，根据当前元素，找到后面符合标准的数组元素；但使用哈希表时，相当于反过来思考，但都是等价的

// 这道题和two sum其实是很像的
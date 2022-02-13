/*
给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。

请你返回 nums 中唯一元素的 和 。

 

示例 1：

输入：nums = [1,2,3,2]
输出：4
解释：唯一元素为 [1,3] ，和为 4 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：0
解释：没有唯一元素，和为 0 。
示例 3 ：

输入：nums = [1,2,3,4,5]
输出：15
解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
通过次数16,985提交次数22,171

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-unique-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

int sumOfUnique(vector<int>& nums) 
{
    int sum = 0;
    unordered_map<int, int> rec;
    for(int n : nums)
    {
        rec[n]++;
        if(rec[n] == 1)
        {
            sum += n;
        }
        else if(rec[n] == 2)
        {
            sum -= n;
        }
    }
    return sum;
}

// 最直接的用哈希表的做法，记录每次出现的次数，然后如果是第一次就累加

// 如果是第二次那就减去这个值，如果超过了两次那就忽略
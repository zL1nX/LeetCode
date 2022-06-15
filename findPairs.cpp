/*
给定一个整数数组和一个整数 k，你需要在数组里找到 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。

这里将 k-diff 数对定义为一个整数对 (nums[i], nums[j])，并满足下述全部条件：

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
注意，|val| 表示 val 的绝对值。

 

示例 1：

输入：nums = [3, 1, 4, 1, 5], k = 2
输出：2
解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个1，但我们只应返回不同的数对的数量。
示例 2：

输入：nums = [1, 2, 3, 4, 5], k = 1
输出：4
解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
示例 3：

输入：nums = [1, 3, 1, 5, 4], k = 0
输出：1
解释：数组中只有一个 0-diff 数对，(1, 1)。
 

提示：

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/k-diff-pairs-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_set>

using namespace std;

int findPairs(vector<int>& nums, int k) 
{
    unordered_set<int> visited;
    unordered_set<int> rec;
    for(int i = 0; i < nums.size(); i++)
    {
        if(visited.count(nums[i] - k))
        {
            rec.emplace(nums[i] - k); // 只加那个较小的左端点
        }
        if(visited.count(nums[i] + k))
        {
            rec.emplace(nums[i]); // 同理
        }
        visited.emplace(nums[i]);
    }
    return rec.size();
}


// 题目很像两数之和, 大的技术肯定是要用哈希表来做, 但是哈希表的问题就在于如何去重

// 重复是指两个层面的重: 重复的数对, 重复的数组元素

// 这里的方法是使用set, 然后每次只往set内加入一个数对中的较小的左端点, 例如(1,4)和(4,7), 我们遍历到4的话, 只会加进去1 (表示1,4)和加进去4(表示4,7)

// 这样就不会有重复计数的问题了, 当然因为有set, 所以也不会有重复元素计数的问题
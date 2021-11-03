/*
给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 difference 。

子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。

 

示例 1：

输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。
示例 2：

输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。
示例 3：

输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。
 

提示：

1 <= arr.length <= 105
-104 <= arr[i], difference <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) 
{
    unordered_map<int, int> dp;
    int res = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        dp[arr[i]] = dp[arr[i] - difference] + 1;
        res = max(res, dp[arr[i]]);
    }
    return res;
}

// 这个dp的定义非常关键，dp的索引是数组的值，索引的值是最大等差子序列的长度

// 那么这样一来，dp在转移时，就只用 dp[i] = dp[i - difference] + 1; 这就非常简洁而且好写了

// 本来打算用一个很长的vector去写，但直接用哈希表更好，而且不用处理索引相对顺序的问题，而且默认值还是0

// 这样即使dp到了一个数组中不存在的数，也是从0开始，即从一个新的序列开始，对整个迭代过程没有任何影响

// 最后看一圈dp值之间的最大值即可

// 这题很精巧，值得多练
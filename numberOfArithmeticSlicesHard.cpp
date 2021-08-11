/*
给你一个整数数组 nums ，返回 nums 中所有 等差子序列 的数目。

如果一个序列中 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该序列为等差序列。

例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和 [3, -1, -5, -9] 都是等差序列。
再例如，[1, 1, 2, 5, 7] 不是等差序列。
数组中的子序列是从数组中删除一些元素（也可能不删除）得到的一个序列。

例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
题目数据保证答案是一个 32-bit 整数。

 

示例 1：

输入：nums = [2,4,6,8,10]
输出：7
解释：所有的等差子序列为：
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
示例 2：

输入：nums = [7,7,7,7,7]
输出：16
解释：数组中的任意子序列都是等差子序列。
 

提示：

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
通过次数5,688提交次数12,969

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
using namespace std;


int numberOfArithmeticSlices(vector<int>& nums) 
{
    int n = nums.size(), res = 0;
    vector<unordered_map<long long, int>> dp(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            long long d = 1LL * nums[i] - nums[j]; // 注意这里类型转换的写法
            auto it = dp[j].find(d);
            int cnt = it == dp[j].end() ? 0 : it->second;
            res += cnt;
            dp[i][d] += cnt + 1;
        }
    }
    return res;
}

// 记住最关键的点是，尾项和公差可以确定一个等差序列

// dp[i][d]表示尾项在i时，公差为d的等差序列的数目

// https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/

// 有点像前面一题的豪华plus版，这个dp的定义和怎么递推属实难想
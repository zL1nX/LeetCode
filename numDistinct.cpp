/*
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2：

输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
 

提示：

0 <= s.length, t.length <= 1000
s 和 t 由英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t) 
{
    int m = s.length(), n = t.length();
    if(m < n) // 首先要保证s的长度不能低于t
    {
        return 0;
    }
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    // dp[i][j]中存储的是t[j:]在s[i:]的子序列中出现的个数
    for(int i = 0; i < m + 1; i++)
    {
        dp[i][n] = 1; // 当考虑边界条件，即j = n时，t[j:]为空序列，即任意的s[i:]都包含空序列，故为1
    }
    for(int i = 0; i < n; i++) // 注意这里是小于n 而非n + 1，因为空序列也能匹配空序列
    {
        dp[m][i] = 0; // i = m时，同理，s[i:]为空序列，因此必不会包含任意t
    }
    // 开始从边界动态规划
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(s[i] == t[j]) // 若当前字符相等，则可以选择匹配或不匹配，因此有两种组成
            {
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = dp[i + 1][j]; // 不相等时，那么就直接从s的下一个字符匹配（因为是t要去匹配s的子序列，所以是考察s的下一个字符）
            }
        }
    }
    return dp[0][0]; // 最后返回的就是，两个完整字符串的比较结果，因为从0开始

}

// 一道非常经典的动态规划题
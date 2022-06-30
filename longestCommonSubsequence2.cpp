/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

 

示例 1：

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。
示例 2：

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
示例 3：

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
 

提示：

1 <= text1.length, text2.length <= 1000
text1 和 text2 仅由小写英文字符组成。
通过次数247,026提交次数383,343

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-common-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) 
{
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; // 只有在两个相等的时候, lcs才会累加
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 不相等的话, 只是取个当前路径的最大值往下再看看
            }
        }
    }
    return dp[m][n];
}

// 1143-最长公共子序列

// 写起来好像那个编辑距离, 甚至整个思路也挺像的

// dp的定义依然是直接定义成最终的答案, 因此形式上也将是一个二维的数组, 最后结果就是dp[m][n]

// 转移的话, 如果两个字符相等, 那说明这个字符肯定在lcs里 (反正不连续, 那肯定是越多越好), 因此往下走的时候lcs长度会加1

// 如果不相等, 说明至少有一个字符不在lcs中, 那么就先走到下一个再说, lcs的长度肯定先不动


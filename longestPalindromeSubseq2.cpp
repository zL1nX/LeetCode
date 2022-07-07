/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

 

示例 1：

输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。
示例 2：

输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
 

提示：

1 <= s.length <= 1000
s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>

using namespace std;


int longestPalindromeSubseq(string s) 
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1; //
    }
    for(int i = n - 1; i >= 0; i --)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2; // 都相等了, 那必然算是最长回文子序列的一部分
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 不相等的话, 就先从上一步转移过来, 再看下一步怎么弄, 本质和编辑距离与子序列是一样的
            }
        }
    }
    return dp[0][n - 1];
}

// 这道题里dp的定义是关键点, dp[i][j]表示s[i..j]的最长回文子序列, 因此很容易能看出

// dp的转移方向是和回文子序列的扩展方向是一致的, 即从单单一个字符开始, 不断地向外扩展

// 另外还需要注意的就是, 遍历的方向, 因为dp需要i+1和j-1来弄, 所以i是反着来遍历的
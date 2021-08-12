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
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) 
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = n - 1; i >= 0; i --)// 从后往前遍历，这样可以实现从短序列到长序列的考察，很经典的写法
    {
        dp[i][i] = 1; // 长度为1的子序列必为回文子序列
        for(int j = i + 1; j < n; j++) // 注意j是i后面的每个点都会遍历到，因此不会漏掉结果
        {
            if(s[i] == s[j]) // 端点相等
            {
                dp[i][j] = dp[i + 1][j - 1] + 2; //加上端点的长度
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 端点不等的话，注意是要考察看两边端点中最长的那个
            }
        }
    }
    return dp[0][n - 1];
}

// 非常标准的一道dp和回文子序列的题，关键在于定义出dp的含义

// dp[i][j] 表示ij之间的最长回文子序列长度，而且使用dp的好处之一在于，我不care什么连续不连续的问题

// 因为只要满足子序列两端点去掉后还是回文子序列这个性质就够了，因此只需要遍历每对端点，也就是n2级别的复杂度

// 然后注意下转移方程该怎么写即可

// 非常经典的一道题，感觉面试会考
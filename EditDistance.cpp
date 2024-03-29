/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) 
{
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i ++)
    {
        dp[i][0] = i;
    }
    for(int j = 1; j <= m; j ++)
    {
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
            }
        }
    }
    return dp[n][m];
}

// 72. 编辑距离

// dp[i][j] 就是对于s1[0..i]和s2[0..j]只需要dp[i][j]步就能将两个变成一样的字符串

// 因此, 如果知道了子串的编辑距离, 那么扩展到当前串, 就是一个取最值的事情
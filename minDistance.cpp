/*
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 

提示：

给定单词的长度不超过500。
给定单词中的字符只含有小写字母。
通过次数33,495提交次数55,827

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-operation-for-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2) 
{
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i = 1; i <= m; i++)
    {
        char x = word1[i - 1];
        for(int j = 1; j <= n; j++)
        {
            char y = word2[j - 1];
            if(x == y)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcs = dp[m][n];
    return m - lcs + n - lcs;
    
}
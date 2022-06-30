/*
给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。

 

示例 1:

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
示例 2:

输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
 

提示:

0 <= s1.length, s2.length <= 1000
s1 和 s2 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>

using namespace std;

int minimumDeleteSum(string s1, string s2) 
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int sum = 0;
    for(int j = 1; j <= n; j ++)
    {
        dp[0][j] = dp[0][j - 1] + s2[j - 1]; //  base case有所不同, 因为相当于把另外一个字符串全删了
    }
    for(int i = 1; i <= m; i++)
    {   
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1]; // 因为没删所以不用变
            }
            else
            {
                dp[i][j - 1] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                // 删了哪个就把哪个的ascii加上
            }
        }
    }
    return dp[m][n];
}

// 712-两个字符串的最小ASCII删除和

// 看起来就是LCS的变种, 就是稍微的换一下dp的定义, 这里dp换成最终的ascii即可, 因为dp的过程实际就是在模拟

// 哪些字符被删去了, 哪些还没被删

// 因此在转移过程中就可以直接把ascii的值算上

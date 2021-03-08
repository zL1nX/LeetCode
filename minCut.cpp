/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

 

示例 1：

输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
示例 2：

输入：s = "a"
输出：0
示例 3：

输入：s = "ab"
输出：1
 

提示：

1 <= s.length <= 2000
s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;

int minCut(string s) 
{
    int n = s.length();
    vector<vector<int>> g(n, vector<int>(n, true));
    for(int i = n - 1; i >= 0; i--) // 注意这种遍历方式，方向是相反的
    {
        for(int j = i + 1; j < n; j++)
        {
            g[i][j] = (s[i] == s[j]) && (g[i + 1][j - 1]); // 当且仅当内部是回文串，以及最外面的两个字符是相同的
        }
    }

    vector<int> f(n, INT_MAX); // f[i] 表示字符串的前缀 s[0..i] 的最少分割次数
    for(int i = 0;i  < n; i++)
    {
        if(g[0][i])
        {
            f[i] = 0; // 如果整个串都是回文串的话，就无须分隔，分隔次数为0
        }
        else
        {
            for(int j = 0; j < i; j++)
            {
                if(g[j + 1][i]) // 考虑分隔后的最后一个串，如果这个串是回文串
                {
                    f[i] = min(f[i], f[j] + 1); // 就相当于前面的这个fj + 1，dp的结果即可作为整个位置i前面这个串的最少值
                }
            }
        }
    }
    return f[n - 1];
}
/*
有台奇怪的打印机有以下两个特殊要求：

打印机每次只能打印由 同一个字符 组成的序列。
每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。

 
示例 1：

输入：s = "aaabbb"
输出：2
解释：首先打印 "aaa" 然后打印 "bbb"。
示例 2：

输入：s = "aba"
输出：2
解释：首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
 

提示：

1 <= s.length <= 100
s 由小写英文字母组成
通过次数6,216提交次数11,420

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strange-printer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;

int strangePrinter(string s) 
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); //dp[i][j] 表示打印s[i,j]的最小操作次数
    
    // 因为这个dp肯定要从短字符串开始，扩散到全体字符串，因此遍历的顺序需要考虑到
    // 从最后的字符开始，逐步往前扩大，可以满足本题要求
    // 要是从最开始的地方遍历，那么你j该怎么选取呢？这样写就会非常奇怪
    for(int i = n - 1; i >= 0; i --)
    {
        dp[i][i] = 1; // 边界条件
        for(int j = i + 1; j < n ; j++)
        {
            if(s[i] == s[j]) // 如aba，就可以从ab转移到aba
            {
                dp[i][j] = dp[i][j - 1]; // 因此可以由上一次操作构造而来
            }
            else // abab 就可以分解成 aba+b a + bab 等
            {
                for(int k = i; k < j; k ++) //因此要对子区间的操作次数进行遍历，找到最小值
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    return dp[0][n - 1];
}

// https://leetcode-cn.com/problems/strange-printer/solution/xin-shou-pian-cong-xiao-wen-ti-zai-dao-q-qifh/

// dp的神奇定义 以及 状态转移的定义 以及 遍历顺序
/*
给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
每个元音 'a' 后面都只能跟着 'e'
每个元音 'e' 后面只能跟着 'a' 或者是 'i'
每个元音 'i' 后面 不能 再跟着另一个 'i'
每个元音 'o' 后面只能跟着 'i' 或者是 'u'
每个元音 'u' 后面只能跟着 'a'
由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

 

示例 1：

输入：n = 1
输出：5
解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
示例 2：

输入：n = 2
输出：10
解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
示例 3：

输入：n = 5
输出：68
 

提示：

1 <= n <= 2 * 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-vowels-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <numeric>

using namespace std;

int countVowelPermutation(int n) 
{
    vector<long long> curr(5, 1), next(5);
    const long long mod = 1e9 + 7;
    for(int i = 1; i < n; i++)
    {
        next[0] = (curr[1] + curr[2] + curr[4]) % mod;
        next[1] = (curr[0] + curr[2]) % mod;
        next[2] = (curr[1] + curr[3]) % mod;
        next[3] = (curr[2]) % mod;
        next[4] = (curr[2] + curr[3]) % mod;
        curr = next;
    }
    return accumulate(curr.begin(), curr.end(), 0LL) % mod;
}

// 从题目意义上来讲，肯定是要用dp来做的，dp[i][j]表示在第i个字符处以第j个元音结尾的可能字符串数量

// 因此，这道题要用dp解决的第一个问题就是，先搞清每个元音字母是从谁转移过来的

// 这一点刚好是和题目给出的条件相反，因此需要逆着先推一下，例如元音a前面只有可能是从e、i、u转移过来的

// 只有这样，才能实现一个从前往后的递推

// 之后，后面的内容就是一个非常简单的动态规划了；不过因为当前状态只和上一个状态有关，所以不用生成那么长的序列

// 只需要保存两个状态即可。
/*
请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。

由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。

 

示例 1：

输入：n = 5
输出：12
解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
示例 2：

输入：n = 100
输出：682289015
 

提示：

1 <= n <= 100
通过次数13,104提交次数24,564

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/prime-arrangements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int numPrimeArrangements(int n) 
{
    int primeCnt = 0; // 质数的个数 == 质数索引的个数, 所以一定是满的, 只要不满那就不是一个合法排列
    for(int i = 1; i <= n; i ++)
    {
        primeCnt += isPrime(i);
    }
    return (int)(factorial(primeCnt) * factorial(n - primeCnt) % MOD);
}

int isPrime(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    for(int i = 2; i * i <= n; i ++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

long long factorial(int n)
{
    long long res = 1; // 注意溢出的问题
    for(int i = 2; i <=n; i ++)
    {
        res *= i;
        res %= MOD;
    }
    return res;
}

// 1175. 质数排列


// 因为题目限定了数的范围, 所以在1到n的范围里, 必然质数索引的个数等于质数个数

// 所以题目就是, 质数的个数形成的排列, 乘以 合数个数形成的排列
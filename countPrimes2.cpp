/*
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。

 

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
 

提示：

0 <= n <= 5 * 106
*/

#include <vector>

using namespace std;

int countPrimes(int n) 
{
    vector<bool> isPrime(n, true);
    int res = 0;
    for(int i = 2; i * i < n; i++)
    {
        if(isPrime[i])
        {
            for(int k = i * i; k < n; k += i) // 不从2 * i, 而是从 i * i 开始, 是因为小于i的都已经被筛过了, 即 i * c (c < i), 所以直接从 i * i 开始
            {
                isPrime[k] = false;
            }
        }
    }

    for(int i = 2; i < n; i++)
    {
        if(isPrime[i])
        {
            res++;
        }
    }
    return res;
}
/*
超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。

给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。

题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。

 

示例 1：

输入：n = 12, primes = [2,7,13,19]
输出：32 
解释：给定长度为 4 的质数数组 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
示例 2：

输入：n = 1, primes = [2,3,5]
输出：1
解释：1 不含质因数，因此它的所有质因数都在质数数组 primes = [2,3,5] 中。
 
提示：

1 <= n <= 106
1 <= primes.length <= 100
2 <= primes[i] <= 1000
题目数据 保证 primes[i] 是一个质数
primes 中的所有值都 互不相同 ，且按 递增顺序 排列


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) 
{
    int k = primes.size();
    vector<int> ugly(n + 1);
    vector<int> primeTurns(k, 1); // all 1 from the beginning
    ugly[1] = 1; // start 
    int minn = INT_MAX;
    for(int i = 2; i <= n; i++) 
    {
        vector<int> nums(k); // 记录乘积结果
        for(int j = 0; j < k; j++)
        {
            nums[j] = primes[j] * ugly[primeTurns[j]]; // n指针不断相乘，如果turn还是1的话，仍然是素数乘1的结果
            minn = min(minn, nums[j]); // 选出本轮乘完之后的最小值
        }
        ugly[i] = minn; // 乘完之后的最小值即为当前i对应的丑数（最小值）
        for(int j = 0;  j < k; j++)
        {
            if(minn == nums[j])
            {
                primeTurns[j]++; // 找到是谁，然后将对应质数的「贡献值」增加一
            }
        }
    }
    return ugly[n];
}

// 与第n个丑数相比，这一题相当于用原来三指针的思路扩展成n指针

// 写的时候类似于动态规划，初始时每个素数对应的乘数都为1，每次乘完一轮要看下最小值是谁，然后这个位置就是它了

// 然后对应最小值的素数在下一轮中的乘数要+1

// 实现方法非常好
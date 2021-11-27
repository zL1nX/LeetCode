/*
最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
Paste（粘贴）：粘贴 上一次 复制的字符。
给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。

 

示例 1：

输入：3
输出：3
解释：
最初, 只有一个字符 'A'。
第 1 步, 使用 Copy All 操作。
第 2 步, 使用 Paste 操作来获得 'AA'。
第 3 步, 使用 Paste 操作来获得 'AAA'。
示例 2：

输入：n = 1
输出：0
 

提示：

1 <= n <= 1000
通过次数28,933提交次数53,247

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

int minSteps(int n) 
{
    vector<int> f(n + 1);
    for(int i = 2; i <= n; i++)
    {
        f[i] = INT_MAX;
        for(int j = 1; j * j <= n; j++)
        {
            if(i % j == 0)
            {
                f[i] = min(f[i], f[j] + i / j);
                f[i] = min(f[i], f[i / j] + j);
            } 
        }
    }
    return f[n];
}

// 你要得到n个A，而且每次复制都是复制全部，那么n如果是质数的话，只可能一个个来

// n是合数的话，就是它的因子们j转移而来，j要变成i个A，需要一次复制操作，i/j - 1次粘贴操作（因为原来就有j个A）

// 因此一共就是转移 i / j 

// 而且写代码时注意到因子的对称性，即i / j 和 j本身都是i的一对因子，所以写的时候都要考虑到，不重不漏

// 所以也只用遍历 根号i个就够了
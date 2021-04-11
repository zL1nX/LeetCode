/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。

 

示例 1：

输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：

输入：n = 1
输出：1
解释：1 通常被视为丑数。
 

提示：

1 <= n <= 1690

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
using namespace std;

int nthUglyNumber(int n) 
{
    int p2 = 1, p3 = 1, p5 = 1;
    vector<int> ugly(n + 1, 1);
    for(int i = 2; i <= n; i++)
    {
        int next_ugly2 = ugly[p2] * 2, next_ugly3 = ugly[p3] * 3, next_ugly5 = ugly[p5] * 5;
        ugly[i] = min(next_ugly2, min(next_ugly3, next_ugly5));
        if(ugly[i] == next_ugly2)
        {
            p2++;
        }
        if(ugly[i] == next_ugly3)
        {
            p3++;
        }
        if(ugly[i] == next_ugly5)
        {
            p5++;
        }
    }
    return ugly[n];
}

// dp的思想，即dp[i] = min(*2, *3, *5)

// pi主要指的是资格 https://leetcode-cn.com/problems/ugly-number-ii/solution/san-zhi-zhen-fang-fa-de-li-jie-fang-shi-by-zzxn/


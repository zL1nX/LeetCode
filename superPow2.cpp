/*
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

 

示例 1：

输入：a = 2, b = [3]
输出：8
示例 2：

输入：a = 2, b = [1,0]
输出：1024
示例 3：

输入：a = 1, b = [4,3,3,8,5,2]
输出：1
示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198
 

提示：

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b 不含前导 0
*/

#include <vector>
using namespace std;

int base = 1337;

int mypow(int a, int k)
{
    a %= base;
    int res = 1;
    for(int c = 0; c < k; c++)
    {
        res *= a;
        res %= base;
    }
    return res;
}

int superPow(int a, vector<int>& b) 
{
    if (b.empty()) return 1; // 递归结束的条件, 不要忘了
    int k1 = b.back();
    b.pop_back();

    int r1 = mypow(a, k1);
    int r2 = mypow(superPow(a, b), 10); // 递归发生的地方

    return (r1 * r2) % base;
    
}
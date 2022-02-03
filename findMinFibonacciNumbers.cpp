/*
给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。

 

示例 1：

输入：k = 7
输出：2 
解释：斐波那契数字为：1，1，2，3，5，8，13，……
对于 k = 7 ，我们可以得到 2 + 5 = 7 。
示例 2：

输入：k = 10
输出：2 
解释：对于 k = 10 ，我们可以得到 2 + 8 = 10 。
示例 3：

输入：k = 19
输出：3 
解释：对于 k = 19 ，我们可以得到 1 + 5 + 13 = 19 。
 

提示：

1 <= k <= 10^9
通过次数9,649提交次数15,269

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;


int findMinFibonacciNumbers(int k) 
{
    vector<int> fibo = {1, 1};
    while(fibo.back() < k)
    {
        int loc = fibo.size() - 1;
        fibo.push_back(fibo[loc] + fibo[loc - 1]);
    }
    int res = 0, left = k;
    while(left > 0)
    {
        int loc = fibo.size() - 1;
        while(fibo[loc] > left) // 贪心的地方
        {
            loc--;
        }
        res += 1;
        left -= fibo[loc];
    }
    return res;
}

// 斐波那契数列 + 贪心（重点在于贪心的证明），但其实这题用贪心就是正确的，只不过不太会证
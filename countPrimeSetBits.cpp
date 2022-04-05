/*
给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。

计算置位位数 就是二进制表示中 1 的个数。

例如， 21 的二进制表示 10101 有 3 个计算置位。
 

示例 1：

输入：left = 6, right = 10
输出：4
解释：
6 -> 110 (2 个计算置位，2 是质数)
7 -> 111 (3 个计算置位，3 是质数)
9 -> 1001 (2 个计算置位，2 是质数)
10-> 1010 (2 个计算置位，2 是质数)
共计 4 个计算置位为质数的数字。
示例 2：

输入：left = 10, right = 15
输出：5
解释：
10 -> 1010 (2 个计算置位, 2 是质数)
11 -> 1011 (3 个计算置位, 3 是质数)
12 -> 1100 (2 个计算置位, 2 是质数)
13 -> 1101 (3 个计算置位, 3 是质数)
14 -> 1110 (3 个计算置位, 3 是质数)
15 -> 1111 (4 个计算置位, 4 不是质数)
共计 5 个计算置位为质数的数字。
 

提示：

1 <= left <= right <= 106
0 <= right - left <= 104
通过次数23,803提交次数32,927

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <unordered_map>
#include <vector>

using namespace std;

int countPrimeSetBits(int left, int right) 
{
    int res = 0;
    unordered_map<int, int> primes = {{2, 1}, {3, 1}, {5, 1}, {7, 1}, {11, 1}, {13, 1}, {17, 1}, {19, 1}};
    for(int num = left; num <= right; num++)
    {
        int cnt = 0, n = num;
        while(n)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        if(primes.find(cnt) != primes.end())
        {
            res += 1;
        }
    }
    return res;
}

// 本质都是模拟, 不过有一些数学优化方法, 比如把质数表示为1从而实现位运算判断是否为质数

// 其他的都差不多, C++无非再用下__builtin_popcount这种内置的api

// 剩下的基本都是一样的

/*
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/solution/er-jin-zhi-biao-shi-zhong-zhi-shu-ge-ji-jy35g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
给定一个正整数 n ，你可以做如下操作：

如果 n 是偶数，则用 n / 2替换 n 。
如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
n 变为 1 所需的最小替换次数是多少？

 

示例 1：

输入：n = 8
输出：3
解释：8 -> 4 -> 2 -> 1
示例 2：

输入：n = 7
输出：4
解释：7 -> 8 -> 4 -> 2 -> 1
或 7 -> 6 -> 3 -> 2 -> 1
示例 3：

输入：n = 4
输出：2
 

提示：

1 <= n <= 231 - 1
通过次数21,547提交次数54,362

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> rec;

int integerReplacement(int n) 
{
    if(n == 1) return 0;
    if(rec.count(n))
    {
        return rec[n];
    }
    if(n % 2 == 0) 
    {
        rec[n] = 1 + integerReplacement(n / 2);
        return rec[n];
    }
    rec[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    return rec[n];
}

// 这个方法是加了记忆化后的方法，即每个哈希表的值都是一个函数值的递归

// 去掉哈希表之后就是直接暴力递归DFS，但这个DFS暴力其实是贪心的暴力，即每次都去找最小的

// 对于偶数只有一种操作，对于奇数因为加减后会变成偶数，偶数又只有一种操作，因此不妨合一起看成两步操作，然后变成偶数时去选一种最小的

// 这个贪心法能证明最后结果一定是最小的吗